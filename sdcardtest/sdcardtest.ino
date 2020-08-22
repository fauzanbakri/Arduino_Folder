#include "DHT.h"
#include <SPI.h>
#include <SD.h>
 
#define DHTPIN D4
#define DHTTYPE DHT11  
DHT dht(DHTPIN, DHTTYPE);
 
const int chipSelect = D8;
File myFile;
 
void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
 
  Serial.print("Initializing SD card...");
 
  if (!SD.begin(chipSelect)) 
  {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
  dht.begin();
 
}
 
void loop()
{
  delay(2000);
  myFile = SD.open("dht11.csv", FILE_WRITE);
      // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  String h = "skjdksahdkjasdhkjashd";
  String t = "dskajdlkasjd";
  String f = "sndkjaskdsjkd";
  // Check if any reads failed and exit early (to try again).
  // if the file opened okay, write to it:
  if (myFile) 
  {
    Serial.print("opened dht11.csv...");
    myFile.print(h);
    myFile.print(",");
    myFile.print(t);
    myFile.print(",");
    myFile.println(f);
    // close the file:
    myFile.close();
    Serial.println("closed dht11.csv.");
  } 
  else 
  {
    // if the file didn't open, print an error:
    Serial.println("error opening dht11.csv");
  }
}
