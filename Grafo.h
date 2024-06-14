//
// Created by Eddy Lucandy on 14/6/24.
//

#ifndef ACTV_GRUPAL_GRAFO_H
#define ACTV_GRUPAL_GRAFO_H

#include <iostream>
#include <string>
#include "Par.h"
#include "Lista.h"

using namespace std;

template <typename Clave, typename InfoVertice, typename Coste>
class Grafo {
protected:
    // Clase interna que representa un vértice del grafo
    class NodoVertice {
    public:
        Clave clave;  // Identificador del vértice
        InfoVertice vertice;  // Información asociada al vértice
        int gradoEntrada;  // Grado de entrada del vértice
        int gradoSalida;  // Grado de salida del vértice

        // Constructor del NodoVertice
        NodoVertice(Clave c, InfoVertice v)
                : clave(c), vertice(v), gradoEntrada(0), gradoSalida(0) {}
    };

    // Clase interna que representa una arista del grafo
    class NodoArista {
    public:
        NodoVertice* destino;  // Vértice destino de la arista
        Coste coste;  // Peso de la arista

        // Constructor del NodoArista con solo el destino
        NodoArista(NodoVertice* d) : destino(d), coste(Coste()) {}

        // Constructor del NodoArista con destino y coste
        NodoArista(NodoVertice* d, Coste c) : destino(d), coste(c) {}
    };

    // Atributos
    Lista<NodoVertice*> vertices; // Conjunto de vértices
    Lista<Lista<NodoArista*>> aristas; // Lista de adyacencia para representar las aristas

public:
    // Constructor del grafo
    Grafo() {}

    // Destructor para liberar memoria
    ~Grafo() {
        for (int i = 1; i <= vertices.longitud(); ++i) delete vertices.consultar(i);
        for (int i = 1; i <= aristas.longitud(); ++i)
            for (int j = 1; j <= aristas.consultar(i).longitud(); ++j)
                delete aristas.consultar(i).consultar(j);
    }

    // Método para verificar si el grafo está vacío
    bool esVacio() const {
        return vertices.longitud() == 0;
    }

    // Método para insertar un vértice en el grafo
    void insertarVertice(Clave c, InfoVertice v) {
        vertices.insertar(vertices.longitud() + 1, new NodoVertice(c, v));
        aristas.insertar(aristas.longitud() + 1, Lista<NodoArista*>());
    }

    // Método para modificar la información de un vértice existente
    void modificarVertice(Clave c, InfoVertice v) {
        for (int i = 1; i <= vertices.longitud(); ++i) {
            if (vertices.consultar(i)->clave == c) {
                vertices.consultar(i)->vertice = v;
                break;
            }
        }
    }

    // Método para eliminar un vértice del grafo
    void eliminarVertice(Clave c) {
        for (int i = 1; i <= vertices.longitud(); ++i) {
            if (vertices.consultar(i)->clave == c) {
                delete vertices.consultar(i);
                vertices.borrar(i);
                aristas.borrar(i);
                break;
            }
        }
    }

    // Método para verificar si un vértice existe en el grafo
    bool existeVertice(Clave c) const {
        for (int i = 1; i <= vertices.longitud(); ++i) {
            if (vertices.consultar(i)->clave == c) {
                return true;
            }
        }
        return false;
    }

    // Método para insertar una arista en el grafo
    void insertarArista(Clave o, Clave d, Coste c) {
        NodoVertice* origen = nullptr;
        NodoVertice* destino = nullptr;
        int i = 1, j = 1;

        for (; i <= vertices.longitud(); ++i) {
            if (vertices.consultar(i)->clave == o) {
                origen = vertices.consultar(i);
                break;
            }
        }

        for (; j <= vertices.longitud(); ++j) {
            if (vertices.consultar(j)->clave == d) {
                destino = vertices.consultar(j);
                break;
            }
        }

        if (origen && destino) {
            aristas.consultar(i).insertar(1, new NodoArista(destino, c));
            origen->gradoSalida++;
            destino->gradoEntrada++;
        }
    }

    // Método para modificar el coste de una arista existente
    void modificarArista(Clave o, Clave d, Coste c) {
        for (int i = 1; i <= vertices.longitud(); ++i) {
            if (vertices.consultar(i)->clave == o) {
                for (int j = 1; j <= aristas.consultar(i).longitud(); ++j) {
                    if (aristas.consultar(i).consultar(j)->destino->clave == d) {
                        aristas.consultar(i).consultar(j)->coste = c;
                        return;
                    }
                }
            }
        }
    }

    // Método para eliminar una arista del grafo
    void eliminarArista(Clave o, Clave d) {
        for (int i = 1; i <= vertices.longitud(); ++i) {
            if (vertices.consultar(i)->clave == o) {
                for (int j = 1; j <= aristas.consultar(i).longitud(); ++j) {
                    if (aristas.consultar(i).consultar(j)->destino->clave == d) {
                        delete aristas.consultar(i).consultar(j);
                        aristas.consultar(i).borrar(j);
                        vertices.consultar(i)->gradoSalida--;
                        vertices.consultar(j)->gradoEntrada--;
                        return;
                    }
                }
            }
        }
    }

    // Método para obtener el coste de una arista
    Coste costeArista(Clave o, Clave d) const {
        for (int i = 1; i <= vertices.longitud(); ++i) {
            if (vertices.consultar(i)->clave == o) {
                for (int j = 1; j <= aristas.consultar(i).longitud(); ++j) {
                    if (aristas.consultar(i)->consultar(j)->destino->clave == d) {
                        return aristas.consultar(i)->consultar(j)->coste;
                    }
                }
            }
        }
        return Coste();
    }

    // Método para obtener el grado de entrada de un vértice
    int gradoEntrada(Clave v) const {
        for (int i = 1; i <= vertices.longitud(); ++i) {
            if (vertices.consultar(i)->clave == v) {
                return vertices.consultar(i)->gradoEntrada;
            }
        }
        return 0;
    }

    // Método para obtener el grado de salida de un vértice
    int gradoSalida(Clave v) const {
        for (int i = 1; i <= vertices.longitud(); ++i) {
            if (vertices.consultar(i)->clave == v) {
                return vertices.consultar(i)->gradoSalida;
            }
        }
        return 0;
    }

    // Método para obtener la lista de sucesores de un vértice
    Lista<Clave> listaSucesores(Clave v) const {
        Lista<Clave> sucesores;
        for (int i = 1; i <= vertices.longitud(); ++i) {
            if (vertices.consultar(i)->clave == v) {
                for (int j = 1; j <= aristas.consultar(i).longitud(); ++j) {
                    sucesores.insertar(j, aristas.consultar(i).consultar(j)->destino->clave);
                }
            }
        }
        return sucesores;
    }

    // Método para obtener la lista de predecesores de un vértice
    Lista<Clave> listaPredecesores(Clave v) const {
        Lista<Clave> predecesores;
        for (int i = 1; i <= vertices.longitud(); ++i) {
            for (int j = 1; j <= aristas.consultar(i).longitud(); ++j) {
                if (aristas.consultar(i).consultar(j)->destino->clave == v) {
                    predecesores.insertar(predecesores.longitud() + 1, vertices.consultar(i)->clave);
                }
            }
        }
        return predecesores;
    }

    // Método para obtener el número de vértices en el grafo
    int numVertices() const {
        return vertices.longitud();
    }

    // Método para obtener la lista de todos los vértices
    Lista<Clave> listaVertices() const {
        Lista<Clave> lista;
        for (int i = 1; i <= vertices.longitud(); ++i) {
            lista.insertar(lista.longitud() + 1, vertices.consultar(i)->clave);
        }
        return lista;
    }

    // Método para obtener la lista de aristas como pares de vértices
    Lista<Par<Clave, Clave>> listaAristas() const {
        Lista<Par<Clave, Clave>> listado;
        for (int i = 1; i <= vertices.longitud(); ++i) {
            Clave origen = vertices.consultar(i)->clave;
            Lista<Clave> sucesores = listaSucesores(origen);
            for (int j = 1; j <= sucesores.longitud(); ++j) {
                Clave destino = sucesores.consultar(j);
                Par<Clave, Clave> arista(origen, destino);
                listado.insertar(1, arista);
            }
        }
        return listado;
    }

    // Método toString para representar el grafo como una cadena de texto
    std::string toString() const {
        std::string texto;
        for (int i = 1; i <= vertices.longitud(); ++i) {
            texto += vertices.consultar(i)->clave + " --> ";
            for (int j = 1; j <= aristas.consultar(i).longitud(); ++j) {
                texto += aristas.consultar(i).consultar(j)->destino->clave + "("
                         + std::to_string(aristas.consultar(i).consultar(j)->coste) + ") ";
            }
            texto += "\n";
        }
        return texto;
    }

    // Método recursivo para el recorrido en profundidad
    static void profREC(Grafo<Clave, InfoVertice, Coste>& gr, Clave inicio, Lista<Clave>& noVisitados) {
        std::cout << "*VISITO: " << inicio << std::endl;
        noVisitados.borrar(noVisitados.buscar(inicio));
        std::cout << "\tNoVisitados: " << noVisitados.toString() << std::endl;

        Lista<Clave> sucesores = gr.listaSucesores(inicio);
        std::cout << "\tSucesores de " << inicio << ": " << sucesores.toString() << std::endl;
        for (int i = 1; i <= sucesores.longitud(); ++i) {
            Clave v = sucesores.consultar(i);
            if (noVisitados.buscar(v) != 0) {
                profREC(gr, v, noVisitados);
            }
        }
    }

    // Método para iniciar el recorrido en profundidad desde un vértice dado
    static void profundidad(Grafo<Clave, InfoVertice, Coste>& gr, Clave inicio) {
        Lista<Clave> noVisitados = gr.listaVertices();
        profREC(gr, inicio, noVisitados);
        while (!noVisitados.esVacia()) {
            std::cout << "\n**Nueva componente conexa**\n";
            profREC(gr, noVisitados.consultar(1), noVisitados);
        }
    }
};

#endif //ACTV_GRUPAL_GRAFO_H
