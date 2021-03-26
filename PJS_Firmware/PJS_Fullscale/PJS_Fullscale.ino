#include "PJS_FullscaleFunctions.h"
#include <Wire.h> 
#include "Adafruit_Sensor.h"
#include "Adafruit_BMP3XX.h"


//Switch pins
#define Switch1_Link 21      // (x1) when clicked the linkage folded, when unclicked the linkage is extended
#define Switch2_Link 20      // (x1) when clicked the linkage is unfolded, when unclicked the linkage is not extended
#define Switch3_DoorLock 22  // (x2) when the limit switch is clicked that means door is unlocked (though cannot do a check for locking)
#define Switch4_UAS 23       // (x1) when unclicked PJS is deployed, when clicked PJS is inserted

//Driver pins
#define UAS_DriverIN1 0 
#define UAS_DriverIN2 1
#define Link_DriverIN1 2
#define Link_DriverIN2 3
#define LockA_DriverIN1 4
#define LockA_DriverIN2 5
#define LockB_DriverIN1 6
#define LockB_DriverIN2 7


//RF Receiver pins
#define RF_CH1 8
#define RF_CH2 9
#define RF_CH3 10
#define RF_CH4 11
#define RF_CH5 13
#define RF_CH6 14


//Altimeter (I2C)
#define SEALEVELPRESSURE_HPA (1010.9) //adjustment for pressure
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

int unlockTime = 5;
int lockTime = 4;
int altitudeMin = 550;
int altitudeMax = 650;
int loopCheck = 0; 
int Time = 0; 
int deadzone = 20; 

int Ch1 = 0; 
int Ch2 = 0; 
int Ch3 = 0; 
int Ch4 = 0; 
int Ch5 = 0; 
int Ch6 = 0; 

int receive(int receiverX);

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
  int State_Switch1_Link = digitalRead(Switch1_Link); 
  int State_Switch2_Link = digitalRead(Switch2_Link); 
  int State_Switch4_UAS = digitalRead(Switch4_UAS);
  
  //getting altitude and velocity   
  
  float altitude = bmp.readAltitude(SEALEVELPRESSURE_HPA);

  //if you cannot call the bmp.readaltitude function in the header, file, make these adjustments
  //delay(0.000050);
  //float altitudeNew = bmp.readAltitude(SEALEVELPRESSURE_HPA);
  //float velocity = velocity(altitude, altitudeNew);
  
  float velocityValue = velocity(altitude);
  
  //get stuff from receiver. Only getting CH2 - CH6 input during installation and setup
  int Ch1 = receive(RF_CH1); //safety switch
  int Ch2 = receive(RF_CH2); //Automatic Arming Switch - if on, will deploy if altimeter and other conditions are met
  int Ch3 = receive(RF_CH3); //Manual deployment - if on, will instantly undergo deployment procedure
  int Ch4 = receive(RF_CH4); //lock and unlock
  int Ch5 = receive(RF_CH5); //door open and door close
  int Ch6 = receive(RF_CH6); //uas deploy uas insert
  //if arming switch is on, execute the following
  
  if(Ch1 > 200) { 
 
    if((Ch2 > 200)&&(altitude > altitudeMin)&&(altitude < altitudeMax)&&(velocityValue < 30)){ 
      deployment(Time, State_Switch1_Link, State_Switch2_Link, State_Switch4_UAS);
      Serial.println("Automated Altitude Based Deployment Engaged");
    }
    
    else if(Ch3 > 200) { 
      deployment(Time, State_Switch1_Link, State_Switch2_Link, State_Switch4_UAS);
      Serial.println("Automated Deployment Override Initiated");
    } 

    //start of individualized manual 
    if(Ch4 > 200) { 
      analogWrite(LockA_DriverIN1, 255); 
      analogWrite(LockA_DriverIN2, 0);
      analogWrite(LockB_DriverIN1, 0); 
      analogWrite(LockB_DriverIN2, 255);
      Serial.println("Unlock door"); 
    }

    else if (Ch4 < -200) {
      analogWrite(LockA_DriverIN1, 0); 
      analogWrite(LockA_DriverIN2, 255);
      analogWrite(LockB_DriverIN1, 255); 
      analogWrite(LockB_DriverIN2, 0);
      Serial.println("Lock door"); 
    }

    else if (Ch4 > -100 && Ch4 < 200){
      analogWrite(LockA_DriverIN1, 0); 
      analogWrite(LockA_DriverIN2, 0);
      analogWrite(LockB_DriverIN1, 0); 
      analogWrite(LockB_DriverIN2, 0);
      Serial.println("Door Locks stopped");
    }

    if(Ch5 > 200) { 
      analogWrite(Link_DriverIN1, 255); 
      analogWrite(Link_DriverIN2, 0);
      Serial.println("Open door"); 
    }

    else if (Ch5 < -200) { 
      analogWrite(Link_DriverIN1, 0); 
      analogWrite(Link_DriverIN2, 255);
      Serial.println("Close door"); 
    }

    else if (Ch5 > -100 && Ch5 < 200){
      analogWrite(Link_DriverIN1, 0); 
      analogWrite(Link_DriverIN2, 0);
      Serial.println("Door stopped"); 
    }

    if(Ch6 > 200) { 
      analogWrite(UAS_DriverIN2, 0); 
      analogWrite(UAS_DriverIN1, 255); 
      Serial.println("Deploy UAS"); 
    }

    else if(Ch6 < -200) { 
      analogWrite(UAS_DriverIN2, 135); 
      analogWrite(UAS_DriverIN1, 0); 
      Serial.println("Install UAS"); 
    }

    else if(Ch6 > -100 && Ch6 < 200) { 
      analogWrite(UAS_DriverIN2, 0); 
      analogWrite(UAS_DriverIN1, 0); 
      Serial.println("UAS Installation stopped"); 
    }
    
  }
  else{
    setAllZero();
  }
  
}

float velocity(float altitude) {
  float dt = 0.000050;
  delay(dt); //uncomment if we make the adjustment in the main program
  float altitudeNew = bmp.readAltitude(SEALEVELPRESSURE_HPA);
  float dy = altitudeNew - altitude;
  float velocity = dy/dt;
  return velocity;
}
  
int receive(int receiverX) { 
  int Ch=pulseIn(receiverX,HIGH,25000);
  Ch=pulseToPWM(Ch);
  return Ch;
}

int pulseToPWM(int pulse){
  if (pulse>950){
    pulse = map(pulse, 950, 2050, -500, 500);
    pulse = constrain(pulse, -255, 255);  
  }
  else{
    pulse=0;  
  }
  if(abs(pulse)<= deadzone){
    pulse=0;
  }
  return pulse;
}

int deployment(int Time, int State_Switch1_Link, int State_Switch2_Link, int State_Switch4_UAS) { 

  unlockDoor(unlockTime); 
  delay(1000);
  
  openDoor();
  delay(1000);
  
  //if Switch1_Link is unclicked and Switch2_Link is clicked (door open), deploy UAS
  if(State_Switch1_Link == LOW && State_Switch2_Link == HIGH){ 
    deployUAS();
  }

  //if Switch4_UAS is low (UAS deployed), close door
  if(State_Switch4_UAS == LOW) {
    closeDoor();
  }


  //if Switch1_Link is clicked and Switch2_LInk is unclicked (door closed), lock door
  if(State_Switch1_Link == HIGH && State_Switch2_Link == LOW) { 
    lockDoor(lockTime);
    }
}

int unlockDoor(int unlockTime) {
  
  for(int i = 0; i < 255; i++){  
    analogWrite(LockA_DriverIN1, i); 
    analogWrite(LockA_DriverIN2, 0);
    analogWrite(LockB_DriverIN1, 0); 
    analogWrite(LockB_DriverIN2, i);
    delay(3.92); 
    }
  
  for(int i = 0; i < (unlockTime - 1); i++) { 
    analogWrite(LockA_DriverIN1, 255); 
    analogWrite(LockA_DriverIN2, 0);
    analogWrite(LockB_DriverIN1, 0); 
    analogWrite(LockB_DriverIN2, 255);
    delay(1000);
  }
  analogWrite(LockA_DriverIN1, 0);
  analogWrite(LockA_DriverIN2, 0);
  analogWrite(LockB_DriverIN1, 0); 
  analogWrite(LockB_DriverIN2, 0);
}
  

int lockDoor(int lockTime) { 
  for(int i = 0; i < 255; i++) {  
      analogWrite(LockA_DriverIN1, 0); 
      analogWrite(LockA_DriverIN2, i);
      analogWrite(LockB_DriverIN1, i); 
      analogWrite(LockB_DriverIN2, 0);
      delay(3.92); 
  }
  
  for(int i = 0; i < (lockTime - 1); i++) { //drives motors for lockTime seconds
      analogWrite(LockA_DriverIN1, 0); 
      analogWrite(LockA_DriverIN2, 255);
      analogWrite(LockB_DriverIN1, 255); 
      analogWrite(LockB_DriverIN2, 0);
      delay(1000); 
    }
  analogWrite(LockA_DriverIN1, 0);
  analogWrite(LockA_DriverIN2, 0);
  analogWrite(LockB_DriverIN1, 0); 
  analogWrite(LockB_DriverIN2, 0);
}


//Expected a primary expression before == token 
void openDoor() { //switches will have different states at some points so || (or) is used?????
  for(int i = 0; i < 255; i++) { 
    if(digitalRead(Switch1_Link) == HIGH || digitalRead(Switch2_Link) == LOW || Ch5 > 200){ 
      analogWrite(Link_DriverIN1, i); 
      analogWrite(Link_DriverIN2, 0);
      delay(10); 
    }
  }
  
  while(digitalRead(Switch1_Link) == HIGH || digitalRead(Switch2_Link) == LOW || Ch5 > 200) { 
    analogWrite(Link_DriverIN1, 255); 
    analogWrite(Link_DriverIN2, 0);
  }
  analogWrite(Link_DriverIN1, 0); 
  analogWrite(Link_DriverIN2, 0);
}



void closeDoor() { 
  for(int i = 0; i < 255; i++) { 
    if(digitalRead(Switch4_UAS) == LOW || Ch5 < 200) {
      analogWrite(Link_DriverIN1, 0); 
      analogWrite(Link_DriverIN2, i);
      delay(10); 
    }
  }
  
  while(digitalRead(Switch1_Link) == LOW || digitalRead(Switch2_Link) == HIGH || Ch5 < 200) { 
    analogWrite(Link_DriverIN1, 0); 
    analogWrite(Link_DriverIN2, 255);
  }
  analogWrite(Link_DriverIN1, 0); 
  analogWrite(Link_DriverIN2, 0);
}



void deployUAS() { 
  for(int i = 0; i < 255; i++) { 
    if(digitalRead(Switch1_Link) == LOW && digitalRead(Switch2_Link) == HIGH || Ch5 > 200) { 
    analogWrite(UAS_DriverIN2, i); 
    analogWrite(UAS_DriverIN1, 0); 
      delay(10); 
    }
  }

  while(digitalRead(Switch1_Link) == LOW && digitalRead(Switch2_Link) == HIGH || Ch5 > 200) { 
    analogWrite(UAS_DriverIN2, 0); 
    analogWrite(UAS_DriverIN1, 255); 
  }
    analogWrite(UAS_DriverIN2, 0); 
    analogWrite(UAS_DriverIN1, 0); 
}


void installUAS() { 
  for(int i = 135; i < 135; i++) { 
    analogWrite(UAS_DriverIN2, i); 
    analogWrite(UAS_DriverIN1, 0); 
    delay(10); 
  }
}

void setAllZero(){
  analogWrite(UAS_DriverIN1, 0);
  analogWrite(UAS_DriverIN2, 0);
  analogWrite(Link_DriverIN1, 0);
  analogWrite(Link_DriverIN2, 0);
  analogWrite(LockA_DriverIN1, 0);
  analogWrite(LockA_DriverIN2, 0);
  analogWrite(LockB_DriverIN1, 0);
  analogWrite(LockB_DriverIN2, 0);
}


  
