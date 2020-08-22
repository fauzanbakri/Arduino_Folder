 void setup() {
 pinMode(2, OUTPUT);
 pinMode(5, OUTPUT);
 Serial.begin(115200);
}
void loop() {
 if (digitalRead(16) == HIGH){
 digitalWrite(5, HIGH);
 }else if(digitalRead(16) == LOW){
 digitalWrite(5, LOW);
  }
 
}
