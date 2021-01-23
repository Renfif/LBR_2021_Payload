//Switch pins
#define Switch1_Link
#define Switch2_Door
#define Switch3_UAS

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

//Receiver pins
#define RF_CH1 8
#define RF_CH2 9
#define RF_CH3 10
#define RF_CH4 11
#define RF_CH5 13
#define RF_CH6 14

//Altimeter pins - Ifeoma add whatever you need 
#define Alt_SDI 18
#define Alt_SCK 19

//SD Card pins 
#define SD_DAT0 35 
#define SD_DAT1 34
#define SD_DAT2 39
#define SD_DAT3 38
#define SD_CMD 37 
#define SD_CLK 36



//getting signal to perform operations manually OR another condition is met 


//all switches are clicked closed 
//1 switch is normally closed and when UAS releases it is LOW
//2 switches check if doors are closed, and are HIGH when closed  
//2 switches for the linkage arm normally open, HIGH when door is oopen

//ch1 is an arming switch 



void loop() {

  //get stuff from receiver. Only getting CH2 - CH6 input during installation and setup
  Ch1 = receive(Receiver1) //Arming Switch
  Ch2 = receive(Receiver2)
  Ch3 = receive(Receiver3) 
  Ch4 = receive(Receiver4)
  Ch5 = receive(Receiver5) 
  Ch6 = receive(Receiver6)

  //if arming switch is on, execute the following
  if(Ch1 > 200) { 
    main(Ch2, Ch3, Ch4)
  }
   
}

int Receive(ReceiverX) { 
  
  int Ch=pulseIn(ReceiverX,HIGH,25000);
  
  Ch=pulseToPWM(Ch);

  return Ch;

}


int pulseToPWM(int pulse){
  if (pulse>1000){
    pulse = map(pulse, 1000, 2000, -500, 500);
    pulse = constrain(pulse, -255,255);  
  }else{
    pulse=0;  
  }
  if(abs(pulse)<= deadzone){
    pulse=0;
  }
  return pulse;
}


void main() { 

  //Time = _______________________ (real time clock function)

  //if channel says, unlock door, also consider considering for relay

  if(Switch2_Door == HIGH) and (altimeter is correct)) or (Ch2 > 0) { 
    UnlockDoor(Ch2, Time) // is start of procedure dictated by human control or altimeter? 
   
    if((Switch2_Door == HIGH) and (altimeter is correct)) or (Ch3 > 0) {
       delay(5000);
       OpenDoor(Time)
       
       }

  }

   
  //if door open, and altimeter is clear, deploy UAS
  
  if((Switch1_Link == HIGH) and (altimeter is correct)) or (Ch4 > 0) { 
    UAS_Deploy(Time)
    } 


  //if UAS is deployed, limit switch and/or timing, close door, also consider considering for relay

  if(Switch3_UAS == LOW) and (altimeter is correct)) or (CH5 > 0) { 
    
    CloseDoor(Time) 
    
    } 


}


void UnlockDoor(Time) { 

  //unlock door 
  //write to datalogging program
 
}


void OpenDoor(Time) { 
  //open door 
  //write to datalogging program

  
  
}

void UAS_Deploy(Time) { 
  //deployUAS
  //write to datalogging program
  analogWrite(UAS_DriverIN1, 255); 
  analogWrite(UAS_DriverIN2, 0);
  
}

void CloseDoor(Time) { 
  //deployUAS 
  //write to datalogging program

}
