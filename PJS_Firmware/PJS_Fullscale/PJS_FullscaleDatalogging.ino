
//figure out later
//SD Equivalent
//CS -> CS (PIN2 - DAT3)
//SCLK - > SCLK (PIN5 - CLK)
//MOSI -> SDI (PIN3 - CMD)
//MISO <- SDO (PIN7 - DAT0)

#include <SPI.h> 
#include <SD.h> 

/*
  SD card datalogger

  This example shows how to log data from three analog sensors
  to an SD card using the SD library.

  The circuit:
   analog sensors on analog ins 0, 1, and 2
   SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4 (for MKRZero SD: SDCARD_SS_PIN)

  created  24 Nov 2010
  modified 9 Apr 2012
  by Tom Igoe

  This example code is in the public domain.

*/

#include <SPI.h>
#include <SD.h>

const int chipSelect = BUILTIN_SD;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.print("Initializing SD card...");

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    while (1);
  }
  Serial.println("card initialized.");
} 

//altitude, what we're doing doing, time
// test to see if it is smart enough to convert the integer to a string inside of the function call

void dataLogging(File dataFile, String dataString, int altitude, String velocity, String Time) { 
  
  String dataString = dataString + "  Altitude:  " + altitude + "  Velocity  " + velocity + "  Time:  " Time; 
  
  if (dataFile) {
    dataFile.println(dataString);
    
    // print to the serial port too:
    Serial.println(dataString);
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  }   
}
  
  
