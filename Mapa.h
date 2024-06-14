//
// Created by Eddy Lucandy on 13/6/24.
//

#ifndef ACTV_GRUPAL_MAPA_H
#define ACTV_GRUPAL_MAPA_H

#include <iostream>
#include "Ciudad.h"
#include <vector>
#include <string>

using namespace std;

class Mapa {

    vector<Ciudad*> ciudades;
    vector<vector<bool>> conexiones; // Matriz de adyacencia

public:
    Mapa(int numCiudades) {
        conexiones.resize(numCiudades,
                          vector<bool>(numCiudades, false));
    }

    void conectarCiudades(int ciudad1, int ciudad2) {
        if (ciudad1 < conexiones.size() && ciudad2 < conexiones.size()) {
            conexiones[ciudad1][ciudad2] = true;
            conexiones[ciudad2][ciudad1] = true;
        }
    }

    void mostrarConexiones() {

        cout << "Mapa de conexiones:\n";
        for (int i = 0; i < conexiones.size(); i++) {
            for (int j = 0; j < conexiones[i].size(); j++) {

                cout << conexiones[i][j] << " ";
            }

            cout << "\n";
        }
    }
};


#endif //ACTV_GRUPAL_MAPA_H
