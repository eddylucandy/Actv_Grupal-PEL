#include "Juego.h"
#include "Ciudad.h"

void Juego::iniciarJuego() {
    std::string nombreJugador;
    std::cout << "Iniciando partida..." << std::endl;
    std::cout << "Ingrese el nombre del jugador (sin espacios): ";
    std::cin >> nombreJugador;
    jugador = Jugador(nombreJugador);
    std::cout << "Iniciando partida nueva para el jugador " << nombreJugador << "..." << std::endl;
    seleccionarPokemonInicial();
    viajar();
}

void Juego::seleccionarPokemonInicial() {
    std::cout << "Seleccione su Pokemon inicial:" << std::endl;
    std::cout << "1. Charmander (Fuego)" << std::endl;
    std::cout << "2. Squirtle (Agua)" << std::endl;
    std::cout << "3. Bulbasaur (Tierra)" << std::endl;
    std::cout << "Seleccione una opcion: ";
    int opcion;
    std::cin >> opcion;

    if (opcion == 1) {
        jugador.agregarPokemon(Pokemon("Charmander", "Fuego", 5, 100, 52, 43));
    } else if (opcion == 2) {
        jugador.agregarPokemon(Pokemon("Squirtle", "Agua", 5, 100, 48, 65));
    } else if (opcion == 3) {
        jugador.agregarPokemon(Pokemon("Bulbasaur", "Tierra", 5, 100, 49, 49));
    } else {
        std::cout << "Opcion no valida. Se seleccionara Bulbasaur por defecto." << std::endl;
        jugador.agregarPokemon(Pokemon("Bulbasaur", "Tierra", 5, 100, 49, 49));
    }
}
void Juego::viajar() {
    // Simulamos la exploración de la primera ruta
    while (medallasRecolectadas < 8) {
        explorarRuta();
    }

    std::cout << "¡Felicidades! Has recolectado todas las medallas. ¡Has ganado el juego!" << std::endl;
}
void Juego::explorarRuta() {
    std::cout << "\nExplorando ruta..." << std::endl;
    // Simulamos un encuentro aleatorio en la ruta
    int encuentro = rand() % 3; // 0: Entrenador, 1: Pokémon salvaje, 2: Objeto

    switch (encuentro) {
        case 0: {
            std::cout << "Te encuentras con un entrenador en la ruta. ¿Que deseas hacer?" << std::endl;
            std::cout << "1. Pelear" << std::endl;
            std::cout << "2. Usar objeto" << std::endl;
            std::cout << "3. Escapar" << std::endl;
            std::cout << "Seleccione una opción: ";
            int opcion;
            std::cin >> opcion;


            switch (opcion) {
                case 1:
                    // Lógica para la batalla con el entrenador
                    std::cout << "¡Has peleado con el entrenador!" << std::endl;
                    // Simulación de ganar la medalla
                    recolectarMedalla();
                    break;
                case 2:
                    std::cout << "Usaste un objeto para ayudarte en tu camino." << std::endl;
                    // Lógica para usar un objeto (puede ser curación, mejora de estado, etc.)
                    break;
                case 3:
                    std::cout << "Escapaste del entrenador y continuaste tu viaje." << std::endl;
                    // Lógica para escapar (podrías simplemente continuar la exploración)
                    break;
                default:
                    std::cout << "Opcion no válida. No hiciste nada y continuaste tu camino." << std::endl;
                    break;
            }
            break;
        }
        case 1:
            std::cout << "Te encuentras con un Pokemon salvaje. ¡Preparate para la batalla!" << std::endl;
            // Lógica para la batalla con el Pokémon salvaje (simulación)
            break;
        case 2:
            std::cout << "Encuentras un objeto util en tu camino." << std::endl;
            // Lógica para el uso del objeto encontrado (simulación)
            break;
        default:
            std::cout << "No encuentras nada especial en tu ruta." << std::endl;
            break;
    }

    // Después de la ruta, decidir automáticamente ir a una ciudad o pueblo
    if (rand() % 2 == 0) { // Simulamos una decisión aleatoria
        Ciudad ciudad("Ciudad");
        ciudad.explorarCiudad(jugador); // Aquí podrías manejar la lógica de la ciudad
    } else {
        Pueblo pueblo("Pueblo");
        pueblo.explorarPueblo(jugador); // Aquí podrías manejar la lógica del pueblo
    }
}

void Juego::recolectarMedalla() {
    medallasRecolectadas++;
    std::cout << "¡Has recolectado una medalla! Total de medallas: " << medallasRecolectadas << std::endl;
}



int main() {
    std::cout << "Bienvenido a Pokemon Gamer" << std::endl;
    std::cout << "1. Partida Nueva" << std::endl;
    std::cout << "2. Salir" << std::endl;
    std::cout << "Seleccione una opcion: ";

    int opcion;
    std::cin >> opcion;

    if (opcion == 1) {
        Juego juego;
        juego.iniciarJuego();
    } else {
        std::cout << "Saliendo del juego..." << std::endl;
    }

    return 0;

}
