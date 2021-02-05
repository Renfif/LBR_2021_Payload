#include <Wire.h> 
#include <Adafruit_Sensor.h>
#include "Adafruit_BMP3XX.h"


//Switch pins
#define Switch1_Link      // (x1) when clicked the linkage folded, when unclicked the linkage is extended
#define Switch2_Link      // (x1) when clicked the linkage is unfolded, when unclicked the linkage is not extended
#define Switch3_DoorLock  // (x2) when the limit switch is clicked that means door is unlocked (though cannot do a check for locking)
#define Switch4_UAS       // (x1) when unclicked PJS is deployed, when clicked PJS is inserted

//Driver pins
#define UAS_DriverIN1 0 
#define UAS_DriverIN2 1
#define Link_DriverIN1 2
#define Link_DriverIN2 3
#define LockA_DriverIN1 4
#define LockA_DriverIN2 5
#define LockB_DriverIN1 6
#define LockB_DriverIN2 7
#define Relay_Signal 12

//RF Receiver pins
#define RF_CH1 8
#define RF_CH2 9
#define RF_CH3 10
#define RF_CH4 11
#define RF_CH5 13
#define RF_CH6 14

//Altimeter (I2C)
#define SEALEVELPRESSURE_HPA (1013.25) //adjustment for pressure
#define Alt_SDI 18
#define Alt_SCK 19
Adafruit_BMP3XX bmp; //I2C


//SD Card pins 
#define SD_DAT0 35 
#define SD_DAT1 34
#define SD_DAT2 39
#define SD_DAT3 38
#define SD_CMD 37 
#define SD_CLK 36



void setup() { 

  Serial.begin(115200); 

  bmp.setTemperatureOversampling(BMP3_OVERSAMPLING_8X);
  bmp.setPressureOversampling(BMP3_OVERSAMPLING_4X);
  bmp.setIIRFilterCoeff(BMP3_IIR_FILTER_COEFF_3);
  bmp.setOutputDataRate(BMP3_ODR_50_HZ);

  pinMode(UAS_DriverIN1, OUTPUT);
  pinMode(UAS_DriverIN2, OUTPUT);
  pinMode(Link_DriverIN1, OUTPUT);
  pinMode(Link_DriverIN2, OUTPUT);
  pinMode(LockA_DriverIN1, OUTPUT);
  pinMode(LockA_DriverIN2, OUTPUT);
  pinMode(LockB_DriverIN1, OUTPUT);
  pinMode(LockB_DriverIN2, OUTPUT);
}

void loop() {

  //getting altitude and velocity
  altitude = bmp.readAltitude(SEALEVELPRESSURE_HPA);
  delay(10); 
  altitudeNew = bmp.readAltitude(SEALEVELPRESSURE_HPA);

  dy = altitudeNew - altitude
  dt = 0.01 

  velocity = dy/dt 

  //get stuff from receiver. Only getting CH2 - CH6 input during installation and setup
  Ch1 = receive(receiver1) //safety switch
  Ch2 = receive(receiver2) //Automatic Arming Switch - if on, will deploy if altimeter and other conditions are met
  Ch3 = receive(receiver3) //Manual deployment - if on, will instantly undergo deployment procedure
  Ch4 = receive(receiver4) //lock and unlock
  Ch5 = receive(receiver5) //door open and door close
  Ch6 = receive(receiver6) //uas deploy uas insert

  //if arming switch is on, execute the following

  if(Ch1 > 200) { 
    
    if(Ch2 > 200)&&(altitude > 550)&&(altitude < 650)&&(velocity < 30)&& { 
      deployment(Time, switch1_Link, switch2_Link, switch3_DoorLock, switch4_UAS)
    }
    
    if(Ch3 > 200) { 
      deployment(Time, switch1_Link, switch2_Link, switch3_DoorLock, switch4_UAS)
    } 

    if(Ch4 > 200) { 
      unlockDoor()
    }

    else if (Ch4 < 200) {
      lockDoor()
    }

    if(Ch5 > 200) { 
      openDoor()
    }

    else if (Ch5 < 200) { 
      closeDoor()
    }

    if(Ch6 > 200) { 
      deployUAS() 
    }

    else if(Ch6 < 200) { 
      installUAS()
    }
    
  }
  
}


int receive(receiverX) { 
  
  int Ch=pulseIn(receiverX,HIGH,25000);
  
  Ch=pulseToPWM(Ch);

  return Ch;

}


int pulseToPWM(int pulse){
  if (pulse>1000){
    pulse = map(pulse, 1000, 2000, -500, 500);
    pulse = constrain(pulse, -255, 255);  
  }else{
    pulse=0;  
  }
  if(abs(pulse)<= deadzone){
    pulse=0;
  }
  return pulse;
}


void deployment(Time, switch1_Link, switch2_Link, switch3_DoorLock, switch4_UAS) { 

  //if Switch3s are clicked (door unlocked), open door
  while(!Switch3_DoorLock == HIGH) { 
    unlockDoor(); 
  }
  

  
  if(Switch3_DoorLock == HIGH) { 
    openDoor(); //need to do an until check to stop the motor?
  }

  //if Switch1_Link is unclicked and Switch2_Link is clicked (door open), deploy UAS
  if(Switch1_Link == LOW)&&(Switch2_Link == HIGH){ 
    deployUAS();
  }

  //if Switch4_UAS is low (UAS deployed), close door
  if(switch4_UAS == LOW) {
    closeDoor();
  }

  //if Switch1_Link is clicked and Switch2_LInk is unclocked (door closed), lock door
  if(Switch1_Link == HIGH)&&(Switch2_Link == LOW) { 
    lockDoor()
    }
 
}


//if we do ramping, wont it ramp up and down

void unlockDoor() {
  for(int i = 255; i < 255; i++) { 
    analogWrite(LockA_DriverIN1, i); 
    analogWrite(LockA_DriverIN2, 0);
    delay(5); 
  }
  while(1) { 
    analogWrite(LockA_DriverIN1, 255); 
    analogWrite(LockA_DriverIN2, 0);
  }
}


void lockDoor() { 
  for(int i = 255; i < 255; i++) { 
    analogWrite(LockA_DriverIN2, i); 
    analogWrite(LockA_DriverIN1, 0);
    delay(10); 
  }
}


void openDoor() { 
  for(int i = 255; i < 255; i++) { 
    analogWrite(LinkDriverIN1, i); 
    analogWrite(LinkDriverIN2, 0); 
    delay(10); 
  }
}


void closeDoor() { //ramp down 
  for(int i = 255; i < 255; i++) { 
    analogWrite(LinkDriverIN2, i); 
    analogWrite(LinkDriverIN1, 0); 
    delay(10); 
  }
}


void deployUAS() { 
  for(int i = 255; i < 255; i++) { 
    analogWrite(UAS_DriverIN1, i); 
    analogWrite(UAS_DriverIN2, 0); 
    delay(10); 
  }
}


void installUAS() { 
  for(int i = 255; i < 255; i++) { 
    analogWrite(UAS_DriverIN2, i); 
    analogWrite(UAS_DriverIN1, 0); 
    delay(10); 
  }
}
//should we do this nested fuction? 
int motor(int INA, int INB) { 
  for(int i = 255; i < 255; i) { 
    analogWrite(INA, i); 
    analogWrite(INB, 0); 
    delay(10); 
  }
}
