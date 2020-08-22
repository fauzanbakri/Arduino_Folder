
#include <SD.h>
#include <DHT.h>
#define DHTPIN D2     
#define DHTTYPE DHT22   

DHT dht(DHTPIN, DHTTYPE);

#define CS_PIN  D8

void setup()
{
  Serial.begin(9600);
  Serial.print("Inicializando o cartão SD...");
  dht.begin();
  if (!SD.begin(CS_PIN)) {
    Serial.println("Falha, verifique se o cartão está presente.");
    //programa encerrrado
    return;
  }
  Serial.println("Cartão inicializado.");
 
}
void loop (){
  float umidade = 21312;
  Serial.print("Umidade: ");
  Serial.println(umidade);
  float temperatura = 323213;
  Serial.print("Temperatura: ");
  Serial.println(temperatura);
 
  File dataFile = SD.open("LOG.txt", FILE_WRITE);
  if (dataFile) {
    Serial.println("O arquivo foi aberto com sucesso.");
      dataFile.print(umidade);
      dataFile.print(" | ");
      dataFile.println(temperatura);
      dataFile.close();
  }
  else {
    Serial.println("Falha ao abrir o arquivo LOG.txt");
  }
  delay(2000);
 
}
