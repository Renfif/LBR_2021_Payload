float velocity(altitude) {
  dt = 0.000050
  delay(dt); //uncomment if we make the adjustment in the main program
  float altitudeNew = bmp.readAltitude(SEALEVELPRESSURE_HPA)
  dy = altitudeNew - altitude
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

void deployment(Time, State_Switch1_Link, State_Switch2_Link, State_Switch4_UAS) { 

  unlockDoor(unlockTime); 
  delay(1000);
  
  openDoor();
  delay(1000)
  
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

void unlockDoor(unlockTime) {
  
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
  

void lockDoor(lockTime) { 
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
    if(digitalRead(Switch1_Link) == LOW && digitalRead(Switch2_Link) == HIGH || Ch5 > 200) { 
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
