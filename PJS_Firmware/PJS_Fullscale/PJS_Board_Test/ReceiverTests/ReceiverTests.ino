#define Rec 8
int deadzone = 50;

void setup() {
  Serial.begin(115200);
  pinMode(Rec, INPUT);
  
}

void loop() {
  int Ch1 = pulseIn(Rec, HIGH, 25000);
  Ch1 = pulseToPWM(Ch1);
  Serial.println(Ch1);
}

int pulseToPWM(int pulse){
  if (pulse>900){
    pulse = map(pulse, 900, 2000, -500, 500);
    pulse = constrain(pulse, -255,255);  
  }else{
    pulse=0;  
  }
  if(abs(pulse)<= deadzone){
    pulse=0;
  }
  return pulse;
}
