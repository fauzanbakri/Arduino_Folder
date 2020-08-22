int sensorPin = A0;
int nilai;

void setup() {
Serial.begin(9600);
}

void loop() {
int nilai = analogRead(sensorPin);
Serial.print(“Kelembaban tanah : “);
Serial.println(nilai);

if(nilai > 700){
Serial.println(“Tanah kering, siram air”);
}else if(nilai < 700 && nilai > 350){
Serial.println(“Kelembaban normal gan”);
}else{
Serial.println(“Tanah basah/lembab gan”);
}
delay(500);
}
