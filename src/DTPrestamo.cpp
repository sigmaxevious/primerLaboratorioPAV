#include "../include/DTPrestamo.h"

DTPrestamo::DTPrestamo() : codigoMaterial(""), tituloMaterial(""), fechaPrestamo(), diasPermitidos(0) {}

DTPrestamo::DTPrestamo(std::string codigoMaterial, std::string tituloMaterial,
                       DTFecha fechaPrestamo, int diasPermitidos) {
    this->codigoMaterial = codigoMaterial;
    this->tituloMaterial = tituloMaterial;
    this->fechaPrestamo  = fechaPrestamo;
    this->diasPermitidos = diasPermitidos;
}

DTPrestamo::~DTPrestamo() {}