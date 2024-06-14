//
// Created by Eddy Lucandy on 12/6/24.
//

#ifndef ACTV_GRUPAL_CIUDAD_H
#define ACTV_GRUPAL_CIUDAD_H


#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Definición de la clase Ciudad
class Ciudad {
protected:
    
    vector<string> viviendas; // Lista de viviendas

    vector<string> objetos;   // Lista de objetos disponibles en la ciudad

    string gimnasio;

    string centroPokemon;

    string tienda;

public:
    Ciudad(int numeroDeCasas) {
        for (int i = 0; i < numeroDeCasas; ++i) {
            viviendas.push_back("Casa " + to_string(i + 1));
        }
    }

    virtual void menuCiudad() {
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
