//
// Created by Eddy Lucandy on 12/6/24.
//

#ifndef ACTV_GRUPAL_CIUDAD_H
#define ACTV_GRUPAL_CIUDAD_H

#include <iostream>
#include <vector>
#include <string>

// Definición de la clase Ciudad
class Ciudad {
protected:
    std::vector<std::string> viviendas; // Lista de viviendas
    std::vector<std::string> objetos;   // Lista de objetos disponibles en la ciudad
    std::string gimnasio;
    std::string centroPokemon;
    std::string tienda;

public:
    Ciudad(int numeroDeCasas) {
        for (int i = 0; i < numeroDeCasas; ++i) {
            viviendas.push_back("Casa " + std::to_string(i + 1));
        }
    }

    virtual void menu() {
        std::cout << "Donde estoy\n";
        std::cout << "Moverse\n";
        std::cout << "Mochila\n";
        std::cout << "Equipo\n";
        std::cout << "Información\n";
    }
};

// Subclase Pueblo, que hereda de Ciudad
class Pueblo : public Ciudad {
public:
    Pueblo() : Ciudad(3) {} // Los pueblos tienen 3 casas
};

// Subclase CiudadGrande, que hereda de Ciudad
class CiudadGrande : public Ciudad {
public:
    CiudadGrande() : Ciudad(5) {} // Las ciudades grandes tienen 5 casas
};

#endif //ACTV_GRUPAL_CIUDAD_H
