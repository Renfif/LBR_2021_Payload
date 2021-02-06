#define Relay 3
#define MassMotorA 4 //these are pwm
#define MassMotorB 5
#define Receiver1 6 //these are pwm
#define Receiver2 7
#define Receiver3 8
#define Receiver4 9
#define DoorMotorPWM 14
#define DoorMotorINA 15
#define DoorMotorINB 20

const int deadzone = 20;
//delays for door and block droppa
const int t1 = 5000;
const int t2 = 6600;

void setup() {

  Serial.begin(115200);
  
  pinMode(Relay, OUTPUT);
  pinMode(DoorMotorPWM, OUTPUT);
  pinMode(DoorMotorINA, OUTPUT);
  pinMode(DoorMotorINB, OUTPUT);
  pinMode(MassMotorA, OUTPUT);
  pinMode(MassMotorB, OUTPUT);
  pinMode(Receiver1, INPUT);
  pinMode(Receiver2, INPUT);
  pinMode(Receiver3, INPUT);
  pinMode(Receiver4, INPUT);

  digitalWrite(Relay, LOW);
  digitalWrite(DoorMotorPWM, LOW);
  digitalWrite(DoorMotorINA, LOW);
  digitalWrite(DoorMotorINB, LOW);
  digitalWrite(MassMotorA, LOW);
  digitalWrite(MassMotorB, LOW);
  
}

void loop() {
  int Ch1=pulseIn(Receiver1,HIGH,25000);
  int Ch2=pulseIn(Receiver2,HIGH,25000);
  int Ch3=pulseIn(Receiver3,HIGH,25000);
  int Ch4=pulseIn(Receiver4,HIGH,25000);

  Ch1=pulseToPWM(Ch1);
  Ch2=pulseToPWM(Ch2);
  Ch3=pulseToPWM(Ch3);
  Ch4=pulseToPWM(Ch4);

  //Serial.println(Ch1);
  //ch1 is two position
  if(Ch1 > 200){
    Deployment();
  }

  if(Ch3>0){
    analogWrite(MassMotorA, 255);
    analogWrite(MassMotorB, 0);
  }
  if(Ch3<0){
    analogWrite(MassMotorB, 255);
    analogWrite(MassMotorA, 0);
  }
  if(Ch3==0){
    analogWrite(MassMotorA, 0);
    analogWrite(MassMotorB, 0);
  }
   //manual mass control
  if(Ch2>0){
    digitalWrite(DoorMotorINA, HIGH);
    digitalWrite(DoorMotorINB, LOW);
    analogWrite(DoorMotorPWM, 255);
  }
  if(Ch2<0){
    digitalWrite(DoorMotorINA, LOW);
    digitalWrite(DoorMotorINB, HIGH);
    analogWrite(DoorMotorPWM, 255);
   }
   if(Ch2==0){
    digitalWrite(DoorMotorINA, LOW);
    digitalWrite(DoorMotorINB, LOW);
    analogWrite(DoorMotorPWM, 0);
   }
    //manual Door control
   if(Ch4>0){
     digitalWrite(Relay, HIGH);
   }
   if(Ch4==0){
     digitalWrite(Relay,LOW);
   }
    //manual relay control
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

void Deployment(){
      digitalWrite(Relay,HIGH);
      analogWrite(DoorMotorPWM, 255);
      digitalWrite(DoorMotorINB,HIGH);
      digitalWrite(DoorMotorINA, LOW);
      delay(t1);
      digitalWrite(DoorMotorINB, LOW);
      analogWrite(MassMotorA, 0);
      analogWrite(MassMotorB, 255);
      delay(t2);
      analogWrite(MassMotorB, 0);
      delay(300);
      digitalWrite(DoorMotorINA, HIGH);
      delay(t1);
      digitalWrite(DoorMotorINA, LOW);
      digitalWrite(Relay, LOW);
      
}
