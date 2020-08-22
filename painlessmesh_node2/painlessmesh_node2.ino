#include "FS.h"

void setup() {
  Serial.begin(115200);
  String str = "";
  Dir dir = SPIFFS.openDir("/");
  while (dir.next()) {
      str += dir.fileName();
      str += " / ";
      str += dir.fileSize();
      str += "\r\n";
  }
  Serial.print(str);
}

void loop() {
  // nothing to do for now, this is just a simple test

}
