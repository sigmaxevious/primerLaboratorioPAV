#include "../include/Sesion.h"
#include "../include/Usuario.h"

Sesion::Sesion(Usuario* usuario) {
    this->usuarioAutenticado = usuario;
}

Usuario* Sesion::getUsuarioAutenticado() const {
    return this->usuarioAutenticado;
}

Sesion::~Sesion() {}