#include <Arduino.h>

char polybios[5][5] = {
    {'A', 'B', 'C', 'D', 'E'},
    {'F', 'G', 'H', 'I', 'K'},
    {'L', 'M', 'N', 'O', 'P'},
    {'Q', 'R', 'S', 'T', 'U'},
    {'V', 'W', 'X', 'Y', 'Z'}};

String cifrar(const String &mensaje)
{
  String mensaje_cifrado = "";

  for (char c : mensaje)
  {
    char letra = toupper(c);
    if (letra == 'J')
    {
      letra = 'I';
    }

    if (isAlpha(letra))
    {
      for (int i = 0; i < 5; i++)
      {
        for (int j = 0; j < 5; j++)
        {
          if (polybios[i][j] == letra)
          {
            int fila = i + 1;
            int columna = j + 1;
            mensaje_cifrado += String(fila);
            mensaje_cifrado += String(columna);
            break;
          }
        }
      }
    }
    else if (letra == ' ')
    {
      mensaje_cifrado += ' ';
    }
  }

  return mensaje_cifrado;
}

String descifrar(const String &mensaje_cifrado)
{
  String mensaje_descifrado = "";

  for (int i = 0; i < mensaje_cifrado.length(); i += 2)
  {
    if (mensaje_cifrado != ' ')
    {
      if (isdigit(mensaje_cifrado[i]) && isdigit(mensaje_cifrado[i + 1]))
      {
        int fila = mensaje_cifrado[i] - '0';
        int columna = mensaje_cifrado[i + 1] - '0';

        if (fila >= 1 && fila <= 5 && columna >= 1 && columna <= 5)
        {
          char letra = polybios[fila - 1][columna - 1];
          mensaje_descifrado += letra;
        }
      }
      else if (mensaje_cifrado[i] == ' ')
      {
        mensaje_descifrado += ' ';
      }
    }
    else
    {
      break;
    }
  }

  return mensaje_descifrado;
}

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available())
  {
    String mensaje = "CAMBIAR MENSAJE AQUÍ";
    String mensaje_descifrado = descifrar(mensaje);
    Serial.println(mensaje + " -> " + mensaje_descifrado);
    Serial.readStringUntil('\n');
  }
}
