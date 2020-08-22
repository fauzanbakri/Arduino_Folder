#include <SD.h>
#include <SPI.h>
File myFile;
void setup() {
  Serial.begin(9600);
  Serial.print("Initializing SD card...");
  if (!SD.begin(15)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
  myFile = SD.open("new.csv", FILE_READ);
  if (myFile) {
    Serial.println("data.csv:");
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    myFile.close();
  } else {
    Serial.println("error opening new.csv");
  }
}

void loop() {


}
