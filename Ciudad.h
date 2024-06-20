//
// Created by Eddy Lucandy on 12/6/24.
//

#ifndef ACTV_GRUPAL_CIUDAD_H
#define ACTV_GRUPAL_CIUDAD_H


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

        void menuCiudad() {
            int opcion;
            cout << "Menu de la Ciudad:\n";
            cout << "1. Donde estoy\n";
            cout << "2. Moverse\n";
            cout << "3. Mochila\n";
            cout << "4. Equipo\n";
            cout << "5. Información\n";
            cout << "6. Abandonar el juego\n";
            cout << "Seleccione una opción: ";
            cin >> opcion;

            switch (opcion) {
                case 1:
                    cout << "Estás en la ciudad XXX.\n";
                    break;
                case 2:
                    cout << "Selecciona la dirección a la que deseas moverte.\n";
                    // Aquí se podría implementar una función adicional para manejar la navegación
                    break;
                case 3:
                    cout << "Abriendo la mochila...\n";
                    // Lógica para mostrar o manipular el contenido de la mochila
                    break;
                case 4:
                    cout << "Mostrando el equipo Pokémon.\n";
                    // Lógica para mostrar o cambiar el equipo Pokémon
                    break;
                case 5:
                    cout << "Información de la ciudad y consejos útiles.\n";
                    // Proporcionar información relevante sobre la ciudad
                    break;
                case 6:
                    cout << "Abandonando el juego...\n";
                    exit(0); // Termina la ejecución del programa
                    break;
                default:
                    cout << "Opción no válida. Por favor, intenta de nuevo.\n";
                    break;
            }
        }


        std::string getNombre() const {
            return nombre;
        }
};

#endif //ACTV_GRUPAL_CIUDAD_H
