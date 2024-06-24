//
// Created by Eddy Lucandy on 13/6/24.
//

#ifndef ACTV_GRUPAL_RUTAS_H
#define ACTV_GRUPAL_RUTAS_H

#include <iostream>
#include <string>
#include "Par.h"
#include "Lista.h"
#pragma once

using namespace std;


class Ruta {
private:
    Lista<std::string> pokemonsSalvajes;
    Lista<std::string> objetosOcultos;
    Lista<std::string> entrenadores;
    string nombre;

public:
    Ruta() : nombre("") {}
    Ruta(std::string nombre) : nombre(nombre) {}


    void agregarPokemonSalvaje(const std::string& pokemon) {
        pokemonsSalvajes.insertar(pokemonsSalvajes.longitud() + 1, pokemon);
    }

    void agregarObjetoOculto(const std::string& objeto) {
        objetosOcultos.insertar(objetosOcultos.longitud() + 1, objeto);
    }

    void agregarEntrenador(const std::string& entrenador) {
        entrenadores.insertar(entrenadores.longitud() + 1, entrenador);
    }

    string getNombre() const {
        return nombre;
    }

    std::string toString() const {
        std::string info = "Ruta: " + nombre + "\n";
        info += "Pokemons Salvajes: " + pokemonsSalvajes.toString() + "\n";
        info += "Objetos Ocultos: " + objetosOcultos.toString() + "\n";
        info += "Entrenadores: " + entrenadores.toString() + "\n";
        return info;
    }

    void menuRuta() const {
        int opcion;
        cout << "Menu de la Ruta:\n";
        cout << "1. Explorar\n";
        cout << "2. Moverse\n";
        cout << "3. Abandonar el juego\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Explorando XXX...\n";
                break;
            case 2:
                cout << "Moviendose.\n";
                // Aquí se podría implementar una función adicional para manejar la navegación
                break;
            case 3:
                cout << "Abandonando el juego...\n";
                exit(0); // Termina la ejecución del programa
                break;
            default:
                cout << "Opción no válida. Por favor, intenta de nuevo.\n";
                break;
        }
    }
};

#endif //ACTV_GRUPAL_RUTAS_H
