//
// Created by Eddy Lucandy on 14/6/24.
//

#ifndef ACTV_GRUPAL_GRAFO_H
#define ACTV_GRUPAL_GRAFO_H

#include "Lista.h"
#include "Par.h"
#include <string>
#include <memory>
#include <stdexcept>
#include <iostream>

template <typename Clave, typename InfoVertice, typename Coste>
class Grafo {
protected:
    class NodoVertice {
    public:
        Clave clave;
        InfoVertice vertice;

        NodoVertice(Clave c, InfoVertice v) : clave(c), vertice(v) {}
    };

    class NodoArista {
    public:
        std::shared_ptr<NodoVertice> destino;
        Coste coste;

        NodoArista(std::shared_ptr<NodoVertice> d, Coste c) : destino(d), coste(c) {}
    };

    Lista<std::shared_ptr<NodoVertice> > vertices;
    Lista<Lista<std::shared_ptr<NodoArista> > > aristas;

public:
    Grafo() {}

    bool esVacio() const {
        return vertices.longitud() == 0;
    }

    void insertarVertice(Clave c, InfoVertice v) {
        vertices.insertar(vertices.longitud() + 1, std::make_shared<NodoVertice>(c, v));
        aristas.insertar(aristas.longitud() + 1, Lista<std::shared_ptr<NodoArista> >());
    }

    void modificarVertice(Clave c, InfoVertice v) {
        for (int i = 1; i <= vertices.longitud(); ++i) {
            if (vertices.consultar(i)->clave == c) {
                vertices.consultar(i)->vertice = v;
                break;
            }
        }
    }

    void eliminarVertice(Clave c) {
        for (int i = 1; i <= vertices.longitud(); ++i) {
            if (vertices.consultar(i)->clave == c) {
                // Eliminar las aristas asociadas
                Lista<std::shared_ptr<NodoArista> > aristasVertice = aristas.consultar(i);
                for (int j = 1; j <= aristasVertice.longitud(); ++j) {
                    eliminarArista(c, aristasVertice.consultar(j)->destino->clave);
                }

                vertices.borrar(i);
                aristas.borrar(i);
                break;
            }
        }
    }

    bool existeVertice(Clave c) const {
        for (int i = 1; i <= vertices.longitud(); ++i) {
            if (vertices.consultar(i)->clave == c) {
                return true;
            }
        }
        return false;
    }

    void insertarArista(Clave o, Clave d, Coste c) {
        std::shared_ptr<NodoVertice> origen = nullptr;
        std::shared_ptr<NodoVertice> destino = nullptr;
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
            aristas.consultar(i).insertar(aristas.consultar(i).longitud() + 1, std::make_shared<NodoArista>(destino, c));
            aristas.consultar(j).insertar(aristas.consultar(j).longitud() + 1, std::make_shared<NodoArista>(origen, c));
        } else {
            std::cerr << "Error: Origen o destino no encontrado para insertar la arista.\n";
        }
    }

    void modificarArista(Clave o, Clave d, Coste c) {
        for (int i = 1; i <= vertices.longitud(); ++i) {
            if (vertices.consultar(i)->clave == o) {
                for (int j = 1; j <= aristas.consultar(i).longitud(); ++j) {
                    if (aristas.consultar(i).consultar(j)->destino->clave == d) {
                        aristas.consultar(i).consultar(j)->coste = c;
                    }
                }
            }

            if (vertices.consultar(i)->clave == d) {
                for (int j = 1; j <= aristas.consultar(i).longitud(); ++j) {
                    if (aristas.consultar(i).consultar(j)->destino->clave == o) {
                        aristas.consultar(i).consultar(j)->coste = c;
                    }
                }
            }
        }
    }

    void eliminarArista(Clave o, Clave d) {
        for (int i = 1; i <= vertices.longitud(); ++i) {
            if (vertices.consultar(i)->clave == o) {
                for (int j = 1; j <= aristas.consultar(i).longitud(); ++j) {
                    if (aristas.consultar(i).consultar(j)->destino->clave == d) {
                        aristas.consultar(i).borrar(j);
                        break;
                    }
                }
            }

            if (vertices.consultar(i)->clave == d) {
                for (int j = 1; j <= aristas.consultar(i).longitud(); ++j) {
                    if (aristas.consultar(i).consultar(j)->destino->clave == o) {
                        aristas.consultar(i).borrar(j);
                        break;
                    }
                }
            }
        }
    }

    Coste costeArista(Clave o, Clave d) const {
        for (int i = 1; i <= vertices.longitud(); ++i) {
            if (vertices.consultar(i)->clave == o) {
                for (int j = 1; j <= aristas.consultar(i).longitud(); ++j) {
                    if (aristas.consultar(i).consultar(j)->destino->clave == d) {
                        return aristas.consultar(i).consultar(j)->coste;
                    }
                }
            }
        }
        return Coste();
    }

    Lista<Clave> listaSucesores(Clave v) const {
        Lista<Clave> sucesores;
        for (int i = 1; i <= vertices.longitud(); ++i) {
            if (vertices.consultar(i)->clave == v) {
                for (int j = 1; j <= aristas.consultar(i).longitud(); ++j) {
                    sucesores.insertar(sucesores.longitud() + 1, aristas.consultar(i).consultar(j)->destino->clave);
                }
            }
        }
        return sucesores;
    }

    Lista<Clave> listaVertices() const {
        Lista<Clave> lista;
        for (int i = 1; i <= vertices.longitud(); ++i) {
            lista.insertar(lista.longitud() + 1, vertices.consultar(i)->clave);
        }
        return lista;
    }

    Lista<Par<Clave, Clave> > listaAristas() const {
        Lista<Par<Clave, Clave> > listado;
        for (int i = 1; i <= vertices.longitud(); ++i) {
            Clave origen = vertices.consultar(i)->clave;
            Lista<Clave> sucesores = listaSucesores(origen);
            for (int j = 1; j <= sucesores.longitud(); ++j) {
                Clave destino = sucesores.consultar(j);
                Par<Clave, Clave> arista(origen, destino);
                listado.insertar(listado.longitud() + 1, arista);
            }
        }
        return listado;
    }

    InfoVertice consultarVertice(Clave c) const {
        for (int i = 1; i <= vertices.longitud(); ++i) {
            if (vertices.consultar(i)->clave == c) {
                return vertices.consultar(i)->vertice;
            }
        }
        throw std::runtime_error("Vertice no encontrado");
    }

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
