#include "../include/Fabrica.h"
#include "../include/ControladorMateriales.h"
#include "../include/ControladorSesion.h"
#include "../include/ControladorUsuarios.h"

Fabrica* Fabrica::instancia = nullptr;

Fabrica::Fabrica() {}

Fabrica* Fabrica::getInstancia() {
    if (instancia == nullptr)
        instancia = new Fabrica();
    return instancia;
}

IControladorMateriales* Fabrica::getControladorMateriales() {
    return new ControladorMateriales();
}

IControladorSesion* Fabrica::getControladorSesion() {
    return new ControladorSesion();
}

IControladorUsuarios* Fabrica::getControladorUsuarios() {
    return new ControladorUsuarios();
}