//
// Created by Eddy Lucandy on 12/6/24.
//

#ifndef ACTV_GRUPAL_CIUDAD_H
#define ACTV_GRUPAL_CIUDAD_H

#pragma once
#include <iostream>
#include <string>
#include "Lista.h"

using namespace std;

class Ciudad {
private:
    Lista<std::string> viviendas;
    Lista<std::string> objetos;
    std::string gimnasio;
    std::string centroPokemon;
    std::string tienda;
    std::string nombre;

public:
    Ciudad() : nombre("") {}
    Ciudad(std::string nombre) : nombre(nombre) {}

    void agregarVivienda(const std::string& vivienda) {
        viviendas.insertar(viviendas.longitud() + 1, vivienda);
    }

    void agregarObjeto(const std::string& objeto) {
        objetos.insertar(objetos.longitud() + 1, objeto);
    }

    void establecerGimnasio(const std::string& gimnasio) {
        this->gimnasio = gimnasio;
    }

    void establecerCentroPokemon(const std::string& centroPokemon) {
        this->centroPokemon = centroPokemon;
    }

    void establecerTienda(const std::string& tienda) {
        this->tienda = tienda;
    }

    string getNombre() const {
        return nombre;
    }

    string toString() const {
        string info = "Ciudad: " + nombre + "\n";
        info += "Viviendas: " + viviendas.toString() + "\n";
        info += "Objetos: " + objetos.toString() + "\n";
        info += "Gimnasio: " + gimnasio + "\n";
        info += "Centro Pokemon: " + centroPokemon + "\n";
        info += "Tienda: " + tienda + "\n";
        return info;
    }
};

#endif //ACTV_GRUPAL_CIUDAD_H
