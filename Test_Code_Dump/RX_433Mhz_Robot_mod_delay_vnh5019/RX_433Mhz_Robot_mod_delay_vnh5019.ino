
/* The code was made by Tamás Imets for an Arduino UNO project
   This code controls the BB-8 Droid from the Star Wars: The Force Awakens,
   and works with Bluetooth RC Car application, using a HC-06 seriaé bluetooth module
   See more details at instructables.com/member/Imetomi
   Friday,  December 25, 2015
*/
#include "DualVNH5019MotorShield.h"
#include <Servo.h>
#include <SoftwareSerial.h>
int command = 0;  //incoming serial data
DualVNH5019MotorShield md;

int battery;
int led = 3;
SoftwareSerial bluetooth(A0, A1);
int cmd;

Servo head;
void setup() {
  bluetooth.begin(9600);
  Serial.begin(9600); // set up Serial library at 9600 bps - this is the speed the serial interface will work all
  head.attach(9); //attach servo to pin D9 or to servo2 on motor shield
  // md.setM1Speed(255); //set default speed
  // md.setM2Speed(255); //set default speed
  md.init();
  pinMode(led, OUTPUT); //connect here the blue LED
}


void loop() {
 
  if (bluetooth.available()) {
    cmd = bluetooth.read();
    Serial.write(cmd);
    switch (cmd)
    {
      case 'D':
        md.setM1Speed(0); // stopped
        md.setM2Speed(0); // stopped
        break;

      case 'A':
        md.setM1Speed(255);
        md.setM2Speed(255);
        break;
    
      case 'B':
        md.setM1Speed(100);
        md.setM2Speed(100);
        break;

      case 'C':
        md.setM1Speed(50);
        md.setM2Speed(50);
        break;

      case 'E':
        md.setM1Speed(-70);
        md.setM2Speed(-70);
        break;

      case 'F':
        md.setM1Speed(-255);
        md.setM2Speed(-255);
        break;

      case 'G':
        md.setM1Speed(255);
        md.setM2Speed(-255);
        break;

      case 'H':
        md.setM1Speed(100);
        md.setM2Speed(-100);
        break;

      case 'I':
        md.setM1Speed(50);
        md.setM1Speed(-50);
        break;

      case 'J':
        md.setM1Speed(-50);
        md.setM2Speed(50);
        break;

      case 'K':
        md.setM1Speed(-100);
        md.setM2Speed(100);
        break;

      case 'L':
        md.setM1Speed(-255);
        md.setM2Speed(255);
        break;
        
        
    
      case '0':
        digitalWrite(led, LOW);
        break;
      case '1':
        analogWrite(led, 50);
        break;
      case '2':
        analogWrite(led, 100);
        break;
      case '3':
        analogWrite(led, 150);
        break;
      case '4':
        analogWrite(led, 200);
        break;
      case '5':
        analogWrite(led, 255);
        break;
    }
  }

}

