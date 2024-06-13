#ifndef PUEBLO_H
#define PUEBLO_H

#include <string>
#include <vector>
#include "Gimnasio.h"
#include "Centro Pokemon.h"
#include "Casa.h"

class Pueblo {
private:
    std::string nombre;
    std::vector<Gimnasio> gimnasios;
    CentroPokemon centroPokemon;
    std::vector<Casa> casas;

public:
    Pueblo(std::string nombre) : nombre(nombre), centroPokemon(CentroPokemon()) {
        for (int i = 0; i < 4; i++) {
            gimnasios.push_back(Gimnasio());
        }
        for (int i = 0; i < 3; i++) {
            casas.push_back(Casa());
        }
    }

    void explorarPueblo(Jugador& jugador) const {
        std::cout << "Estas en el pueblo: " << nombre << std::endl;
        std::cout << "1. Visitar Gimnasio" << std::endl;
        std::cout << "2. Visitar Centro Pokemon" << std::endl;
        std::cout << "3. Visitar Casa" << std::endl;
        std::cout << "Seleccione una opcion: ";
        int opcion;
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                gimnasios[rand() % gimnasios.size()].enfrentarEntrenador(jugador);
                break;
            case 2:
                centroPokemon.curarPokemons(jugador);
                break;
            case 3:
                casas[rand() % casas.size()].visitarCasa();
                break;
            default:
                std::cout << "Opcion no valida. Saliendo del pueblo..." << std::endl;
        }
    }
};

#endif // PUEBLO_H
