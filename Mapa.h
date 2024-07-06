//
// Created by Eddy Lucandy on 13/6/24.
//

#ifndef ACTV_GRUPAL_MAPA_H
#define ACTV_GRUPAL_MAPA_H

#pragma once
#include "Ciudad.h"
#include "Grafo.h"
#include "Lista.h"
#include "Par.h"
#include "Rutas.h"
#include <memory>
#include <iostream>
#include <ctime>

class Mapa {
private:
    Grafo<std::string, std::shared_ptr<void>, int> grafo;
    std::string posicionActual;
    bool juegoContinua;

public:
    Mapa() : juegoContinua(true) {
        std::srand(static_cast<unsigned int>(std::time(nullptr))); // Inicializa el generador de números aleatorios
        std::cout << "Mapa creado\n";
    }
/*
    ~Mapa() {
        std::cout << "Mapa destruido\n";
    }*/

    bool verificarGrafo() const {
        string c;
        if (!grafo.esVacio()) {
            Lista<string> vertices = grafo.listaVertices();  // Obtiene la lista de vértices una vez
            for (int i = 1; i <= vertices.longitud(); i++) {  // Usa '<=' para asegurar la iteración correcta
                cout << vertices.consultar(i) << endl;  // Imprime cada vértice
                cout << "si existe";
            }
        } else {
            cout << "El grafo está vacío." << endl;
        }

        Lista<std::string> vertices = grafo.listaVertices();
        for (int i = 1; i <= vertices.longitud(); ++i) {
            std::string vertice = vertices.consultar(i);
            if (!grafo.existeVertice(vertice)) {
                std::cout << "Error: El vértice " << vertice << " no existe en el grafo." << std::endl;
                return false;
            }

            Lista<std::string> sucesores = grafo.listaSucesores(vertice);
            for (int j = 1; j <= sucesores.longitud(); ++j) {
                std::string sucesor = sucesores.consultar(j);
                if (!grafo.existeVertice(sucesor)) {
                    std::cout << "Error: El sucesor " << sucesor << " de " << vertice << " no existe en el grafo." << std::endl;
                    return false;
                }
            }
        }
        std::cout << "El grafo fue creado correctamente." << std::endl;
        return true;
    }

    bool grafoEstaVacio() const {
        return grafo.esVacio();
    }


    void inicializarMapa() {
        std::cout << "Inicializando mapa...\n";
        auto P1 = std::make_shared<Ciudad>("Ciudad1");
        auto P2 = std::make_shared<Ciudad>("Ciudad2");
        auto P3 = std::make_shared<Ciudad>("Ciudad3");
        auto P4 = std::make_shared<Ciudad>("Ciudad4");
        auto P5 = std::make_shared<Ciudad>("Ciudad5");
        auto P6 = std::make_shared<Ciudad>("Ciudad6");
        auto P7 = std::make_shared<Ciudad>("Ciudad7");
        auto P8 = std::make_shared<Ciudad>("Ciudad8");
        auto P9 = std::make_shared<Ciudad>("Ciudad9");
        auto P10 = std::make_shared<Ciudad>("Ciudad10");
        auto P11 = std::make_shared<Ciudad>("Ciudad11");
        auto P12 = std::make_shared<Ciudad>("Ciudad12");

        auto R1 = std::make_shared<Ruta>("Ruta1");
        auto R2 = std::make_shared<Ruta>("Ruta2");
        auto R3 = std::make_shared<Ruta>("Ruta3");
        auto R4 = std::make_shared<Ruta>("Ruta4");
        auto R5 = std::make_shared<Ruta>("Ruta5");
        auto R6 = std::make_shared<Ruta>("Ruta6");
        auto R7 = std::make_shared<Ruta>("Ruta7");
        auto R8 = std::make_shared<Ruta>("Ruta8");
        auto R9 = std::make_shared<Ruta>("Ruta9");
        auto R10 = std::make_shared<Ruta>("Ruta10");
        auto R11 = std::make_shared<Ruta>("Ruta11");
        auto R12 = std::make_shared<Ruta>("Ruta12");
        auto R13 = std::make_shared<Ruta>("Ruta13");

        grafo.insertarVertice("P1", P1);
        grafo.insertarVertice("P2", P2);
        grafo.insertarVertice("P3", P3);
        grafo.insertarVertice("P4", P4);
        grafo.insertarVertice("P5", P5);
        grafo.insertarVertice("P6", P6);
        grafo.insertarVertice("P7", P7);
        grafo.insertarVertice("P8", P8);
        grafo.insertarVertice("P9", P9);
        grafo.insertarVertice("P10", P10);
        grafo.insertarVertice("P11", P11);
        grafo.insertarVertice("P12", P12);

        grafo.insertarVertice("R1", R1);
        grafo.insertarVertice("R2", R2);
        grafo.insertarVertice("R3", R3);
        grafo.insertarVertice("R4", R4);
        grafo.insertarVertice("R5", R5);
        grafo.insertarVertice("R6", R6);
        grafo.insertarVertice("R7", R7);
        grafo.insertarVertice("R8", R8);
        grafo.insertarVertice("R9", R9);
        grafo.insertarVertice("R10", R10);
        grafo.insertarVertice("R11", R11);
        grafo.insertarVertice("R12", R12);
        grafo.insertarVertice("R13", R13);

        grafo.insertarArista("P1", "R1", 1);
        grafo.insertarArista("R1", "P12", 2);
        grafo.insertarArista("P12", "R2", 3);
        grafo.insertarArista("R2", "P11", 4);
        grafo.insertarArista("P1", "R3", 5);
        grafo.insertarArista("R3", "P2", 6);
        grafo.insertarArista("P2", "R4", 7);
        grafo.insertarArista("R4", "P3", 8);
        grafo.insertarArista("P3", "R5", 9);
        grafo.insertarArista("R5", "P4", 10);
        grafo.insertarArista("P4", "R6", 11);
        grafo.insertarArista("R6", "P5", 12);
        grafo.insertarArista("P4", "R7", 13);
        grafo.insertarArista("R7", "P6", 14);
        grafo.insertarArista("P5", "R8", 15);
        grafo.insertarArista("R8", "P7", 16);
        grafo.insertarArista("P6", "R9", 17);
        grafo.insertarArista("R9", "P8", 18);
        grafo.insertarArista("P7", "R10", 19);
        grafo.insertarArista("R10", "P8", 20);
        grafo.insertarArista("P8", "R11", 21);
        grafo.insertarArista("R11", "P9", 22);
        grafo.insertarArista("P9", "R12", 23);
        grafo.insertarArista("R12", "P10", 24);
        grafo.insertarArista("P10", "R13", 25);
        grafo.insertarArista("R13", "P11", 26);

        std::cout << grafo.toString() << std::endl;

        posicionActual = "P1";

        // Verificar si el grafo fue bien creado
        if (!verificarGrafo()) {
            std::cerr << "Error al crear el grafo." << std::endl;
            return;
        }

        // Verificar si el grafo está vacío
        if (grafoEstaVacio()) {
            std::cerr << "El grafo está vacío." << std::endl;
            return;
        }
    }


    void menuCiudad() {
        int opcion;
        std::cout << "Menu de la Ciudad:\n";
        std::cout << "1. Donde estoy\n";
        std::cout << "2. Moverse\n";
        std::cout << "3. Mochila\n";
        std::cout << "4. Equipo\n";
        std::cout << "5. Información\n";
        std::cout << "6. Explorar Ciudad\n";
        std::cout << "7. Abandonar el juego\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                std::cout << "Estás en " << posicionActual << ".\n";
                break;
            case 2:
                moverse();
                break;
            case 3:
                std::cout << "Abriendo la mochila...\n";
                break;
            case 4:
                std::cout << "Mostrando el equipo Pokémon.\n";
                break;
            case 5:
                mostrarInformacion();
                break;
            case 6:
                explorarCiudad();
                break;
            case 7:
                std::cout << "¿Estás seguro de que quieres abandonar el juego? (s/n): ";
                char respuesta;
                std::cin >> respuesta;
                if (respuesta == 's' || respuesta == 'S') {
                    juegoContinua = false;
                }
                break;
            default:
                std::cout << "Opción no válida. Por favor, intenta de nuevo.\n";
                break;
        }
    }

    void explorarCiudad() {
        auto vertice = grafo.consultarVertice(posicionActual);
        auto ciudad = std::static_pointer_cast<Ciudad>(vertice);
        ciudad->explorar();
    }

    void menuRuta() {
        int opcion;
        std::cout << "Menu de la Ruta:\n";
        std::cout << "1. Explorar\n";
        std::cout << "2. Moverse\n";
        std::cout << "3. Abandonar el juego\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                explorarRuta();
                break;
            case 2:
                moverse();
                break;
            case 3:
                std::cout << "¿Estás seguro de que quieres abandonar el juego? (s/n): ";
                char respuesta;
                std::cin >> respuesta;
                if (respuesta == 's' || respuesta == 'S') {
                    juegoContinua = false;
                }
                break;
            default:
                std::cout << "Opción no válida. Por favor, intenta de nuevo.\n";
                break;
        }
    }


    void mostrarMovimientosPosibles() const {
        Lista<std::string> destinos = grafo.listaSucesores(posicionActual);
       /* if (destinos.longitud() == 0) {
            std::cout << "No hay destinos disponibles desde aquí." << std::endl;
            return;
        }*/

        std::cout << "Destinos disponibles:\n";
        for (int i = 1; i <= destinos.longitud(); ++i) {
            std::cout << destinos.consultar(i) << "\n";
        }
    }




    void moverse() {
        while (true) {
            mostrarMovimientosPosibles();
            Lista<std::string> destinos = grafo.listaSucesores(posicionActual);

            /*if (destinos.longitud() == 0) {
                return;
            }*/

            std::cout << "Selecciona la dirección a la que deseas moverte (por clave): ";
            std::string clave;
            std::cin >> clave;

            bool destinoValido = false;
            for (int i = 1; i <= destinos.longitud(); ++i) {
                if (destinos.consultar(i) == clave) {
                    destinoValido = true;
                    break;
                }
            }

            if (destinoValido) {
                if (esRuta(clave)) {
                    posicionActual = clave;
                    menuRuta();
                } else {
                    posicionActual = clave;
                    menuCiudad();
                }
                std::cout << "Has llegado a " << posicionActual << ".\n";
                break;
            } else {
                std::cout << "Opción no válida. Por favor, intenta de nuevo.\n";
            }
        }
    }



    void explorarRuta() {
        std::cout << "Explorando la ruta...\n";
        int encuentro = rand() % 3;

        switch (encuentro) {
            case 0:
                encuentroPokemon();
                break;
            case 1:
                encuentroEntrenador();
                break;
            case 2:
                encuentroObjeto();
                break;
            default:
                std::cout << "Sigues tu camino sin incidentes.\n";
                break;
        }
    }

    void encuentroPokemon() {
        std::cout << "¡Encontraste un Pokémon salvaje! ¿Quieres pelear o huir?\n";
        std::cout << "1. Pelear\n";
        std::cout << "2. Huir\n";
        int eleccion;
        std::cin >> eleccion;
        if (eleccion == 1) {
            std::cout << "¡Comienzas la batalla Pokémon!\n";
        } else if (eleccion == 2) {
            std::cout << "Decides huir. Continuas tu viaje.\n";
        } else {
            std::cout << "Opción no válida. Por favor, intenta de nuevo.\n";
        }
    }

    void encuentroEntrenador() {
        std::cout << "¡Encontraste un entrenador Pokémon dispuesto a luchar! ¿Quieres pelear o huir?\n";
        std::cout << "1. Pelear\n";
        std::cout << "2. Huir\n";
        int eleccion;
        std::cin >> eleccion;
        if (eleccion == 1) {
            std::cout << "¡El combate comienza!\n";
        } else if (eleccion == 2) {
            std::cout << "Decides huir. Sigues tu camino.\n";
        } else {
            std::cout << "Opción no válida. Por favor, intenta de nuevo.\n";
        }
    }

    void encuentroObjeto() {
        std::cout << "¡Has encontrado un objeto en el camino! ¿Quieres cogerlo o dejarlo?\n";
        std::cout << "1. Cogerlo\n";
        std::cout << "2. Dejarlo\n";
        int eleccion;
        std::cin >> eleccion;
        if (eleccion == 1) {
            std::cout << "Tomas el objeto y lo guardas en tu mochila.\n";
        } else if (eleccion == 2) {
            std::cout << "Decides dejarlo donde está y continuar tu aventura.\n";
        } else {
            std::cout << "Opción no válida. Por favor, intenta de nuevo.\n";
        }
    }

    void mostrarInformacion() {
        auto vertice = grafo.consultarVertice(posicionActual);
        if (esCiudad(posicionActual)) {
            auto ciudad = std::static_pointer_cast<Ciudad>(vertice);
            std::cout << ciudad->toString() << "\n";
        } else {
            auto ruta = std::static_pointer_cast<Ruta>(vertice);
            std::cout << ruta->toString() << "\n";
        }
    }

    void ejecutar() {
        inicializarMapa();
        while (juegoContinua) {
            if (esCiudad(posicionActual)) {
                std::cout << "\nTe encuentras en " << posicionActual << ".\n";
                menuCiudad();
            } else if (esRuta(posicionActual)) {
                std::cout << "\nEstás en " << posicionActual << ".\n";
                menuRuta();
            } else {
                std::cout << "Error: Posición actual no válida.\n";
                break;
            }

            if (posicionActual == "P11") {
                std::cout << "¡Felicidades! Has llegado a la última ciudad.\n";
                std::cout << "¿Quieres continuar jugando? (s/n): ";
                char respuesta;
                std::cin >> respuesta;
                if (respuesta != 's' && respuesta != 'S') {
                    juegoContinua = false;
                }
            }
        }
        std::cout << "Gracias por jugar. ¡Hasta la próxima!\n";
    }

    bool esCiudad(const std::string& nombre) {
        return nombre[0] == 'P' && std::isdigit(nombre[1]);
    }

    bool esRuta(const std::string& nombre) {
        return nombre[0] == 'R' && std::isdigit(nombre[1]);
    }
};

#endif //ACTV_GRUPAL_MAPA_H

