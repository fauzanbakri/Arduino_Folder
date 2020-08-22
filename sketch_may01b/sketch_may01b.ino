void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(16, OUTPUT);
  digitalWrite(16, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  int ldr = analogRead(A0);
  Serial.println(ldr);
  if  (ldr < 700){
    digitalWrite(16, HIGH);
    delay(1000);
  }else if(800 <  ldr){
    digitalWrite(16, LOW);
    delay(1000);
  }else{
    delay(1000);
  }
  delay(1000);
}
