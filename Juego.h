#ifndef JUEGO_H
#define JUEGO_H

#include <iostream>
#include <vector>
#include <string>
#include "Jugador.h"
#include "Ciudad.h"
#include "Pueblo.h"
#include "Ruta.h"

class Juego {
private:
    Jugador jugador;
    int medallasRecolectadas;

public:
    Juego() : medallasRecolectadas(0) {}

    void iniciarJuego();  // Declaración de la función iniciarJuego()

    // Otras funciones de la clase Juego
    void seleccionarPokemonInicial();
    void viajar();
    void explorarRuta();
    void recolectarMedalla();
};

#endif // JUEGO_H
