#include <TimeLib.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>

File fd;
const uint8_t BUFFER_SIZE = 20;
char fileName[] = "demoFile.txt"; // SD library only supports up to 8.3 names
char buff[BUFFER_SIZE+2] = "";  // Added two to allow a 2 char peek for EOF state
uint8_t index = 0;

const uint8_t chipSelect = 8;
const uint8_t cardDetect = 9;

enum states: uint8_t { NORMAL, E, EO };
uint8_t state = NORMAL;

bool alreadyBegan = false;  // SD.begin() misbehaves if not first call

#define LimitSwitchA 0
#define LimitSwitchB 1
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

#define SEALEVELPRESSURE_HPA (1013.25)
time_t RTCTime;
Adafruit_BMP3XX bmp;


void setup() {
  Serial.begin(115200);
  while (!Serial && millis() < 4000 );
  Serial.println("\n" __FILE__ " " __DATE__ " " __TIME__);
  setSyncProvider(getTeensy3Time);

  if (!bmp.begin_I2C()) {   // hardware I2C mode, can pass in address & alt Wire
    Serial.println("Could not find a valid BMP3 sensor, check wiring!");
    while (1);
  }

  //Barometer Initialization
  bmp.setTemperatureOversampling(BMP3_OVERSAMPLING_8X);
  bmp.setPressureOversampling(BMP3_OVERSAMPLING_4X);
  bmp.setIIRFilterCoeff(BMP3_IIR_FILTER_COEFF_3);
  bmp.setOutputDataRate(BMP3_ODR_50_HZ);
  
  //SDcard init
  pinMode(cardDetect, INPUT);
  initializeCard();

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
  //check Barom can read pressure
  if (! bmp.performReading()) {
    Serial.println("Failed to perform reading :(");
    return;
  }

  //Receiver Channels
  Ch1=pulseIn(Receiver1,HIGH);
  Ch2=pulseIn(Receiver2,HIGH);
  Ch3=pulseIn(Receiver3,HIGH);
  Ch4=pulseIn(Receiver4,HIGH);  

//  // Make sure the card is still present
//  if (!digitalRead(cardDetect))
//  {
//    initializeCard();
//  }

//  Serial.print("Approx. Altitude = ");
//  Serial.print(bmp.readAltitude(SEALEVELPRESSURE_HPA));
//  Serial.println(" m");

  //CONTROL CODE
  
}
