
#include <PJS_FullscaleFunctions.h>
#include <Wire.h> 
#include <Adafruit_Sensor.h>
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



void setup() { 

  Serial.begin(115200); 

  bmp.setTemperatureOversampling(BMP3_OVERSAMPLING_8X);
  bmp.setPressureOversampling(BMP3_OVERSAMPLING_4X);
  bmp.setIIRFilterCoeff(BMP3_IIR_FILTER_COEFF_3);
  bmp.setOutputDataRate(BMP3_ODR_50_HZ);

  int loopCheck = 0; 

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
  int State_Switch2_Link = digitalRead(Switch2_Link0); 
  int State_Switch3_DoorLock = digitalRead(Switch3_DoorLock); 
  int State_Switch4_UAS = digitalRead(Switch4_UAS);
  
  //getting altitude and velocity
  
  float altitude = bmp.readAltitude(SEALEVELPRESSURE_HPA);

  //if you cannot call the bmp.readaltitude function in the header, file, make these adjustments
  //delay(0.000050);
  //float altitudeNew = bmp.readAltitude(SEALEVELPRESSURE_HPA);
  //float velocity = velocity(altitude, altitudeNew);
  
  float velocity = velocity(altitude, altitude);
  
  //get stuff from receiver. Only getting CH2 - CH6 input during installation and setup
  Ch1 = receive(receiver1) //safety switch
  Ch2 = receive(receiver2) //Automatic Arming Switch - if on, will deploy if altimeter and other conditions are met
  Ch3 = receive(receiver3) //Manual deployment - if on, will instantly undergo deployment procedure
  Ch4 = receive(receiver4) //lock and unlock
  Ch5 = receive(receiver5) //door open and door close
  Ch6 = receive(receiver6) //uas deploy uas insert

  //if arming switch is on, execute the following
  
  if(Ch1 > 200) { 

    if(Ch2 > 200)&&(altitude > 550)&&(altitude < 650)&&(velocity < 30){ 
      deployment(Time, State_Switch1_Link, State_Switch2_Link, State_Switch3_DoorLock, State_Switch4_UAS)
    }
    
    if(Ch3 > 200) { 
      deployment(Time, State_Switch1_Link, State_Switch2_Link, State_Switch3_DoorLock, State_Switch4_UAS)
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


  
