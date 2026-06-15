#ifndef FABRICA_H
#define FABRICA_H

#include "IControladorMateriales.h"
#include "IControladorSesion.h"
#include "IControladorUsuarios.h"

class Fabrica {
private:
    static Fabrica* instancia;
    Fabrica();

public:
    static Fabrica* getInstancia();
    IControladorMateriales* getControladorMateriales();
    IControladorSesion*     getControladorSesion();
    IControladorUsuarios*   getControladorUsuarios();
};

#endif