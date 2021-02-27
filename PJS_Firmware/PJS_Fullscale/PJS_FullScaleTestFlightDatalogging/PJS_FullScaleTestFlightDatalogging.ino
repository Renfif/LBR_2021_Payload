#include <Wire.h>
#include <Adafruit_Sensor.h>
#include "Adafruit_BMP3XX.h"
#include <TimeLib.h>
#include <SdFat.h>
#include <SdFatConfig.h>
#include <sdios.h>
#include "ExFatlib\ExFatLib.h"

//Altimeter (I2C)
//http://www.usairnet.com/weather/maps/current/california/barometric-pressure/
#define SEALEVELPRESSURE_HPA (1021.6735) //adjustment for pressure
#define Alt_SDI 18
#define Alt_SCK 19
Adafruit_BMP3XX bmp; //I2C

#define SD_CONFIG SdioConfig(DMA_SDIO)
SdExFat sd;
ExFile logfile;

#define LOG_INTERVAL 50 // millis between entries (reduce to take more/faster data)
// how many Milliseconds before writing the logged data permanently to disk
// set it to the LOG_INTERVAL to write each time (safest)
// set it to 10*LOG_INTERVAL to write all data every 10 datareads, you could lose up to
// the last 10 reads if power is lost but it uses less power and is much faster!
#define SYNC_INTERVAL 100 // millis between calls to flush() - to write data to the card
uint32_t syncTime = 0; // time of last sync()
#define ECHO_TO_SERIAL 1 // echo data to serial port 1 = Turned on
//here is the "go" button
#define WAIT_TO_START 1 // Wait for serial input in setup() 1 = autostart

//mostly stolen from https://forum.pjrc.com/threads/59984-Hi-Performance-Teensy-4-0-Datalogger-with-condition-based-logging
void error(char *str)
{
  Serial.print("SD error: ");
  Serial.println(str);
  while (10); //Stops if you cannot read the SD
}

void setup() {
  setSyncProvider(getTeensy3Time);
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
  delay(200);
  if (timeStatus() != timeSet) {
    Serial.println("Unable to sync with the RTC");
  } else {
    Serial.println("RTC has set the system time");
  }
  // initialize the SD card
  Serial.print("Initializing SD card...");

  // see if the card is present and can be initialized:
  if (!sd.begin(SD_CONFIG)) {
    Serial.println("Card failed, or not present");
  }
  else Serial.println("Card initialized.");


  // create a new file
  char filename[] = "LOGGER00.CSV";
  for (uint8_t i = 0; i < 100; i++) {
    filename[6] = i / 10 + '0';
    filename[7] = i % 10 + '0';
    if (! sd.exists(filename)) {
      // only open a new file if it doesn't exist
      logfile = sd.open(filename, FILE_WRITE);
      break; // leave the loop!
    }
  }

  if (! logfile) {
    Serial.println("couldnt create file");
  }

  Serial.print("Logging to: ");
  Serial.println(filename);
  
  Serial.println("Altimeter found, initializing...");
  //set up oversampling and filters
  bmp.setTemperatureOversampling(BMP3_OVERSAMPLING_8X);
  bmp.setPressureOversampling(BMP3_OVERSAMPLING_4X);
  bmp.setIIRFilterCoeff(BMP3_IIR_FILTER_COEFF_3);
  bmp.setOutputDataRate(BMP3_ODR_50_HZ);
  Serial.println("Altimeter Initialized");
}

//File dataFile = SD.open("datalog.txt", FILE_WRITE);

void loop() {
  
  if (Serial.available()) {
    time_t t = processSyncMessage();
    if (t != 0) {
      Teensy3Clock.set(t); // set the RTC
      setTime(t);
    }
  }

  String Year = year();
  String Mon = month();
  String Day = day();
  String Hour = hour();
  String Min = minute();
  String Sec = second();
  //concatenate hour:minute string
  delay(1);
  delay((LOG_INTERVAL - 1) - (micros() % LOG_INTERVAL));
  
  int altitude = bmp.readAltitude(SEALEVELPRESSURE_HPA);
  String data = "  Altitude:  " + altitude;
  delay(3);

  int h = Hour.toInt();
  int m = Min.toInt();
  int s = Sec.toInt();
  String ymd = (Year + "," + Mon + "," + Day + " ");
  
  logfile.print(ymd);
  logfile.printf("%02d", h);
  logfile.print(",");
  logfile.printf("%02d", m);
  logfile.print(",");
  logfile.printf("%02d", s);
  logfile.print(data);
  logfile.println();
  
#if ECHO_TO_SERIAL
    Serial.print(ymd);
    Serial.printf(" %02d", h);
    Serial.print(":");
    Serial.printf("%02d", m);
    Serial.print(":");
    Serial.printf("%02d", s);
    Serial.print(data);
    Serial.println();
#endif //ECHO_TO_SERIAL
  // Now we write data to disk! Don't sync too often - requires 2048 bytes of I/O to SD card
  // which uses a bunch of power and takes time
  if ((micros() - syncTime) < SYNC_INTERVAL) return;
  syncTime = micros();
  // blink LED to show we are syncing data to the card & updating FAT!
  logfile.flush();//physically save any bytes written to the file to the SD card
}

time_t getTeensy3Time()
{
  return Teensy3Clock.get();
}
/* code to process time sync messages from the serial port */
#define TIME_HEADER "T" // Header tag for serial time sync message

unsigned long processSyncMessage() {
  unsigned long pctime = 0L;
  const unsigned long DEFAULT_TIME = 1614410910; // february 26 2021

  if (Serial.find(TIME_HEADER)) {
    pctime = Serial.parseInt();
    return pctime;
    if ( pctime < DEFAULT_TIME) { // check the value is a valid time (greater than Jan 1 2013)
      pctime = 0L; // return 0 to indicate that the time is not valid
    }
  }
  return pctime;
}

void printDigits(int digits) {
  // utility function for digital clock display: prints preceding colon and leading 0
  Serial.print(": ");
  if (digits < 10)
    Serial.print('0');
  Serial.print(digits);
}
