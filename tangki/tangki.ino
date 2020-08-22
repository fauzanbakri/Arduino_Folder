#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>

// utlrasonic pinout
#define ULTRASONIC_TRIG_PIN     5   // pin TRIG to D1
#define ULTRASONIC_ECHO_PIN     4   // pin ECHO to D2

// user config: TODO
const char* wifi_ssid = "whateverYouLike";             // SSID
const char* wifi_password = "somethingSneaky";         // WIFI
const char* apiKeyIn = "tes";      // API KEY IN
const unsigned int writeInterval = 25000; // write interval (in ms)

// ASKSENSORS config.
String host = "http://localhost";         // ASKSENSORS host name

ESP8266WiFiMulti WiFiMulti;

void setup() {

  Serial.begin(115200);
  Serial.println("*****************************************************");
  Serial.println("********** Program Start : Connect Ultrasonic HC-SR04 + ESP8266 to AskSensors over HTTP");
  Serial.println("Wait for WiFi... ");
  Serial.print("********** connecting to WIFI : ");
  Serial.println(wifi_ssid);
  WiFi.begin(wifi_ssid, wifi_password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("-> WiFi connected");
  Serial.println("-> IP address: ");
  Serial.println(WiFi.localIP());
  // ultraonic setup 
  pinMode(ULTRASONIC_TRIG_PIN, OUTPUT);
  pinMode(ULTRASONIC_ECHO_PIN, INPUT);
  
}


void loop() {
    // wait for WiFi connection
  if (WiFi.status() == WL_CONNECTED){

        HTTPClient http;

        Serial.print("[HTTP] begin...\n");

        long duration, distance;
        digitalWrite(ULTRASONIC_TRIG_PIN, LOW);  
        delayMicroseconds(2); 
        
        digitalWrite(ULTRASONIC_TRIG_PIN, HIGH);
        delayMicroseconds(10); 
        
        digitalWrite(ULTRASONIC_TRIG_PIN, LOW);
        duration = pulseIn(ULTRASONIC_ECHO_PIN, HIGH);
        distance = (duration/2) / 29.1;
        Serial.print("********** Ultrasonic Distance: ");
        Serial.print(distance);
        Serial.println(" cm");
  
        // Create a URL for the request
        String url = "";
        url += host;
        url += "/write/";
        url += apiKeyIn;
        url += "?module1=";
        url += distance;
        
        Serial.print("********** requesting URL: ");
        Serial.println(url);
        http.begin(url); //HTTP
        
        Serial.println("> Request sent to ASKSENSORS");

        Serial.print("[HTTP] GET...\n");
        // start connection and send HTTP header
        int httpCode = http.GET();

        // httpCode will be negative on error
        if(httpCode > 0) {
            // HTTP header has been send and Server response header has been handled
            Serial.printf("[HTTP] GET... code: %d\n", httpCode);

            // file found at server
            if(httpCode == HTTP_CODE_OK) {
                String payload = http.getString();
                Serial.println(payload);
            }
        } else {
            Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();

        Serial.println("********** End ");
        Serial.println("*****************************************************");
    }

    delay(writeInterval);
}
