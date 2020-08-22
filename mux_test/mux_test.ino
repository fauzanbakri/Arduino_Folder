int s2 = 16;
  
//gunakan A0 sebagai input
int analogPin = A0;
  
//variabel untuk menyimpan nilai input
int nilaiInput = 0;
  
void setup() {
  //jadikan pin select sebagai output
  pinMode(s2, OUTPUT);
  
  //aktifkan komunikasi serial
  Serial.begin(9600);
}
  
void loop() {
  //memilih y0 sebagai input
  digitalWrite(s2,LOW);
  nilaiInput = analogRead(analogPin);
  Serial.print(nilaiInput);
  Serial.print(" ");
  delay(100);
     
  //memilih y1 sebagai input
  digitalWrite(s2,HIGH);
  nilaiInput = analogRead(analogPin);
  Serial.println(nilaiInput);
  delay(100);  
}
