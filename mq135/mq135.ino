#include <MQ7.h>
#include "MQ135.h"

MQ135 gasSensor = MQ135(A0);
MQ7 mq7(A0,5.0);

float rzero = gasSensor.getRZero();
int ppm = gasSensor.getPPM();

// SETUP
void setup() {
Serial.begin(9600);
pinMode(16, OUTPUT);
}

// LOOP
void loop() { 
    digitalWrite(16, LOW);
    int ppm = gasSensor.getPPM();
    Serial.print("Air Quality(ppm): ");
    Serial.println(ppm);
    
    digitalWrite(16, HIGH);
    int ppm_co = mq7.getPPM();
    Serial.print("CO(ppm): ");
    Serial.println(ppm_co);
    delay(1000);
}

