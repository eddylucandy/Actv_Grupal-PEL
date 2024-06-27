//#include <mysql.h>
#include "Pokemon.h"
#include "Juego.h"
#include "Jugador.h"
#include <vector>
#include <cstdlib> // Para funciones rand() y srand()
#include <ctime>   // Para la semilla srand()


/*
// Definición de la lista de los primeros 20 Pokémon de la primera generación
const std::vector<PokemonBase> primeros20Pokemon {
        {"Bulbasaur", TipoPokemon::Planta, 5, 100, 50, 50, {{"Placaje", 40}, {"Hoja Afilada", 55}}},
        {"Ivysaur", TipoPokemon::Planta, 5, 100, 50, 50, {{"Placaje", 40}, {"Hoja Afilada", 55}}},
        {"Venusaur", TipoPokemon::Planta, 5, 100, 50, 50, {{"Placaje", 40}, {"Hoja Afilada", 55}}},
        {"Charmander", TipoPokemon::Fuego, 5, 100, 50, 50, {{"Ascuas", 40}, {"Lanzallamas", 55}}},
        {"Charmeleon", TipoPokemon::Fuego, 5, 100, 50, 50, {{"Ascuas", 40}, {"Lanzallamas", 55}}},
        {"Charizard", TipoPokemon::Fuego, 5, 100, 50, 50, {{"Ascuas", 40}, {"Lanzallamas", 55}}},
        {"Squirtle", TipoPokemon::Agua, 5, 100, 50, 50, {{"Pistola Agua", 40}, {"Hidrobomba", 55}}},
        {"Wartortle", TipoPokemon::Agua, 5, 100, 50, 50, {{"Pistola Agua", 40}, {"Hidrobomba", 55}}},
        {"Blastoise", TipoPokemon::Agua, 5, 100, 50, 50, {{"Pistola Agua", 40}, {"Hidrobomba", 55}}},
        {"Pikachu", TipoPokemon::Electrico, 5, 100, 50, 50, {{"Impactrueno", 40}, {"Rayo", 55}}},
        {"Raichu", TipoPokemon::Electrico, 5, 100, 50, 50, {{"Impactrueno", 40}, {"Rayo", 55}}},
        // Agrega los demás Pokémon hasta completar los primeros 20
};

// Implementación de la función atacar
void Pokemon::atacar(Pokemon& rival, int indiceAtaque) {
    if (indiceAtaque < 0 || indiceAtaque >= ataques.size()) {
        std::cout << "Indice de ataque invalido." << std::endl;
        return;
    }

    auto it = ataques.begin();
    std::advance(it, indiceAtaque);
    std::string nombreAtaque = it->first;
    int potencia = it->second;

    // Simulación de la efectividad del ataque según el tipo
    if (tipo == TipoPokemon::Planta && rival.getTipo() == TipoPokemon::Agua) {
        potencia *= 2; // Ataque súper efectivo contra Agua
    } else if (tipo == TipoPokemon::Fuego && rival.getTipo() == TipoPokemon::Planta) {
        potencia *= 2; // Ataque súper efectivo contra Planta
    } else if (tipo == TipoPokemon::Agua && rival.getTipo() == TipoPokemon::Fuego) {
        potencia *= 2; // Ataque súper efectivo contra Fuego
    } // Agrega más tipos y efectividades según sea necesario

    // Aplicación del daño al rival
    rival.recibirDanio(potencia);

    std::cout << nombre << " uso " << nombreAtaque << " contra " << rival.getNombre() << "!" << std::endl;
    std::cout << "El ataque infligio " << potencia << " puntos de daño." << std::endl;

    if (rival.getSalud() <= 0) {
        std::cout << rival.getNombre() << " ha sido derrotado." << std::endl;
    }
}

// Definición de la función tipoPokemonToString
std::string tipoPokemonToString(TipoPokemon tipo) {
    switch (tipo) {
        case TipoPokemon::Planta:
            return "Planta";
        case TipoPokemon::Fuego:
            return "Fuego";
        case TipoPokemon::Agua:
            return "Agua";
        case TipoPokemon::Electrico:
            return "Eléctrico";
        case TipoPokemon::Tierra:
            return "Tierra";
        case TipoPokemon::Normal:
            return "Normal";
        default:
            return "Desconocido";
    }
}
void Pokemon::mostrarInfo() const {
    std::cout << "Nombre: " << nombre << ", Tipo: " << tipoPokemonToString(tipo) << ", Nivel: " << nivel
              << ", Salud: " << salud << ", Ataque: " << ataque << ", Defensa: " << defensa << std::endl;
}

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
    std::cout << "Seleccione su Pokémon inicial:" << std::endl;
    std::cout << "1. Bulbasaur (Planta)" << std::endl;
    std::cout << "2. Charmander (Fuego)" << std::endl;
    std::cout << "3. Squirtle (Agua)" << std::endl;
    std::cout << "Seleccione una opción: ";
    int opcion;
    std::cin >> opcion;


    switch (opcion) {
        case 1:
            jugador.agregarPokemon(Pokemon(primeros20Pokemon[0], 5, 100)); // Crear Bulbasaur
            break;
        case 2:
            jugador.agregarPokemon(Pokemon(primeros20Pokemon[3], 5, 100)); // Crear Charmander
            break;
        case 3:
            jugador.agregarPokemon(Pokemon(primeros20Pokemon[6], 5, 100)); // Crear Squirtle
            break;
        default:
            std::cout << "Opción no válida. Se seleccionará Bulbasaur por defecto." << std::endl;
            jugador.agregarPokemon(Pokemon(primeros20Pokemon[0], 5, 100)); // Crear Bulbasaur por defecto
            break;
    }
}


void Juego::viajar() {
    while (medallasRecolectadas < 8) {
        explorarRuta();
    }

    std::cout << "¡Felicidades! Has recolectado todas las medallas. ¡Has ganado el juego!" << std::endl;
}

void Juego::explorarRuta() {
    std::cout << "\nExplorando ruta..." << std::endl;
    int encuentro = rand() % 3; // 0: Entrenador, 1: Pokémon salvaje, 2: Objeto

    switch (encuentro) {
        case 0: {
            std::cout << "Te encuentras con un entrenador en la ruta. ¡Preparate para la batalla!" << std::endl;

            // Aquí deberías seleccionar un Pokémon rival aleatorio de primeros20Pokemon
            int indicePokemon = rand() % primeros20Pokemon.size();
            const PokemonBase& base = primeros20Pokemon[indicePokemon];

            // Crear un Pokémon rival utilizando el constructor que acepta PokemonBase
            Pokemon rival(base);

            jugador.pelearConEntrenador(rival);
            break;
        }
        case 1:
            std::cout << "Te encuentras con un Pokémon salvaje. ¡Preparate para la batalla!" << std::endl;
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
void Jugador::pelearConEntrenador(Pokemon& rival) {
    if (pokemons.empty()) {
        std::cout << "No tienes ningún Pokémon en tu equipo para pelear." << std::endl;
        return;
    }

    std::cout << "Selecciona tu Pokémon para la batalla:" << std::endl;
    for (size_t i = 0; i < pokemons.size(); ++i) {
        std::cout << i + 1 << ". " << pokemons[i].getNombre() << " (" << tipoPokemonToString(pokemons[i].getTipo()) << ")" << std::endl;
    }

    int opcion;
    std::cin >> opcion;
    opcion--; // Ajustamos la opción al índice del vector

    if (opcion < 0 || opcion >= pokemons.size()) {
        std::cout << "Opción no válida." << std::endl;
        return;
    }

    Pokemon& miPokemon = pokemons[opcion];
    std::cout << "¡Preparando batalla!" << std::endl;
    std::cout << "Tu oponente es: " << rival.getNombre() << " (" << tipoPokemonToString(rival.getTipo()) << ")" << std::endl;

    // Obtener los ataques del jugador utilizando el método público
    const auto& ataquesMiPokemon = miPokemon.getAtaques();

    // Lógica para la batalla
    while (miPokemon.getSalud() > 0 && rival.getSalud() > 0) {
        // Turno del jugador
        std::cout << "Turno de " << miPokemon.getNombre() << ". Elige tu ataque:" << std::endl;
        int i = 1;
        for (const auto& ataque : ataquesMiPokemon) {
            std::cout << i << ". " << ataque.first << " (" << ataque.second << " potencia)" << std::endl;
            i++;
        }

        int ataqueElegido;
        std::cin >> ataqueElegido;
        ataqueElegido--; // Ajustamos la opción al índice del mapa de ataques

        if (ataqueElegido < 0 || ataqueElegido >= ataquesMiPokemon.size()) {
            std::cout << "Ataque no valido. Turno perdido." << std::endl;
        } else {
            auto it = ataquesMiPokemon.begin();
            std::advance(it, ataqueElegido);
            miPokemon.atacar(rival, ataqueElegido); // Realizamos el ataque
        }

        // Turno del rival si aún tiene salud
        if (rival.getSalud() > 0) {
            int ataqueRival = rand() % rival.getAtaques().size(); // El rival elige un ataque aleatorio
            rival.atacar(miPokemon, ataqueRival);
        }
    }

    // Resultado final de la batalla
    if (miPokemon.getSalud() <= 0) {
        std::cout << "Tu Pokemon ha sido derrotado. Debes curarlo antes de continuar." << std::endl;
    } else {
        std::cout << "¡Felicidades! Has derrotado al entrenador y has ganado una medalla." << std::endl;
        recolectarMedalla(); // Recolectamos la medalla después de ganar la batalla
    }
}

void Jugador::recolectarMedalla() {
    // Implementación de la función recolectarMedalla
    // Aquí va el código que recolecta la medalla
}
int main() {
    std::cout << "Bienvenido a Pokemon Gamer" << std::endl;
    std::cout << "1. Partida Nueva" << std::endl;
    std::cout << "2. Salir" << std::endl;
    std::cout << "Seleccione una opcion: ";

    int opcion;
    std::cin >> opcion;

    if (opcion == 1) {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));

        // Crear un objeto Juego
        Juego juego;
        juego.iniciarJuego();  // Llama al método iniciarJuego() de Juego
    } else {
        std::cout << "Saliendo del juego..." << std::endl;
    }

    return 0;
}
=======
#include <iostream>
#include "Mapa.h"


using namespace std;


    int main() {
        // Crear el objeto Mapa
        Mapa ini;

        // Ejecutar el bucle principal del menú
        ini.ejecutar();

        return 0;
    }
>>>>>>> Eddy
*/

     int main() {
         // aspectos a tener en cuenta el punto h de msql
     }
#include <iostream>
    using namespace std;
    int main()
    MYSQL* conectar;
    conectar r = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "usr_empresa", "Empresa@123" , "db_empresa", 3306, NULL, 0);
    if (conectar) {
        cout << "Conexion Exitosa..." << endl;
        else {
            cout << "Error en la Conexion..." << endl;
            system("pause");
            return 0;

     }