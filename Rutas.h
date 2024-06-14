//
// Created by Eddy Lucandy on 13/6/24.
//

#ifndef ACTV_GRUPAL_RUTAS_H
#define ACTV_GRUPAL_RUTAS_H

#include <iostream>
#include "Ciudad.h"
#include <vector>
#include <string>

using namespace std;


class Ruta {
    vector<string> pokemonsSalvajes;
    vector<string> objetosOcultos;
    vector<string> entrenadores;

public:
    void menuRutas() {
        cout << "Menu Ruta:\n";
        cout << "1. Explorar\n";
        cout << "2. Moverse\n";
    }
};

#endif //ACTV_GRUPAL_RUTAS_H
