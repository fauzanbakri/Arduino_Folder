#include<string.h>
byte buff[2];
unsigned long duration1;
unsigned long starttime1;
unsigned long endtime1;
unsigned long duration2;
unsigned long starttime2;
unsigned long endtime2;
unsigned long sampletime_ms = 1000;
unsigned long lowpulseoccupancy1 = 0;
unsigned long lowpulseoccupancy2 = 0;
float ratio1 = 0;
float concentration1 = 0;
float ratio2 = 0;
float concentration2 = 0;
int pin_pm25 =4, pin_pm10 = 90;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(10);
  pinMode(pin_pm25,INPUT);
  pinMode(pin_pm10,INPUT);
  starttime1 = millis();
  starttime2 = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  duration1 = pulseIn(pin_pm10, LOW);
  duration2 = pulseIn(pin_pm25, LOW);
  lowpulseoccupancy1 += duration1;
  lowpulseoccupancy2 += duration2;
  endtime1 = millis();
  endtime2 = millis();
  if ((endtime1-starttime1) > sampletime_ms)
  {
    ratio1 = (lowpulseoccupancy1-endtime1+starttime1 + sampletime_ms)/(sampletime_ms*10.0);  // Integer percentage 0=>100
    concentration1 = 1.1*pow(ratio1,3)-3.8*pow(ratio1,2)+520*ratio1+0.62; // using spec sheet curve
      if (ratio1 > 400000){
      concentration1 = 0;
      ratio1 = 0;
    }
    Serial.print("lowpulseoccupancy1:");
    Serial.print(lowpulseoccupancy1);
    Serial.print("    ratio1:");
    Serial.print(ratio1);
    Serial.print("    DSM501A 1:");
    Serial.println(concentration1);
    lowpulseoccupancy1 = 0;
    starttime1 = millis();
  }
    if ((endtime2-starttime2) > sampletime_ms)
  {
    ratio2 = (lowpulseoccupancy2-endtime2+starttime2 + sampletime_ms)/(sampletime_ms*10.0);  // Integer percentage 0=>100
    concentration2 = 1.1*pow(ratio2,3)-3.8*pow(ratio2,2)+520*ratio2+0.62; // using spec sheet curve
    if (ratio2 > 400000){
      concentration2 = 0;
      ratio2 = 0;
    }
    Serial.print("lowpulseoccupancy2:");
    Serial.print(lowpulseoccupancy2);
    Serial.print("    ratio2:");
    Serial.print(ratio2);
    Serial.print("    DSM501A 2:");
    Serial.println(concentration2);
    lowpulseoccupancy2 = 0;
    starttime2 = millis();
  }
}
