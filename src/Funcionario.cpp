#include "../include/Funcionario.h"

Funcionario::Funcionario() : Usuario(), numEmpleado(0) {}

Funcionario::Funcionario(std::string ci, std::string nombre,
                          std::string password, int numEmpleado)
    : Usuario(ci, nombre, password) {
    this->numEmpleado = numEmpleado;
}

int Funcionario::getNumEmpleado() const {
    return this->numEmpleado;
}

Funcionario::~Funcionario() {}