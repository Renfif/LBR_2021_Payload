#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include "Adafruit_BMP3XX.h"

#define BMP_SCK 13
#define BMP_MISO 12
#define BMP_MOSI 11
#define BMP_CS 10

#define SEALEVELPRESSURE_HPA (1010.9)

#define MotorPin1A 0
#define MotorPin1B 1
#define LimitSwitchA 23
#define ReceiverIn1 8

int ramprate = 1;
int flag = 0;
//int deadzone = 20;
int deadzone = 50;
float landheight = 15.0;
Adafruit_BMP3XX bmp;


void setup() {
  
  Serial.begin(115200);
  if (!bmp.begin_I2C()) {   // hardware I2C mode, can pass in address & alt Wire
    Serial.println("Could not find a valid BMP3 sensor, check wiring!");
    while (1);
  }
  // Set up oversampling and filter initialization
  bmp.setTemperatureOversampling(BMP3_OVERSAMPLING_8X);
  bmp.setPressureOversampling(BMP3_OVERSAMPLING_4X);
  bmp.setIIRFilterCoeff(BMP3_IIR_FILTER_COEFF_3);
  bmp.setOutputDataRate(BMP3_ODR_50_HZ);

  pinMode(MotorPin1A, OUTPUT);
  pinMode(MotorPin1B, OUTPUT);
  pinMode(LimitSwitchA, INPUT_PULLUP);
  pinMode(ReceiverIn1, INPUT);

  digitalWrite(MotorPin1A,LOW);
  digitalWrite(MotorPin1B, LOW);
  
}

void loop() {
  int Ch1= pulseIn(ReceiverIn1, HIGH, 25000);
  Ch1 = pulseToPWM(Ch1);
  Serial.print("Altitude: ");
  Serial.println(bmp.readAltitude(SEALEVELPRESSURE_HPA));
  Serial.print("Rec Channel 1: ");
  Serial.println(Ch1);
  Serial.print("Limit Switch Is: ");
    if(digitalRead(LimitSwitchA) == LOW){
      Serial.println("on");
    }else{
      Serial.println("off");
    }
  
  if (Ch1>0){
    if(digitalRead(LimitSwitchA == LOW) && (bmp.readAltitude(SEALEVELPRESSURE_HPA))<15){    
      Serial.println("Going Forward...");
      rampMotor(1, MotorPin1A);
    }
    else{
      Serial.println("Not Prepared");
    }
  }
  else if(Ch1<0){
    if(digitalRead(LimitSwitchA == LOW) && (bmp.readAltitude(SEALEVELPRESSURE_HPA))<15){    
      Serial.println("Going Backward...");
      rampMotor(1, MotorPin1B);
    }
    else{
      Serial.println("Not Prepared");
    }
  }
  else{
    Serial.println("Not Armed");
  }

//  if(digitalRead(LimitSwitchA) == HIGH){
//    Serial.println("Click");
//    delay(20);
//  }
//  else{
//    Serial.println("Clack");
//    delay(20);
//  }
//  for(int i=0; i<256; i=i+ramprate){
//    analogWrite(MotorPin1A, i);  
//    Serial.println(i);
//    delay(10);
//    if(i==255){
//      Serial.println("Full Forward");
//      delay(500);
//    }
//  }
//  digitalWrite(MotorPin1A,LOW);
//  digitalWrite(MotorPin1B, LOW);
//  for(int i=0; i<256; i=i+ramprate){
//    analogWrite(MotorPin1B, i);
//    Serial.println(i);  
//    delay(10);
//    if(i==255){
//      Serial.println("Full Backward");
//      delay(500);
//    }
//  }
//  digitalWrite(MotorPin1A,LOW);
//  digitalWrite(MotorPin1B, LOW);
  
//  if (! bmp.performReading()) {
//    Serial.println("Failed to perform reading :(");
//    return;
//  }

//  Serial.print("Approx. Altitude = ");
//  Serial.print(bmp.readAltitude(SEALEVELPRESSURE_HPA));
//  Serial.println(" m");

  delay(1000);
}

void rampMotor(int r, int p){
  digitalWrite(MotorPin1A,LOW);
  digitalWrite(MotorPin1B, LOW);
  for(int i=0; i<256; i=i+r){
    analogWrite(p, i);  
    Serial.println(i);
    delay(10);
    if(i==255){
      delay(500);
    }
  }
  for(int i=255; i>-1; i=i-r){
    analogWrite(p, i);  
    Serial.println(i);
    delay(10);
    if(i==0){
      delay(500);
    }
  }
  digitalWrite(MotorPin1A,LOW);
  digitalWrite(MotorPin1B, LOW);

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
