#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Mapa.h"

int main() {
    // Inicializar la semilla del generador de números aleatorios
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Crear el objeto mapa
    Mapa mapa;

    // Ejecutar el juego
    mapa.ejecutar();

    return 0;
}
