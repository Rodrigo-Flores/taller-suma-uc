# Cifrados en Arduino

Este repositorio contiene el código que se usará durante los talleres SUMA UC. Se realizará un envío de paquetes cifrados a través del módulo de radiofrecuencia NRF24L01+, haciendo uso de una placa de arduino mega.


## Materiales

1. NRF24L01+.
2. Arduino mega.
3. Cable USB A macho y USB micro macho.


## Diseño de Conexiones con Arduino y Módulo de Radiofrecuencia

![connection](conn.png)


## Cómo usar el código

Dentro de cada carpeta, que tienen el nombre de cada cifrado, se encuentra su código correspondiente. La nomenclatura es la siguiente:

- `encriptar_*.ino` es para encriptar un mensaje localmente
- `desencriptar_*.ino` es para desencriptar un mensaje localmente
- `enviar_*.ino` es para enviar un mensaje encriptado a través del NRF24L01+
- `recibir_*.ino` es para enviar un mensaje encriptado a través del NRF24L01+
