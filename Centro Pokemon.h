#ifndef CENTROPOKEMON_H
#define CENTROPOKEMON_H

#include <iostream>
#include "Jugador.h"

class CentroPokemon {
public:
    CentroPokemon() {}

    void curarPokemons(Jugador& jugador) const {
        std::cout << "Curando todos los pokemons del jugador..." << std::endl;
        jugador.curarPokemons();
    }

    void mostrarCentroPokemon() const {
        std::cout << "Centro Pokemon" << std::endl;
    }
};

#endif // CENTROPOKEMON_H
