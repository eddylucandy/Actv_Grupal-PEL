//
// Created by Eddy Lucandy on 12/6/24.
//

#ifndef ACTV_GRUPAL_CIUDAD_H
#define ACTV_GRUPAL_CIUDAD_H

#pragma once
#include <iostream>
#include <string>
#include "Lista.h"
#include <cstdlib>
#include <ctime>

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

    void explorar() {
        std::cout << "Explorando la ciudad de " << nombre << "...\n";
        int opcion;
        do {
            std::cout << "1. Visitar una casa\n";
            std::cout << "2. Ir al gimnasio\n";
            std::cout << "3. Ir al centro Pokemon\n";
            std::cout << "4. Ir a la tienda\n";
            std::cout << "5. Salir\n";
            std::cout << "Seleccione una opción: ";
            std::cin >> opcion;

            switch (opcion) {
                case 1:
                    visitarCasa();
                    break;
                case 2:
                    std::cout << "Vas al " << gimnasio << ".\n";
                    break;
                case 3:
                    std::cout << "Vas al " << centroPokemon << ".\n";
                    break;
                case 4:
                    std::cout << "Vas a la " << tienda << ".\n";
                    break;
                case 5:
                    std::cout << "Saliendo de la exploración de la ciudad.\n";
                    break;
                default:
                    std::cout << "Opción no válida. Por favor, intenta de nuevo.\n";
                    break;
            }
        } while (opcion != 5);
    }

    void visitarCasa() {
        if (viviendas.esVacia()) {
            std::cout << "No hay más casas para visitar en esta ciudad.\n";
            return;
        }

        int casaIndex = rand() % viviendas.longitud() + 1;
        std::string casa = viviendas.consultar(casaIndex);
        std::cout << "Visitas " << casa << ".\n";

        viviendas.borrar(casaIndex);

        int evento = rand() % 3;
        switch (evento) {
            case 0:
                std::cout << "Encuentras un objeto en la casa.\n";
                break;
            case 1:
                std::cout << "Encuentras un NPC en la casa.\n";
                break;
            case 2:
                std::cout << "No encuentras nada interesante en la casa.\n";
                break;
            default:
                std::cout << "Continúas tu exploración.\n";
                break;
        }
    }
};

#endif //ACTV_GRUPAL_CIUDAD_H
