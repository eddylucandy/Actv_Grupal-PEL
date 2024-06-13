#ifndef CIUDAD_H
#define CIUDAD_H

#include <string>
#include <vector>
#include "Gimnasio.h"
#include "Centro Pokemon.h"
#include "Casa.h"

class Ciudad {
private:
    std::string nombre;
    Gimnasio gimnasio;
    CentroPokemon centroPokemon;
    std::vector<Casa> casas;

public:
    Ciudad(std::string nombre) : nombre(nombre), gimnasio(Gimnasio()), centroPokemon(CentroPokemon()) {
        for (int i = 0; i < 5; i++) {
            casas.push_back(Casa());
        }
    }

    void explorarCiudad(Jugador& jugador) const {
        std::cout << "Estas en la ciudad: " << nombre << std::endl;
        std::cout << "1. Visitar Gimnasio" << std::endl;
        std::cout << "2. Visitar Centro Pokemon" << std::endl;
        std::cout << "3. Visitar Casa" << std::endl;
        std::cout << "Seleccione una opcion: ";
        int opcion;
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                gimnasio.enfrentarEntrenador(jugador);
                break;
            case 2:
                centroPokemon.curarPokemons(jugador);
                break;
            case 3:
                casas[rand() % casas.size()].visitarCasa();
                break;
            default:
                std::cout << "Opcion no valida. Saliendo de la ciudad..." << std::endl;
        }
    }
};

#endif // CIUDAD_H
