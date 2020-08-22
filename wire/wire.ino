#include <OneWire.h>
#include <DallasTemperature.h>

#define DS18B20 0

OneWire ourWire(DS18B20);
DallasTemperature sensor(&ourWire);
float solarPanelTemperature = 0.00;
float _offset_voltage = 0.00;

void ds18s20(){
  sensor.begin();  
  sensor.requestTemperatures();
  solarPanelTemperature = sensor.getTempCByIndex(0) + _offset_voltage;
  Serial.print("DS18B20 Temp = ");
  Serial.println(solarPanelTemperature);   
//
//  // Publishing sensor data
//  mqttPublish(MQTT_TOPIC_CELCIUS, solarPanelTemperature);
  Serial.print("");
}

void loop(){
   ds18s20();
  }
