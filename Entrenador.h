#ifndef ENTRENADOR_H
#define ENTRENADOR_H

#include <vector>
#include "Pokemon.h"

class Entrenador {
private:
    std::vector<Pokemon> pokemons;

public:
    Entrenador() {
        int numPokemons = rand() % 6 + 1;
        for (int i = 0; i < numPokemons; i++) {
            Pokemon nuevoPokemon("Pokemon" + std::to_string(i + 1), TipoPokemon::Normal, 5, 100, 50, 50);
            pokemons.push_back(nuevoPokemon);
        }
    }

    void batallar(Jugador& jugador) const {
        std::cout << "Batalla contra el entrenador con " << pokemons.size() << " pokemons." << std::endl;
        // Lógica de batalla (a implementar)
    }

    void mostrarEntrenador() const {
        std::cout << "Entrenador con " << pokemons.size() << " pokemons." << std::endl;
    }
};

#endif // ENTRENADOR_H
