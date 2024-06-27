#ifndef ENTRENADOR_H
#define ENTRENADOR_H

#include <string>
#include <vector>
#include "Pokemon.h"

// Enumeración para las ubicaciones en el mapa
enum class Ubicacion {
    Ruta,
    Pueblo,
    Ciudad,

};

class Entrenador {
private:
    int id;
    std::string nombre;
    Ubicacion ubicacion;
    std::vector<Pokemon> pokemons; // Lista de Pokémon (máximo 6)
    std::vector<std::string> mochila; // Lista de objetos en la mochila
    std::vector<std::string> medallas; // Lista de medallas (máximo 8)

public:
    // Constructor de Entrenador
    Entrenador(int id, const std::string &nombre, Ubicacion ubicacion)
            : id(id), nombre(nombre), ubicacion(ubicacion) {}

    // Métodos de acceso
    int getId() const { return id; }

    const std::string &getNombre() const { return nombre; }

    Ubicacion getUbicacion() const { return ubicacion; }

    // Métodos para manejar Pokémon
    bool agregarPokemon(const Pokemon &pokemon) {
        if (pokemons.size() < 6) {
            pokemons.push_back(pokemon);
            std::cout<<"Se agrego un pokemon a tu mochila" << std::endl;
            return true;
        } else {

            std::cout<< "Mochila llena. Ya tienes 6 pokemons" << std::endl;
            return false;
        }
    }

    void mostrarPokemons() const {
        for (const auto& pokemon : pokemons) {
            pokemon.mostrarInfo();
        }
    }

    // Métodos para manejar la mochila
    void agregarObjetoAMochila(const std::string& objeto) {
        mochila.push_back(objeto);
    }

    void mostrarMochila() const {
        std::cout << "Mochila del entrenador " << nombre << ":" << std::endl;
        for (const auto& objeto : mochila) {
            std::cout << objeto << std::endl;
        }
    }

    // Métodos para manejar medallas
    bool agregarMedalla(const std::string& medalla) {
        if (medallas.size() < 8) {
            medallas.push_back(medalla);
            return true;
        }
        return false;
    }

    void mostrarMedallas() const {
        std::cout << "Medallas del entrenador " << nombre << ":" << std::endl;
        for (const auto& medalla : medallas) {
            std::cout << medalla << std::endl;
        }
    }

    // Método para cambiar la ubicación
    void cambiarUbicacion(Ubicacion nuevaUbicacion) {
        ubicacion = nuevaUbicacion;
    }
};

#endif // ENTRENADOR_H
