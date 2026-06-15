#include "../include/DTFuncionario.h"

DTFuncionario::DTFuncionario() : ci(""), nombre(""), numEmpleado(0) {}

DTFuncionario::DTFuncionario(std::string ci, std::string nombre, int numEmpleado) {
    this->ci          = ci;
    this->nombre      = nombre;
    this->numEmpleado = numEmpleado;
}

DTFuncionario::~DTFuncionario() {}