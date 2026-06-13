#ifndef SESION_H
#define SESION_H
#include "Usuario.h"

class Sesion {
    private: Usuario* usuarioAutenticado;

    public: 
    Usuario* getUsuarioAutenticado();
    void setUsuarioAutenticado(Usuario* usuario);
    Sesion();
    ~Sesion();
    Sesion(Usuario* usuario);
    void Cerrar();
};
#endif
