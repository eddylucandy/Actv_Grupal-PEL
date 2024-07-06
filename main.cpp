#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Mapa.h"
#include "Grafo.h"

using namespace std;

int main() {
    // Inicializar la semilla del generador de números aleatorios
    std::srand(static_cast<unsigned int>(std::time(nullptr)));


    //Test
  /*  Grafo<std::string, std::shared_ptr<void>, int> grafo;
    Mapa mapa;
    mapa.inicializarMapa();
    //

if(!grafo.esVacio()){
    for (int i = 1; i <= grafo.numVertices();i++){
        cout<<grafo.listaVertices().consultar(i);
    }}else{
    cout<< "test";
}*/


    // Crear el objeto mapa
    Mapa mapa;

    // Ejecutar el juego
    //mapa.inicializarMapa();
    mapa.ejecutar();

    return 0;
}

