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

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    if (Serial.available())
    {
        String mensaje = "";
        int clave = 3;
        String mensaje_descifrado = descifrar(mensaje_cifrado, clave);
        Serial.println(mensaje + " ->" + mensaje_descifrado);
        Serial.readStringUntil('\n');
    }
}
