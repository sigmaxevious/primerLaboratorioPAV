#include "../include/DTLector.h"

DTLector::DTLector() : ci(""), nombre(""), fechaRegistro() {}

DTLector::DTLector(std::string ci, std::string nombre, DTFecha fechaRegistro) {
    this->ci            = ci;
    this->nombre        = nombre;
    this->fechaRegistro = fechaRegistro;
}

DTLector::~DTLector() {}