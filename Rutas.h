//
// Created by Eddy Lucandy on 13/6/24.
//

#ifndef ACTV_GRUPAL_RUTAS_H
#define ACTV_GRUPAL_RUTAS_H

#include <iostream>
#include <string>
#include "Par.h"
#include "Lista.h"

using namespace std;


class Ruta {
private:
    Lista<std::string> pokemonsSalvajes;
    Lista<std::string> objetosOcultos;
    Lista<std::string> entrenadores;

public:
    void agregarPokemonSalvaje(const std::string& pokemon) {
        pokemonsSalvajes.insertar(pokemonsSalvajes.longitud() + 1, pokemon);
    }

    void agregarObjetoOculto(const std::string& objeto) {
        objetosOcultos.insertar(objetosOcultos.longitud() + 1, objeto);
    }

    void agregarEntrenador(const std::string& entrenador) {
        entrenadores.insertar(entrenadores.longitud() + 1, entrenador);
    }

    void menuRuta() const {
        std::cout << "Menu de la Ruta:\n";
        std::cout << "1. Explorar\n";
        std::cout << "2. Moverse\n";
    }
};

#endif //ACTV_GRUPAL_RUTAS_H
