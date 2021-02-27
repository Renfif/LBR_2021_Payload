#include <Wire.h>
#include <Adafruit_Sensor.h>
#include "Adafruit_BMP3XX.h"
#include <TimeLib.h>
#include <SPI.h> 
#include <SD.h> 

//Altimeter (I2C)
//http://www.usairnet.com/weather/maps/current/california/barometric-pressure/
#define SEALEVELPRESSURE_HPA (1021.6735) //adjustment for pressure
#define Alt_SDI 18
#define Alt_SCK 19
Adafruit_BMP3XX bmp; //I2C




void setup() {
  Serial.begin(115200); 
  while (!Serial) {
      ; // wait for serial port to connect. Needed for native USB port only
    }
  if (!bmp.begin_I2C()) {   // hardware I2C mode, can pass in address & alt Wire
    //if (! bmp.begin_SPI(BMP_CS)) {  // hardware SPI mode  
    //if (! bmp.begin_SPI(BMP_CS, BMP_SCK, BMP_MISO, BMP_MOSI)) {  // software SPI mode
      Serial.println("Could not find a valid BMP3 sensor, check wiring!");
      while (1);
  }
  Serial.println("Altimeter found, initializing...");
  //set up oversampling and filters
  bmp.setTemperatureOversampling(BMP3_OVERSAMPLING_8X);
  bmp.setPressureOversampling(BMP3_OVERSAMPLING_4X);
  bmp.setIIRFilterCoeff(BMP3_IIR_FILTER_COEFF_3);
  bmp.setOutputDataRate(BMP3_ODR_50_HZ);
  Serial.println("Altimeter Initialized");
}

File dataFile = SD.open("datalog.txt", FILE_WRITE);

void loop() {
  // put your main code here, to run repeatedly:

}
