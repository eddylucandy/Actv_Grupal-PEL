#ifndef CASA_H
#define CASA_H

#include <iostream>

class Casa {
public:
    Casa() {}

    void visitarCasa() const {
        std::cout << "Visitando una casa. El residente dice: ¡Buena suerte en tu viaje!" << std::endl;
    }

    void mostrarCasa() const {
        std::cout << "Casa" << std::endl;
    }
};

#endif // CASA_H
