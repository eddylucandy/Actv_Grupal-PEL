#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>
// Enumeración para los tipos de Pokémon
enum class TipoPokemon {
    Normal,
    Fuego,
    Agua,
    Planta,
    Electrico,
    Tierra,
    // Agrega más tipos según sea necesario
};

// Clase base para los datos del Pokémon
class PokemonBase {
public:
    std::string nombre;
    TipoPokemon tipo;
    int nivel;
    int salud;
    int ataque;
    int defensa;
    std::unordered_map<std::string, int> ataquesDisponibles;

    // Constructor de PokemonBase
    PokemonBase(const std::string& nombre, TipoPokemon tipo, int nivel, int salud, int ataque, int defensa, const std::unordered_map<std::string, int>& ataques)
            : nombre(nombre), tipo(tipo), nivel(nivel), salud(salud), ataque(ataque), defensa(defensa), ataquesDisponibles(ataques)
    {}
};

// Lista de los primeros 20 Pokémon de la primera generación
extern const std::vector<PokemonBase> primeros20Pokemon;

// Clase Pokémon
class Pokemon {
private:
    std::string nombre;
    TipoPokemon tipo;
    int nivel;
    int salud;
    int ataque;
    int defensa;
    std::unordered_map<std::string, int> ataques;

public:
    // Constructor de Pokémon desde parámetros directos
    Pokemon(const std::string& nombre, TipoPokemon tipo, int nivel, int salud, int ataque, int defensa)
            : nombre(nombre), tipo(tipo), nivel(nivel), salud(salud), ataque(ataque), defensa(defensa)
    {}

    // Constructor de Pokémon a partir de PokemonBase
    Pokemon(const PokemonBase& base, int nivel = 5, int salud = 100)
            : nombre(base.nombre), tipo(base.tipo), nivel(nivel), salud(salud), ataque(base.ataque), defensa(base.defensa), ataques(base.ataquesDisponibles)
    {}

    // Métodos de acceso y otros métodos de la clase Pokémon
    const std::string& getNombre() const { return nombre; }
    TipoPokemon getTipo() const { return tipo; }
    int getNivel() const { return nivel; }
    int getSalud() const { return salud; }
    int getAtaque() const { return ataque; }
    int getDefensa() const { return defensa; }
    const std::unordered_map<std::string, int>& getAtaques() const { return ataques; }

    // Declaración de la función atacar
    void atacar(Pokemon& rival, int indiceAtaque);

    // Declaración de la función recibirDanio
    void recibirDanio(int danio) {
        salud -= danio;
        if (salud < 0) salud = 0;
    }

    void mostrarInfo() const;

    std::string tipoPokemonToString(TipoPokemon tipo) const {
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


    void curar() {
        salud = 100;
    }
};

#endif // POKEMON_H
