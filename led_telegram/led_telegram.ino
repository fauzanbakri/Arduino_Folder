#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <TelegramBot.h>
#define LED 2 //esp01 pin GPIO 1

// Initialize Wifi connection to the router
const char* ssid  = "fzn1";         //nama wifi hostpotnya
const char* password = "fauzan97";  //password wifinya


// Initialize Telegram BOT
const char BotToken[] = "1041241818:AAGkGjKEu3jq7VecruOVyjwEFDRzxL7cq6Y"; //token bot telegram

WiFiClientSecure net_ssl;
TelegramBot bot (BotToken, net_ssl);


void setup() {
  pinMode(LED, OUTPUT);
  while (WiFi.status() != WL_CONNECTED) {
    //led kedip-kedip kalau belum connect wifi
    digitalWrite(LED, 0);
    delay(200);
    digitalWrite(LED, 1);
    delay(200);
  }
  digitalWrite(LED, 1);//Led mati
  bot.begin();
}

void loop() {
    message m = bot.getUpdates(); // Read new messages
    if (m.text.equals("cek")|| m.text.equals("Cek") || m.text.equals("CEK")){   
        bot.sendMessage(m.chat_id, "Device is Active Now");   
    }  
    if (m.text.equals("on")|| m.text.equals("On")|| m.text.equals("ON")){   
        digitalWrite(LED, 0); // led nyala   
        bot.sendMessage(m.chat_id, "The Led is now ON");   
    }   
    if (m.text.equals("off")|| m.text.equals("Off")|| m.text.equals("OFF")) {   
        digitalWrite(LED, 1); //led mati   
        bot.sendMessage(m.chat_id, "The Led is now OFF");   
    }
}
