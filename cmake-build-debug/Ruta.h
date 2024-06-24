//
// Created by Eddy Lucandy on 12/6/24.
//

#ifndef ACTV_GRUPAL_RUTA_H
#define ACTV_GRUPAL_RUTA_H


#include <iostream>
#include <vector>
#include <string>


class Ruta {
    std::vector<std::string> pokemonsSalvajes;
    std::vector<std::string> objetosOcultos;
    std::vector<std::string> entrenadores;

public:
    void menu() {
        std::cout << "Explorar\n";
        std::cout << "Moverse\n";
    }
};



#endif //ACTV_GRUPAL_RUTA_H
