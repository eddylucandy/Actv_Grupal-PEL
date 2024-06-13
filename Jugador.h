#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
#include <vector>
#include "Pokemon.h"

class Jugador {
private:
    std::string nombre;
    std::vector<Pokemon> pokemons;

public:
    Jugador(std::string nombre) : nombre(nombre) {}
    Jugador() {}

    void agregarPokemon(const Pokemon& pokemon) {
        pokemons.push_back(pokemon);
    }

    void mostrarPokemons() const {
        for (const auto& pokemon : pokemons) {
            pokemon.mostrarInfo();
        }
    }

    void curarPokemons() {
        for (auto& pokemon : pokemons) {
            pokemon.curar();
        }
        std::cout << "Todos tus pokemons han sido curados." << std::endl;
    }

    std::string getNombre() const {
        return nombre;
    }
};

#endif // JUGADOR_H
