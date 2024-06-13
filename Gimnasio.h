#ifndef GIMNASIO_H
#define GIMNASIO_H

#include <iostream>
#include <vector>
#include "Entrenador.h"
#include "Jugador.h"

class Gimnasio {
private:
    std::vector<Entrenador> entrenadores;

public:
    Gimnasio() {
        int numEntrenadores = rand() % 6 + 1;
        for (int i = 0; i < numEntrenadores; i++) {
            entrenadores.push_back(Entrenador());
        }
    }

    void enfrentarEntrenador(Jugador& jugador) const {
        std::cout << "Enfrentando a un entrenador del gimnasio..." << std::endl;
        entrenadores[rand() % entrenadores.size()].batallar(jugador);
    }

    void mostrarGimnasio() const {
        std::cout << "Gimnasio con " << entrenadores.size() << " entrenadores." << std::endl;
    }
};

#endif // GIMNASIO_H
