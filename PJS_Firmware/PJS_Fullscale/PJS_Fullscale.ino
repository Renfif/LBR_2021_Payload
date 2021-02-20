
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

File dataFile = SD.open("datalog.txt", FILE_WRITE)

void loop() {

  //getting altitude and velocity
  float altitude = bmp.readAltitude(SEALEVELPRESSURE_HPA);
  delay(10); 
  float altitudeNew = bmp.readAltitude(SEALEVELPRESSURE_HPA);

  dy = altitudeNew - altitude
  dt = 0.01 

  velocity = dy/dt //what units does this come out as?

  //get stuff from receiver. Only getting CH2 - CH6 input during installation and setup
  Ch1 = receive(receiver1) //safety switch
  Ch2 = receive(receiver2) //Automatic Arming Switch - if on, will deploy if altimeter and other conditions are met
  Ch3 = receive(receiver3) //Manual deployment - if on, will instantly undergo deployment procedure
  Ch4 = receive(receiver4) //lock and unlock
  Ch5 = receive(receiver5) //door open and door close
  Ch6 = receive(receiver6) //uas deploy uas insert

  //if arming switch is on, execute the following
  
  
  
  if(Ch1 > 200) { 

    loopCheck = 1;
    
    if(Ch2 > 200)&&(altitude > 550)&&(altitude < 650)&&(velocity < 30){ 
      deployment(Time, switch1_Link, switch2_Link, switch3_DoorLock, switch4_UAS)
    }
    
    if(Ch3 > 200) { 
      deployment(Time, switch1_Link, switch2_Link, switch3_DoorLock, switch4_UAS)
    } 

    if(Ch4 > 200) { 
      String dataString = "Unlocking door...  ";
      dataLogging(dataFile, dataString, altitude, velocity, Time);
      unlockDoor()
      String dataString = "Door unlocked.     ";
      dataLogging(dataFile, dataString, altitude, velocity, Time);
      
    }

    else if (Ch4 < 200) {
      String dataString = "Locking door...    "; 
      dataLogging(dataFile, dataString, altitude, velocity, Time);
      lockDoor()
      String dataString = "Door locked.       "; 
      dataLogging(dataFile, dataString, altitude, velocity, Time);

    }

    if(Ch5 > 200) { 
      String dataString = "Opening Door...    "; 
      dataLogging(dataFile, dataString, altitude, velocity, Time);
      openDoor()
      String dataString = "Door opened.       "; 
      dataLogging(dataFile, dataString, altitude, velocity, Time);

    }

    else if (Ch5 < 200) { 
      String dataString = "Closing door...    ";
      dataLogging(dataFile, dataString, altitude, velocity, Time);
      closeDoor()
      String dataString = "Door closed.       ";
      dataLogging(dataFile, dataString, altitude, velocity, Time);
    }

    if(Ch6 > 200) { 
      String dataString = "Deploying UAS...   ";
      dataLogging(dataFile, dataString, altitude, velocity, Time);
      deployUAS() 
      String dataString = "UAS deployed.      ";
      dataLogging(dataFile, dataString, altitude, velocity, Time);
    }

    else if(Ch6 < 200) { 
      String dataString = "Installing UAS...  ";
      dataLogging(dataFile, dataString, altitude, velocity, Time);
      installUAS()
      String dataString = "UAS installed.     ";
      dataLogging(dataFile, dataString, altitude, velocity, Time);
    }
    
  }

  else if(loopCheck == 1) { 
    dataFile.close();
  }
 
}


  
