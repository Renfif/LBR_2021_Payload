float velocity(altitude) {
  delay(0.000050); //uncomment if we make the adjustment in the main program
  float altitudeNew = bmp.readAltitude(SEALEVELPRESSURE_HPA)
  dy = altitudeNew - altitude
  dt = 0.000050
  velocity = dy/dt 
  return velocity;
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
  }
  else{
    pulse=0;  
  }
  if(abs(pulse)<= deadzone){
    pulse=0;
  }
  return pulse;
}

//delete this later deployment(Time, State_Switch1_Link, State_Switch2_Link, State_Switch3_DoorLock, State_Switch4_UAS)
void deployment(Time, State_Switch1_Link, State_Switch2_Link, State_Switch3_DoorLock, State_Switch4_UAS) { 

  //if Switch3s are not clicked (door is not unlocked), unlock door
  if(State_Switch3_DoorLock == LOW) { 
    unlockDoor(); 
  }

  //if Switch3s are clicked (door unlocked), open door
  if(State_Switch3_DoorLock == HIGH) { 
    openDoor();
  }


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
    lockDoor(lockTime)
    }
 
}

void unlockDoor() {
  
  for(int i = 0; i < 255; i++){ 
    State_Switch3_DoorLock = digitalRead(Switch3_DoorLock)
    if(State_Switch3_DoorLock == LOW || Ch4 > 200) {  
      analogWrite(LockA_DriverIN1, i); 
      analogWrite(LockA_DriverIN2, 0);
      analogWrite(LockB_DriverIN1, 0); 
      analogWrite(LockB_DriverIN2, i);
      delay(10); 
    }
  }
  
  while(State_Switch3_DoorLock == LOW || Ch4 > 200) { 
    analogWrite(LockA_DriverIN1, 255); 
    analogWrite(LockA_DriverIN2, 0);
    analogWrite(LockB_DriverIN1, 0); 
    analogWrite(LockB_DriverIN2, 255);
    State_Switch3_DoorLock = digitalRead(Switch3_DoorLock)
  }
  
  analogWrite(LockA_DriverIN1, 0);
  analogWrite(LockA_DriverIN2, 0);
  analogWrite(LockB_DriverIN1, 0); 
  analogWrite(LockB_DriverIN2, 0);
}
  
  

void lockDoor(lockTime) { 
  for(int i = 0; i < 255; i++) {  
      analogWrite(LockA_DriverIN1, 0); 
      analogWrite(LockA_DriverIN2, i);
      analogWrite(LockB_DriverIN1, i); 
      analogWrite(LockB_DriverIN2, 0);
      delay(3.9); 
  }
  
  for(int i = 0; i < (lockTime - 1); i++) { //drives motors for lockTime seconds
      analogWrite(LockA_DriverIN1, 0); 
      analogWrite(LockA_DriverIN2, 255);
      analogWrite(LockB_DriverIN1, 255); 
      analogWrite(LockB_DriverIN2, 0);
      delay(1000); 
    }
  }
  analogWrite(LockA_DriverIN1, 0);
  analogWrite(LockA_DriverIN2, 0);
  analogWrite(LockB_DriverIN1, 0); 
  analogWrite(LockB_DriverIN2, 0);
}

void openDoor() { //switches will have different states at some points so || (or) is used?????
  for(int i = 0; i < 255; i++) { 
    if(digitalRead(Switch1_Link) == HIGH || digitalRead(Switch2_Link) == LOW || Ch5 > 200){ 
      analogWrite(Link_DriverIN1, i); 
      analogWrite(Link_DriverIN2, 0);
      delay(10); 
    }
  }
  
  while(digitalRead(Switch1_Link) == HIGH || digitalRead(Switch2_Link)|| Ch5 > 200) == LOW) { 
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
    if(digitalRead(Switch1_Link) == LOW) && digitalRead(Switch2_Link) == HIGH || Ch5 > 200) { //should use and or or?
      analogWrite(Link_DriverIN1, 0); 
      analogWrite(Link_DriverIN2, i);
      delay(10); 
    }
  }

  
  while(digitalRead(Switch1_Link) == LOW && digitalRead(Switch2_Link) == HIGH || Ch5 > 200) { 
    analogWrite(Link_DriverIN1, 0); 
    analogWrite(Link_DriverIN2, 255);
  }
  analogWrite(Link_DriverIN1, 0); 
  analogWrite(Link_DriverIN2, 0);
}


void installUAS() { 
  for(int i = 255; i < 255; i++) { 
    analogWrite(UAS_DriverIN2, i); 
    analogWrite(UAS_DriverIN1, 0); 
    delay(10); 
  }
}
