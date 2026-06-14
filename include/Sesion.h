#ifndef SESION_H
#define SESION_H
#include "Usuario.h"

class Sesion {
private:
    Usuario* usuarioAutenticado;

public:
    Sesion();
    Sesion(Usuario* usuario);
    void Cerrar();
    Usuario* getUsuarioAutenticado() const;
    void setUsuarioAutenticado(Usuario* usuario);
    ~Sesion();
};
#endif