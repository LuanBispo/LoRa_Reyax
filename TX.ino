#include <SoftwareSerial.h>

#define button D2

SoftwareSerial lora(D5, D6);

String lora_RX_address = "93";   //enter Lora RX address

void setup()
{
  pinMode(button, INPUT);
  Serial.begin(115200);
  lora.begin(115200);
}

void loop()
{
  if (digitalRead(button) == LOW) {
    lora.println("AT+SEND=" + lora_RX_address + ",2,LO"); // AT+SEND=1,2,LO
    delay(1000);
  } 
  else {
    lora.println("AT+SEND=" + lora_RX_address + ",2,HI"); // AT+SEND=1,2,HI
    delay(1000);
  }
}