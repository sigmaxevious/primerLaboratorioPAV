#ifndef CONTROLADORSESION_H
#define CONTROLADORSESION_H

#include "Sesion.h"
#include "IControladorSesion.h"
class ControladorSesion : public IControladorSesion {
private:
    Sesion* sesionActual;
public:
    ControladorSesion();
    ~ControladorSesion();

    bool iniciarSesion(std::string ci, std::string password) override;
    void cerrarSesion() override;
    bool hayFuncionarioActivo() override;
    bool hayLectorActivo() override;
};
#endif