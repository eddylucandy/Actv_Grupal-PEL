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
private:
    Grafo<std::string, Ciudad, int> grafo;
    std::string posicionActual;
public:
    void inicializarMapa() {
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

        // Definir la posición inicial del jugador
        posicionActual = "Ciudad1";
    }

    void menuCiudad() {
        int opcion;
        std::cout << "Menu de la Ciudad:\n";
        std::cout << "1. Donde estoy\n";
        std::cout << "2. Moverse\n";
        std::cout << "3. Mochila\n";
        std::cout << "4. Equipo\n";
        std::cout << "5. Información\n";
        std::cout << "6. Abandonar el juego\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                std::cout << "Estás en " << posicionActual << ".\n";
                break;
            case 2:
                moverse();
                break;
            case 3:
                std::cout << "Abriendo la mochila...\n";
                // Lógica para mostrar o manipular el contenido de la mochila
                break;
            case 4:
                std::cout << "Mostrando el equipo Pokémon.\n";
                // Lógica para mostrar o cambiar el equipo Pokémon
                break;
            case 5:
                mostrarInformacion();
                break;
            case 6:
                std::cout << "Abandonando el juego...\n";
                exit(0); // Termina la ejecución del programa
                break;
            default:
                std::cout << "Opción no válida. Por favor, intenta de nuevo.\n";
                break;
        }
    }

    void menuRuta() {
        int opcion;
        std::cout << "Menu de la Ruta:\n";
        std::cout << "1. Explorar\n";
        std::cout << "2. Moverse\n";
        std::cout << "3. Abandonar el juego\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                std::cout << "Explorando la ruta desde " << posicionActual << "...\n";
                // Lógica para explorar la ruta
                explorarRuta();
                break;
            case 2:
                moverse();
                break;
            case 3:
                std::cout << "Abandonando el juego...\n";
                exit(0); // Termina la ejecución del programa
                break;
            default:
                std::cout << "Opción no válida. Por favor, intenta de nuevo.\n";
                break;
        }
    }

    void moverse() {
        Lista<std::string> destinos = grafo.listaSucesores(posicionActual);
        if (destinos.longitud() == 0) {
            std::cout << "No hay destinos disponibles desde aquí." << std::endl;
            return;
        }
        for (int i = 1; i <= destinos.longitud(); ++i) {
            std::cout << i << ". " << destinos.consultar(i) << "\n";
        }
        std::cout << "Selecciona la dirección a la que deseas moverte: ";
        int opcion;
        std::cin >> opcion;
        if (opcion > 0 && opcion <= destinos.longitud()) {
            std::string destinoSeleccionado = destinos.consultar(opcion);
            menuRuta(); // Invoca el menú de ruta antes de actualizar posición actual
            posicionActual = destinoSeleccionado;
            std::cout << "Has llegado a " << posicionActual << ".\n";
        } else {
            std::cout << "Opción no válida. Por favor, intenta de nuevo.\n";
        }
    }

    void explorarRuta() {
        std::cout << "Explorando la ruta...\n";
        int encuentro = rand() % 3;  // Genera un número aleatorio entre 0 y 2

        switch (encuentro) {
            case 0:
                encuentroPokemon();
                break;
            case 1:
                encuentroEntrenador();
                break;
            case 2:
                encuentroObjeto();
                break;
            default:
                std::cout << "Sigues tu camino sin incidentes.\n";
                break;
        }
    }


    void encuentroPokemon() {
        std::cout << "¡Encontraste un Pokémon salvaje! ¿Quieres pelear o huir?\n";
        std::cout << "1. Pelear\n";
        std::cout << "2. Huir\n";
        int eleccion;
        std::cin >> eleccion;
        if (eleccion == 1) {
            std::cout << "¡Comienzas la batalla Pokémon!\n";
            // Lógica de batalla (a implementar)
        }else if(eleccion == 2){
            std::cout << "Decides huir. Continuas tu viaje.\n";
        }else {
            std::cout << "Opción no válida. Por favor, intenta de nuevo.\n";
        }
    }


    void encuentroEntrenador() {
        std::cout << "¡Encontraste un entrenador Pokémon dispuesto a luchar! ¿Quieres pelear o huir?\n";
        std::cout << "1. Pelear\n";
        std::cout << "2. Huir\n";
        int eleccion;
        std::cin >> eleccion;
        if (eleccion == 1) {
            std::cout << "¡El combate comienza!\n";
            // Lógica de combate (a implementar)
        } else if(eleccion == 2){
            std::cout << "Decides huir. Sigues tu camino.\n";
        }else{
            std::cout << "Opción no válida. Por favor, intenta de nuevo.\n";
        }
    }


    void encuentroObjeto() {
        std::cout << "¡Has encontrado un objeto en el camino! ¿Quieres cogerlo o dejarlo?\n";
        std::cout << "1. Cogerlo\n";
        std::cout << "2. Dejarlo\n";
        int eleccion;
        std::cin >> eleccion;
        if (eleccion == 1) {
            std::cout << "Tomas el objeto y lo guardas en tu mochila.\n";
            // Añadir objeto a la mochila (a implementar)
        } else if (eleccion == 2){
            std::cout << "Decides dejarlo donde está y continuar tu aventura.\n";
        }else{
            std::cout << "Opción no válida. Por favor, intenta de nuevo.\n";
        }
    }


    void mostrarInformacion() {
        // Proporcionar información relevante sobre la ciudad
        std::cout << grafo.consultarVertice(posicionActual).toString() << "\n";
    }


    void ejecutar() {
        while (true) {
            if (esCiudad(posicionActual)) {
                menuCiudad();
            } else {
                menuRuta();
            }
        }
    }
/*
    bool esCiudad(const std::string& nombre) {
        // Asumiendo que las ciudades tienen nombres que empiezan con "Ciudad"
        return nombre.find("Ciudad") == 0;
    }*/
    bool esCiudad(const std::string& nombre) {
        // Asumiendo que las ciudades tienen nombres que empiezan con "Ciudad"
        return nombre.find("Ciudad") != std::string::npos;
    }

};

#endif //ACTV_GRUPAL_MAPA_H