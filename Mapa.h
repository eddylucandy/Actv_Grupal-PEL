//
// Created by Eddy Lucandy on 13/6/24.
//

#ifndef ACTV_GRUPAL_MAPA_H
#define ACTV_GRUPAL_MAPA_H

#pragma once
#include "Ciudad.h"
#include "Grafo.h"
#include "Lista.h"
#include "Par.h"
#include "Rutas.h"

class Mapa {
public:
    void mapa() {
        Grafo<std::string, Ciudad, int> grafo;

        // Crear ciudades
        Ciudad ciudad1("Ciudad1");
        Ciudad ciudad2("Ciudad2");
        Ciudad ciudad3("Ciudad3");
        Ciudad ciudad4("Ciudad4");
        Ciudad pueblo1("Pueblo1");
        Ciudad pueblo2("Pueblo2");
        Ciudad pueblo3("Pueblo3");
        Ciudad pueblo4("Pueblo4");
        Ciudad pueblo5("Pueblo5");
        Ciudad pueblo6("Pueblo6");

        // Establecer propiedades de las ciudades
        ciudad1.agregarVivienda("Casa1");
        ciudad1.agregarVivienda("Casa2");
        ciudad1.agregarVivienda("Casa3");
        ciudad1.agregarVivienda("Casa4");
        ciudad1.agregarVivienda("Casa5");
        ciudad1.agregarObjeto("Piedra Lunar");
        ciudad1.establecerGimnasio("Gimnasio Ciudad1");
        ciudad1.establecerCentroPokemon("Centro Pokemon Ciudad1");
        ciudad1.establecerTienda("Tienda Ciudad1");

        ciudad2.agregarVivienda("Casa1");
        ciudad2.agregarVivienda("Casa2");
        ciudad2.agregarVivienda("Casa3");
        ciudad2.agregarVivienda("Casa4");
        ciudad2.agregarVivienda("Casa5");
        ciudad2.agregarObjeto("Pocion");
        ciudad2.establecerGimnasio("Gimnasio Ciudad2");
        ciudad2.establecerCentroPokemon("Centro Pokemon Ciudad2");
        ciudad2.establecerTienda("Tienda Ciudad2");

        ciudad3.agregarVivienda("Casa1");
        ciudad3.agregarVivienda("Casa2");
        ciudad3.agregarVivienda("Casa3");
        ciudad3.agregarVivienda("Casa4");
        ciudad3.agregarVivienda("Casa5");
        ciudad3.agregarObjeto("Superpocion");
        ciudad3.establecerGimnasio("Gimnasio Ciudad3");
        ciudad3.establecerCentroPokemon("Centro Pokemon Ciudad3");
        ciudad3.establecerTienda("Tienda Ciudad3");

        ciudad4.agregarVivienda("Casa1");
        ciudad4.agregarVivienda("Casa2");
        ciudad4.agregarVivienda("Casa3");
        ciudad4.agregarVivienda("Casa4");
        ciudad4.agregarVivienda("Casa5");
        ciudad4.agregarObjeto("Antidoto");
        ciudad4.establecerGimnasio("Gimnasio Ciudad4");
        ciudad4.establecerCentroPokemon("Centro Pokemon Ciudad4");
        ciudad4.establecerTienda("Tienda Ciudad4");

        // Establecer propiedades de los pueblos
        pueblo1.agregarVivienda("Casa1");
        pueblo1.agregarVivienda("Casa2");
        pueblo1.agregarVivienda("Casa3");
        pueblo1.agregarObjeto("Cuerda Huida");
        pueblo1.establecerCentroPokemon("Centro Pokemon Pueblo1");

        pueblo2.agregarVivienda("Casa1");
        pueblo2.agregarVivienda("Casa2");
        pueblo2.agregarVivienda("Casa3");
        pueblo2.agregarObjeto("Piedra Trueno");
        pueblo2.establecerCentroPokemon("Centro Pokemon Pueblo2");

        pueblo3.agregarVivienda("Casa1");
        pueblo3.agregarVivienda("Casa2");
        pueblo3.agregarVivienda("Casa3");
        pueblo3.agregarObjeto("Piedra Fuego");
        pueblo3.establecerCentroPokemon("Centro Pokemon Pueblo3");

        pueblo4.agregarVivienda("Casa1");
        pueblo4.agregarVivienda("Casa2");
        pueblo4.agregarVivienda("Casa3");
        pueblo4.agregarObjeto("Piedra Agua");
        pueblo4.establecerCentroPokemon("Centro Pokemon Pueblo4");

        pueblo5.agregarVivienda("Casa1");
        pueblo5.agregarVivienda("Casa2");
        pueblo5.agregarVivienda("Casa3");
        pueblo5.agregarObjeto("Revivir");
        pueblo5.establecerCentroPokemon("Centro Pokemon Pueblo5");

        pueblo6.agregarVivienda("Casa1");
        pueblo6.agregarVivienda("Casa2");
        pueblo6.agregarVivienda("Casa3");
        pueblo6.agregarObjeto("Max Pocion");
        pueblo6.establecerCentroPokemon("Centro Pokemon Pueblo6");

        // Insertar ciudades y pueblos en el grafo
        grafo.insertarVertice("Ciudad1", ciudad1);
        grafo.insertarVertice("Ciudad2", ciudad2);
        grafo.insertarVertice("Ciudad3", ciudad3);
        grafo.insertarVertice("Ciudad4", ciudad4);
        grafo.insertarVertice("Pueblo1", pueblo1);
        grafo.insertarVertice("Pueblo2", pueblo2);
        grafo.insertarVertice("Pueblo3", pueblo3);
        grafo.insertarVertice("Pueblo4", pueblo4);
        grafo.insertarVertice("Pueblo5", pueblo5);
        grafo.insertarVertice("Pueblo6", pueblo6);

        // Crear rutas entre ciudades y pueblos
        grafo.insertarArista("Ciudad1", "Ciudad2", 1);
        grafo.insertarArista("Ciudad1", "Pueblo1", 1);
        grafo.insertarArista("Ciudad2", "Ciudad3", 1);
        grafo.insertarArista("Ciudad2", "Pueblo2", 1);
        grafo.insertarArista("Ciudad3", "Ciudad4", 1);
        grafo.insertarArista("Ciudad3", "Pueblo3", 1);
        grafo.insertarArista("Ciudad4", "Pueblo4", 1);
        grafo.insertarArista("Pueblo1", "Pueblo5", 1);
        grafo.insertarArista("Pueblo2", "Pueblo6", 1);
        grafo.insertarArista("Pueblo3", "Pueblo4", 1);

        // Mostrar el grafo (mapa)
        std::cout << grafo.toString() << std::endl;
    }
};

#endif //ACTV_GRUPAL_MAPA_H