#include <ESP8266WiFi.h>
#include <PubSubClient.h>
 
const char* ssid = "Connectify-l";
const char* password =  "08080808";
const char* mqttServer = "10.0.6.120";
const int mqttPort = 1883;
const char* mqttUser = "tes";
const char* mqttPassword = "123";
 
WiFiClient espClient;
PubSubClient client(espClient);
 
void setup() {
 
  Serial.begin(9600);
  pinMode(D2,OUTPUT);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
 
  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);
 
  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");
 
    if (client.connect("ESP8266Client", mqttUser, mqttPassword )) {
 
      Serial.println("connected");  
 
    } else {
 
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
 
    }
  }
 
  client.publish("fzn", "Tess Bossssss");
  client.subscribe("test");
 
}
 
void callback(char* topic, byte* payload, unsigned int length) {
 
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);
 
  Serial.print("Message:");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  if(topic=="1"){
    digitalWrite(D2,HIGH);
  }
    else if(topic=="0"){
    digitalWrite(D2,LOW);
  }
  Serial.println();
  Serial.println("-----------------------");
 
}
 
void loop() {
  client.loop();
 
}
