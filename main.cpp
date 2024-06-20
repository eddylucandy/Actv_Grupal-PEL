#include <iostream>
#include "Ciudad.h"
#include "Grafo.h"
#include "Par.h"
#include "Lista.h"
#include "Rutas.h"


using namespace std;

void mapa() {
    // Implementar la función que dibuja el mapa aquí


    // Ejemplo de creación de grafo con ciudades y rutas
    Grafo<std::string, Ciudad, int> grafo;

    // Crear ciudades
    Ciudad ciudad1("Ciudad1");
    Ciudad ciudad2("Ciudad2");

    // Establecer propiedades de las ciudades
    ciudad1.agregarVivienda("Casa1");
    ciudad1.agregarVivienda("Casa2");
    ciudad1.agregarObjeto("Piedra Lunar");
    ciudad1.establecerGimnasio("Gimnasio Ciudad1");
    ciudad1.establecerCentroPokemon("Centro Pokemon Ciudad1");
    ciudad1.establecerTienda("Tienda Ciudad1");

    ciudad2.agregarVivienda("Casa3");
    ciudad2.agregarVivienda("Casa4");
    ciudad2.agregarObjeto("Pocion");
    ciudad2.establecerGimnasio("Gimnasio Ciudad2");
    ciudad2.establecerCentroPokemon("Centro Pokemon Ciudad2");
    ciudad2.establecerTienda("Tienda Ciudad2");

    // Insertar ciudades en el grafo
    grafo.insertarVertice("Ciudad1", ciudad1);
    grafo.insertarVertice("Ciudad2", ciudad2);

    // Crear ruta entre ciudades
    grafo.insertarArista("Ciudad1", "Ciudad2", 1);

    // Mostrar el grafo (mapa)
    std::cout << grafo.toString() << std::endl;
}

int main() {
    // LLamada a la funcion Mapa
    mapa();

    return 0;
}


