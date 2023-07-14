#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  const char text[] = "CAMBIAR MENSAJE AQUÍ"; // máximo 32 caracteres
  radio.write(&text, sizeof(text));
  Serial.println("[ ok ] mensaje enviado");
  delay(1000);
}