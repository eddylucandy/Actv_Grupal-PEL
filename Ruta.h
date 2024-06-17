#ifndef RUTA_H
#define RUTA_H

#include <iostream>
#include <vector>
#include "Entrenador.h"
#include "Pokemon.h"
#include "Jugador.h"

class Ruta {
private:
    std::vector<Entrenador> entrenadores;
    std::vector<Pokemon> pokemonsSalvajes;

public:
    Ruta() {
        int numEntrenadores = rand() % 5 + 1;
        for (int i = 0; i < numEntrenadores; i++) {
            entrenadores.push_back(Entrenador());
        }

        int numPokemonsSalvajes = rand() % 10 + 1;
        for (int i = 0; i < numPokemonsSalvajes; i++) {
            // Escoger un Pokémon base aleatorio de los primeros 20
            const PokemonBase& base = primeros20Pokemon[rand() % primeros20Pokemon.size()];

            // Crear un nuevo Pokémon con base en el PokémonBase seleccionado
            Pokemon nuevoPokemon(base, 5, 100);

            // Agregar el nuevo Pokémon salvaje al vector
            pokemonsSalvajes.push_back(nuevoPokemon);
        }
    }

    void explorarRuta(Jugador& jugador) const {
        std::cout << "Estás explorando la ruta..." << std::endl;
        int evento = rand() % 2;
        if (evento == 0) {
            std::cout << "Te has encontrado con un entrenador!" << std::endl;
            entrenadores[rand() % entrenadores.size()].batallar(jugador);
        } else {
            std::cout << "Te has encontrado con un Pokemon salvaje!" << std::endl;
            // Lógica para atrapar o luchar contra el Pokémon salvaje (a implementar)
        }
    }

    void mostrarRuta() const {
        std::cout << "Ruta con " << entrenadores.size() << " entrenadores y " << pokemonsSalvajes.size() << " pokemons salvajes." << std::endl;
    }
};

#endif // RUTA_H
