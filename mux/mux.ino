
#define MUX_A 14
#define MUX_B 12
#define MUX_C 13

#define ANALOG_INPUT A0


void setup() {
  //Deifne output pins for Mux
  pinMode(MUX_A, OUTPUT);
  pinMode(MUX_B, OUTPUT);     
  pinMode(MUX_C, OUTPUT);
  Serial.begin(9600);     
}

void changeMux(int c, int b, int a) {
  digitalWrite(MUX_A, a);
  digitalWrite(MUX_B, b);
  digitalWrite(MUX_C, c);
}

void loop() {
  float value;
  float outputValue;
  changeMux(LOW, LOW, LOW);
  value = analogRead(ANALOG_INPUT); //Value of the sensor connected Option 0 pin of Mux
  outputValue = (-0.0693*value)+7.3855;
  Serial.print("  output Ph= ");
  Serial.println(outputValue);

  delay(1000);
//  changeMux(LOW, LOW, HIGH);
//  value = analogRead(ANALOG_INPUT); //Value of the sensor connected Option 1 pin of Mux
//  
//  changeMux(LOW, HIGH, LOW);
//  value = analogRead(ANALOG_INPUT); //Value of the sensor connected Option 2 pin of Mux
//
//  changeMux(LOW, HIGH, HIGH);
//  value = analogRead(ANALOG_INPUT); //Value of the sensor connected Option 3 pin of Mux
//
//  changeMux(HIGH, LOW, LOW);
//  value = analogRead(ANALOG_INPUT); //Value of the sensor connected Option 4 pin of Mux
//
//  changeMux(HIGH, LOW, HIGH);
//  value = analogRead(ANALOG_INPUT); //Value of the sensor connected Option 5 pin of Mux
//
//  changeMux(HIGH, HIGH, LOW);
//  value = analogRead(ANALOG_INPUT); //Value of the sensor connected Option 6 pin of Mux
//
//  changeMux(HIGH, HIGH, HIGH);
//  value = analogRead(ANALOG_INPUT); //Value of the sensor connected Option 7 pin of Mux


}
