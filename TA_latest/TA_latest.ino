#include "painlessMesh.h"
#include <Wire.h>
#include <RtcDS3231.h>
#include <SD.h>
#include <SPI.h>
#define   MESH_PREFIX     "whateverYouLike"
#define   MESH_PASSWORD   "somethingSneaky"
#define   MESH_PORT       5555

RtcDS3231<TwoWire> Rtc(Wire);

Scheduler userScheduler; // to control your personal task
painlessMesh  mesh;
File myFile;

void sendMessage() ;

Task taskSendMessage( TASK_SECOND * 1 , TASK_FOREVER, &sendMessage );

void sendMessage() {
  String msg = "";
  myFile = SD.open("data_latest.csv", FILE_READ);
  while (myFile.available()) {
    msg += (char)myFile.read();
  }
  myFile.close();
  mesh.sendBroadcast( msg );
  taskSendMessage.setInterval( random( TASK_SECOND * 1, TASK_SECOND * 1 ));
}

void receivedCallback( uint32_t from, String &msg ) {
  Serial.printf("startHere: Received from %u msg=%s\n", from, msg.c_str());
  myFile = SD.open("receive.csv", FILE_WRITE);
  if (myFile) {
    myFile.print(msg.c_str());
    myFile.close();
  }
}

void newConnectionCallback(uint32_t nodeId) {
  Serial.printf("--> startHere: New Connection, nodeId = %u\n", nodeId);
}

void changedConnectionCallback() {
  Serial.printf("Changed connections\n");
}

void nodeTimeAdjustedCallback(int32_t offset) {
  Serial.printf("Adjusted time %u. Offset = %d\n", mesh.getNodeTime(), offset);
}

void setup() {
  Serial.begin(9600);
  Serial.print("compiled: ");
  Serial.print(__DATE__);
  Serial.println(__TIME__);
  Wire.begin(5, 4);
  Rtc.Begin();
  RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);
  printDate(compiled);
  printTime(compiled);
  interval_data(compiled);
  interval_data2(compiled);
  Serial.println();
  if (!Rtc.IsDateTimeValid())
  {
    if (Rtc.LastError() != 0)
    {
      Serial.print("RTC communications error = ");
      Serial.println(Rtc.LastError());
    }
    else
    {
      Serial.println("RTC lost confidence in the DateTime!");
      Rtc.SetDateTime(compiled);
    }
  }
  if (!Rtc.GetIsRunning())
  {
    Serial.println("RTC was not actively running, starting now");
    Rtc.SetIsRunning(true);
  }
  RtcDateTime now = Rtc.GetDateTime();
  if (now < compiled)
  {
    Serial.println("RTC is older than compile time!  (Updating DateTime)");
    Rtc.SetDateTime(compiled);
  }
  else if (now > compiled)
  {
    Serial.println("RTC is newer than compile time. (this is expected)");
  }
  else if (now == compiled)
  {
    Serial.println("RTC is the same as compile time! (not expected but all is fine)");
  }
  Rtc.Enable32kHzPin(false);
  Rtc.SetSquareWavePin(DS3231SquareWavePin_ModeNone);
  // ----------------------------------END SETUP RTC--------------------------------------------------
  Serial.print("Initializing SD card...");
  if (!SD.begin(15)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  //mesh.setDebugMsgTypes( ERROR | MESH_STATUS | CONNECTION | SYNC | COMMUNICATION | GENERAL | MSG_TYPES | REMOTE ); // all types on
  //  mesh.setDebugMsgTypes( ERROR | STARTUP );  // set before init() so that you can see startup messages

  mesh.init( MESH_PREFIX, MESH_PASSWORD, &userScheduler, MESH_PORT );
  mesh.onReceive(&receivedCallback);
  mesh.onNewConnection(&newConnectionCallback);
  mesh.onChangedConnections(&changedConnectionCallback);
  mesh.onNodeTimeAdjusted(&nodeTimeAdjustedCallback);

  userScheduler.addTask( taskSendMessage );
  taskSendMessage.enable();
}

void loop() {

  if (!Rtc.IsDateTimeValid())
  {
    if (Rtc.LastError() != 0)
    {
      Serial.print("RTC communications error = ");
      Serial.println(Rtc.LastError());
    }
    else
    {
      Serial.println("RTC lost confidence in the DateTime!");
    }
  }
  //  RtcDateTime now = Rtc.GetDateTime();
  //  printDateTime(now);
  //  Serial.println();
  //  temp = Rtc.GetTemperature();
  //  temp.Print(Serial);
  //  Serial.println("C");
  RtcDateTime now = Rtc.GetDateTime();
  int interval = interval_data(now).toInt();
  int interval2 = interval_data2(now).toInt();
  if (interval2 == 0) {
    SD.remove("new.csv");
    writeToCsv();
  }
  mesh.update();
}
void writeToCsv() {
  myFile = SD.open("new.csv", FILE_WRITE);
  if (myFile) {
    RtcDateTime now = Rtc.GetDateTime();
    String timestamp = printTime(now);
    String datestamp = printDate(now);
    Serial.print(timestamp);
    myFile.print(mesh.getNodeId());
    myFile.print(",");
    myFile.print(datestamp);
    myFile.print(",");
    myFile.println(timestamp);
    myFile.close();
    //    Serial.println("done.");
  } else {
    Serial.println("error opening data.csv");
  }

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

//----------------------------------------------------------------------

#define countof(a) (sizeof(a) / sizeof(a[0]))

String printDate(const RtcDateTime& dt)
{
  char datestring[20];
  sprintf(datestring, "%02d/%02d/%d",
          dt.Month(),
          dt.Day(),
          dt.Year() );
  //Serial.println(datestring);
  return datestring;
}
String printTime(const RtcDateTime& dt)
{
  char timestring[20];
  sprintf(timestring, "%02d:%02d",
          dt.Hour(),
          dt.Minute() );
  //Serial.println(timestring);
  return timestring;
}
String interval_data(const RtcDateTime& dt)
{
  char timestring[20];
  sprintf(timestring, "%d",
          dt.Minute() );
  //    Serial.println(timestring);
  return timestring;
}
String interval_data2(const RtcDateTime& dt)
{
  char timestring[20];
  sprintf(timestring, "%d",
          dt.Second() );
  //    Serial.println(timestring);
  return timestring;
}

