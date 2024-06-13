#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>

class Pokemon {
private:
    std::string nombre;
    std::string tipo;
    int nivel;
    int salud;
    int ataque;
    int defensa;

public:
    // Constructor
    Pokemon(std::string nombre, std::string tipo, int nivel, int salud, int ataque, int defensa)
            : nombre(nombre), tipo(tipo), nivel(nivel), salud(salud), ataque(ataque), defensa(defensa) {}

    // Métodos de acceso (getters)
    std::string getNombre() const { return nombre; }
    std::string getTipo() const { return tipo; }
    int getNivel() const { return nivel; }
    int getSalud() const { return salud; }
    int getAtaque() const { return ataque; }
    int getDefensa() const { return defensa; }

    // Otros métodos según necesidad
    void mostrarInfo() const {
        std::cout << "Nombre: " << nombre << ", Tipo: " << tipo << ", Nivel: " << nivel
                  << ", Salud: " << salud << ", Ataque: " << ataque << ", Defensa: " << defensa << std::endl;
    }

    void curar() {
        salud = 100;
};

#endif // POKE