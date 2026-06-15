#include "../include/ControladorSesion.h"
#include "../include/ManejadorUsuarios.h"
#include "../include/Funcionario.h"
#include "../include/Lector.h"
#include <stdexcept>

ControladorSesion::ControladorSesion() : sesionActual(nullptr) {}

ControladorSesion::~ControladorSesion() {
    delete sesionActual;
}

bool ControladorSesion::iniciarSesion(std::string ci, std::string password) {
    if (sesionActual != nullptr)
        throw std::invalid_argument("Ya hay una sesion activa.");
    Usuario* u = ManejadorUsuarios::getInstancia()->findUsuario(ci);
    if (u == nullptr || !u->checkPassword(password))
        return false;
    sesionActual = new Sesion(u);
    return true;
}

void ControladorSesion::cerrarSesion() {
    if (sesionActual == nullptr)
        throw std::invalid_argument("No hay sesion activa.");
    delete sesionActual;
    sesionActual = nullptr;
}

bool ControladorSesion::hayFuncionarioActivo() {
    if (sesionActual == nullptr) return false;
    return dynamic_cast<Funcionario*>(sesionActual->getUsuarioAutenticado()) != nullptr;
}

bool ControladorSesion::hayLectorActivo() {
    if (sesionActual == nullptr) return false;
    return dynamic_cast<Lector*>(sesionActual->getUsuarioAutenticado()) != nullptr;
}
