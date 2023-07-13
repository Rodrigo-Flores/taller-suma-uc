#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Arduino.h>
#include <string.h>

char characters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                     'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                     'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3',
                     '4', '5', '6', '7', '8', '9', ' '};

const char *morseCodes[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
                            ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
                            "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----",
                            ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "/"};

String cifrar(String mensaje)
{
  String mensaje_cifrado = "";

  for (int i = 0; i < mensaje.length(); i++)
  {
    char caracter = toupper(mensaje.charAt(i));

    if (caracter == ' ')
    {
      mensaje_cifrado += "/ ";
    }
    else
    {
      for (int j = 0; j < sizeof(characters); j++)
      {
        if (characters[j] == caracter)
        {
          mensaje_cifrado += morseCodes[j];
          mensaje_cifrado += " ";
          break;
        }
      }
    }
  }

  mensaje_cifrado += "/";
  return mensaje_cifrado;
}

String descifrar(String mensaje_cifrado)
{
  String mensaje_descifrado = "";
  String morse = "";

  for (int i = 0; i < mensaje_cifrado.length(); i++)
  {
    char caracter = mensaje_cifrado.charAt(i);

    if (caracter != ' ')
    {
      morse += caracter;
    }
    else
    {
      if (morse == "/")
      {
        mensaje_descifrado += ' '; // Agregar espacio entre palabras
      }
      else
      {
        bool encontrado = false;
        for (int j = 0; j < sizeof(morseCodes); j++)
        {
          if (strcmp(morseCodes[j], morse.c_str()) == 0)
          {
            mensaje_descifrado += characters[j];
            encontrado = true;
            break;
          }
        }
        if (!encontrado)
        {
          mensaje_descifrado += 'e'; // Caracter desconocido
        }
      }
      morse = "";
    }
  }

  return mensaje_descifrado;
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
  String mensaje_cifrado = cifrar(mensaje);
  radio.write(&mensaje_cifrado, sizeof(mensaje_cifrado));
  Serial.println("[ ok ]" + mensaje + " -> " + mensaje_cifrado);
  delay(1000);
}