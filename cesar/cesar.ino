#include <Arduino.h>

// Función para cifrar el mensaje usando el cifrado de César
String cifrar(String mensaje, int clave) {
    String mensaje_cifrado = "";

    for (int i = 0; i < mensaje.length(); i++) {
        if (isAlpha(mensaje.charAt(i))) {
            char caracter = isUpperCase(mensaje.charAt(i)) ? 'A' : 'a';
            mensaje_cifrado += (char)(((mensaje.charAt(i) - caracter + clave) % 26) + caracter);
        } else {
            mensaje_cifrado += mensaje.charAt(i);
        }
    }

    return mensaje_cifrado;
}

// Función para descifrar el mensaje usando el cifrado de César
String descifrar(String mensaje_cifrado, int clave) {
    return cifrar(mensaje_cifrado, 26 - clave);
}

void setup() {
    Serial.begin(9600);

    String mensaje;
    int clave;

    Serial.println("Ingrese el mensaje: ");
    while (!Serial.available()) {
        // Esperar hasta que se ingrese el mensaje en el monitor serial
    }
    mensaje = Serial.readString();

    Serial.println("Ingrese la clave de cifrado: ");
    while (!Serial.available()) {
        // Esperar hasta que se ingrese la clave en el monitor serial
    }
    clave = Serial.parseInt();

    String mensaje_cifrado = cifrar(mensaje, clave);
    String mensaje_descifrado = descifrar(mensaje_cifrado, clave);

    Serial.println("Mensaje cifrado: " + mensaje_cifrado);
    Serial.println("Mensaje descifrado: " + mensaje_descifrado);
}

void loop() {
    // El código principal se ejecuta en el loop solo una vez
}
