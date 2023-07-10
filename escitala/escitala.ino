#include <Arduino.h>
#include <string.h>

char characters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                     'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                     'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3',
                     '4', '5', '6', '7', '8', '9', ' '};

// Función para cifrar el mensaje usando la escítala romana
String cifrar(const String& mensaje, int n) {
    String mensaje_cifrado;
    int longitud = mensaje.length();
    int num_columnas = ceil(static_cast<double>(longitud) / n);

    for (int i = 0; i < num_columnas; i++) {
        for (int j = 0; j < n; j++) {
            int indice = i + j * num_columnas;
            if (indice < longitud) {
                mensaje_cifrado += mensaje[indice];
            }
        }
    }

    return mensaje_cifrado;
}

// Función para descifrar el mensaje usando la escítala romana
String descifrar(const String& mensaje_cifrado, int n) {
    String mensaje_descifrado;
    int longitud = mensaje_cifrado.length();
    int num_filas = ceil(static_cast<double>(longitud) / n);

    for (int i = 0; i < num_filas; i++) {
        for (int j = 0; j < n; j++) {
            int indice = j + i * n;
            if (indice < longitud) {
                mensaje_descifrado += mensaje_cifrado[indice];
            }
        }
    }

    return mensaje_descifrado;
}

void setup() {
    Serial.begin(9600);
}

void loop() {
    if (Serial.available()) {
        String mensaje = Serial.readStringUntil('\n');
        int n = Serial.parseInt();

        String mensaje_cifrado = cifrar(mensaje, n);
        String mensaje_descifrado = descifrar(mensaje_cifrado, n);

        Serial.println("Mensaje cifrado: " + mensaje_cifrado);
        Serial.println("Mensaje descifrado: " + mensaje_descifrado);
    }
}
