#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Arduino.h>

// Función para cifrar el mensaje usando el cifrado de César
String cifrar(String mensaje, int clave)
{
    String mensaje_cifrado = "";

    for (int i = 0; i < mensaje.length(); i++)
    {
        if (isAlpha(mensaje.charAt(i)))
        {
            char caracter = isUpperCase(mensaje.charAt(i)) ? 'A' : 'a';
            mensaje_cifrado += (char)(((mensaje.charAt(i) - caracter + clave) % 26) + caracter);
        }
        else
        {
            mensaje_cifrado += mensaje.charAt(i);
        }
    }

    return mensaje_cifrado;
}

// Función para descifrar el mensaje usando el cifrado de César
String descifrar(String mensaje_cifrado, int clave)
{
    return cifrar(mensaje_cifrado, 26 - clave);
}

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";

void setup()
{
    Serial.begin(9600);
    radio.begin();
    radio.openWritingPipe(address);
    radio.setPALevel(RF24_PA_MIN);
    radio.stopListening();
}

void loop()
{
    String mensaje = "Hello World";
    int clave = 3;
    String mensaje_cifrado = cifrar(mensaje, clave);
    Serial.println("[ ok ]" + mensaje + " -> "  + mensaje_cifrado);
    radio.write(&text, sizeof(text));
    delay(1000);
}