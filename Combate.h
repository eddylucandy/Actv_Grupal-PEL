#ifndef COMBATE_H
#define COMBATE_H

#include <iostream>
#include <vector>
#include "Entrenador.h"
#include "Pokemon.h"

class Combate {
private:
    Entrenador& jugador;
    Entrenador* rival; // Puntero a Entrenador para saber si se enfrenta a un entrenador
    Pokemon& pokemonJugador;
    Pokemon* pokemonRival; // Puntero a Pokémon del rival (si lo hay)

public:
    Combate(Entrenador& jugador, Pokemon& pokemonJugador)
            : jugador(jugador), rival(nullptr), pokemonJugador(pokemonJugador), pokemonRival(nullptr) {}

    Combate(Entrenador& jugador, Entrenador& rival, Pokemon& pokemonJugador, Pokemon& pokemonRival)
            : jugador(jugador), rival(&rival), pokemonJugador(pokemonJugador), pokemonRival(&pokemonRival) {}

    void mostrarMenu() {
        int opcion;
        do {
            std::cout << "1. Luchar" << std::endl;
            std::cout << "2. Mochila" << std::endl;
            std::cout << "3. Pokemon" << std::endl;
            if (!rival) { // Mostrar la opción de huir solo si no hay rival entrenador
                std::cout << "4. Huir" << std::endl;
            }
            std::cout << "5. Salir del juego" << std::endl;
            std::cout << "Seleccione una opcion: ";
            std::cin >> opcion;

            // Verificar si la entrada es válida
            if (std::cin.fail()) {
                std::cin.clear(); // Limpiar el estado de error
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descartar la entrada no válida
                opcion = -1; // Asignar una opción no válida
            }

            switch (opcion) {
                case 1:
                    luchar();
                    break;
                case 2:
                    mostrarMochila();
                    break;
                case 3:
                    mostrarPokemons();
                    break;
                case 4:
                    if (!rival) {
                        huir();
                    } else {
                        std::cout << "No puedes huir de una batalla contra un entrenador." << std::endl;
                    }
                    break;
                case 5:
                    std::cout << "Saliendo del juego..." << std::endl;
                    exit(0); // Termina el programa
                    break;
                default:
                    std::cout << "Opción no válida. Intente de nuevo." << std::endl;
                    break;
            }
        } while (true); // Repite el menú hasta que se seleccione salir del juego
    }

    void luchar() {
        std::cout << "¡Comienza el combate!" << std::endl;
        if (pokemonRival) {
            std::cout << pokemonJugador.getNombre() << " ataca a " << pokemonRival->getNombre() << std::endl;
            int danio = pokemonJugador.getAtaque() - pokemonRival->getDefensa();
            if (danio < 0) danio = 0;
            pokemonRival->recibirDanio(danio);
            std::cout << pokemonRival->getNombre() << " recibe " << danio << " puntos de daño." << std::endl;
        } else {
            std::cout << "No hay rival para luchar." << std::endl;
        }
    }

    void mostrarMochila() {
        std::cout << "Contenido de la mochila:" << std::endl;
        jugador.mostrarMochila();
    }

    void mostrarPokemons() {
        std::cout << "Pokemons del entrenador:" << std::endl;
        jugador.mostrarPokemons();
    }

    void huir() {
        std::cout << "¡Has huido del combate!" << std::endl;
        // Aquí puedes agregar la lógica para lo que sucede después de huir
    }
};

#endif // COMBATE_H
