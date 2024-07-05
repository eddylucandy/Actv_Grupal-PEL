//
// Created by MAYLEN on 5/07/2024.
//

#ifndef ACTV_GRUPAL_MOCHILA_H
#define ACTV_GRUPAL_MOCHILA_H
#include <iostream>
#include <vector>
#include <algorithm> // Para std::find
#include <string>

class Mochila {
private:
    // Vector para almacenar los objetos de la mochila
    std::vector<std::string> contenido;

public:
    // Constructor por defecto que inicializa una mochila vacía
    Mochila() {
        // El vector 'contenido' se inicializa automáticamente como vacío
    }

    // Método para agregar un objeto a la mochila
    void agregar(const std::string& objeto) {
        contenido.push_back(objeto);
        std::cout << objeto << " ha sido agregado a la mochila." << std::endl;
    }

    // Método para eliminar un objeto de la mochila
    void eliminar(const std::string& objeto) {
        // Buscar el objeto en el vector
        auto it = std::find(contenido.begin(), contenido.end(), objeto);
        if (it != contenido.end()) {
            // Si el objeto se encuentra, eliminarlo
            contenido.erase(it);
            std::cout << objeto << " ha sido eliminado de la mochila." << std::endl;
        } else {
            // Si el objeto no se encuentra, informar al usuario
            std::cout << objeto << " no está en la mochila." << std::endl;
        }
    }

    // Método para mostrar el contenido de la mochila
    void mostrarContenido() const {
        if (contenido.empty()) {
            std::cout << "La mochila está vacía." << std::endl;
        } else {
            std::cout << "La mochila contiene:" << std::endl;
            for (const auto& obj : contenido) {
                std::cout << "- " << obj << std::endl;
            }
        }
    }
};

// Función principal para demostrar el uso de la clase Mochila
int main() {
    // Crear una instancia de Mochila
    Mochila mochila;

    // Agregar objetos a la mochila
    mochila.agregar("Poción");
    mochila.agregar("Poké Ball");

    // Mostrar el contenido de la mochila
    mochila.mostrarContenido();

    // Eliminar un objeto de la mochila
    mochila.eliminar("Poción");

    // Mostrar el contenido de la mochila nuevamente
    mochila.mostrarContenido();

    return 0;
}

#endif //ACTV_GRUPAL_MOCHILA_H
