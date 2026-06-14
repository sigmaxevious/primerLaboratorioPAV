#ifndef ICONTROLADORSESION_H
#define ICONTROLADORSESION_H

#include "Sesion.h"
class IControladorSesion {
public:
    virtual ~IControladorSesion() {}
    virtual bool iniciarSesion(std::string ci, std::string password) = 0;
    virtual void cerrarSesion() = 0;   
};
