#include <SoftwareSerial.h>

#define LED 7

String incomingString;

SoftwareSerial lora(2,3);

void setup()
{
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  lora.begin(115200);
  lora.setTimeout(500);
}

void loop()
{
  if (lora.available()) {

    incomingString = lora.readString();
    Serial.println(incomingString);

    char dataArray[30]; 
    incomingString.toCharArray(dataArray,30);
    char* data = strtok(dataArray, ",");
    data = strtok(NULL, ",");
    data = strtok(NULL, ",");
    Serial.println(data);
    
    if (strcmp(data,"HI") == 0) {
      digitalWrite(LED, HIGH);
      delay(50);
    }

    if (strcmp(data,"LO") == 0) {
      digitalWrite(LED, LOW);
      delay(50);
    }
  }
}