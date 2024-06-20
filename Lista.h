//
// Created by Eddy Lucandy on 14/6/24.
//

#ifndef ACTV_GRUPAL_LISTA_H
#define ACTV_GRUPAL_LISTA_H

#include <iostream>
#include <string>
#include "Par.h"
#pragma once

using namespace std;

// Clase Lista
template <typename T>
class Lista {
private:
    T* contenedor;
    int longitud_actual;
    int capacidad;

    void expandir() {
        capacidad *= 2;
        T* nuevo_contenedor = new T[capacidad];
        for (int i = 0; i < longitud_actual; ++i) {
            nuevo_contenedor[i] = contenedor[i];
        }
        delete[] contenedor;
        contenedor = nuevo_contenedor;
    }

public:
    Lista() : longitud_actual(0), capacidad(4) {
        contenedor = new T[capacidad];
    }

    Lista(const Lista& lista) : longitud_actual(lista.longitud_actual), capacidad(lista.capacidad) {
        contenedor = new T[capacidad];
        for (int i = 0; i < longitud_actual; ++i) {
            contenedor[i] = lista.contenedor[i];
        }
    }

    ~Lista() {
        delete[] contenedor;
    }

    int longitud() const {
        return longitud_actual;
    }

    bool esVacia() const {
        return longitud_actual == 0;
    }

    T consultar(int pos) const {
        return contenedor[pos - 1];
    }

    int buscar(T elem) const {
        for (int i = 0; i < longitud_actual; ++i) {
            if (contenedor[i] == elem) {
                return i + 1;
            }
        }
        return 0;
    }

    void insertar(int pos, T elem) {
        if (longitud_actual == capacidad) {
            expandir();
        }
        for (int i = longitud_actual; i > pos - 1; --i) {
            contenedor[i] = contenedor[i - 1];
        }
        contenedor[pos - 1] = elem;
        ++longitud_actual;
    }

    void borrar(int pos) {
        for (int i = pos - 1; i < longitud_actual - 1; ++i) {
            contenedor[i] = contenedor[i + 1];
        }
        --longitud_actual;
    }

    void modificar(int pos, T elem) {
        contenedor[pos - 1] = elem;
    }

    std::string toString() const {
        if (esVacia()) return "";
        std::string texto = contenedor[0];
        for (int i = 1; i < longitud_actual; ++i) {
            texto += " | " + contenedor[i];
        }
        return texto;
    }
};


#endif //ACTV_GRUPAL_LISTA_H
