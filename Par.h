//
// Created by Eddy Lucandy on 14/6/24.
//

#ifndef ACTV_GRUPAL_PAR_H
#define ACTV_GRUPAL_PAR_H

#include <iostream>
#include <string>
#include "Lista.h"
#pragma once

using namespace std;

// Clase Par
template <typename Atributo, typename Valor>
class Par {
private:
    Atributo atributo;
    Valor valor;

public:
    Par() : atributo(Atributo()), valor(Valor()) {}

    Par(Atributo a, Valor v) : atributo(a), valor(v) {}

    void setAtributo(Atributo a) {
        atributo = a;
    }

    void setValor(Valor v) {
        valor = v;
    }

    Atributo getAtributo() const {
        return atributo;
    }

    Valor getValor() const {
        return valor;
    }

    std::string toString() const {
        return "(" + std::to_string(atributo) + ", " + std::to_string(valor) + ")";
    }
};

#endif //ACTV_GRUPAL_PAR_H
