#include "../include/DTMaterialResumen.h"

DTMaterialResumen::DTMaterialResumen() : codigo(""), titulo("") {}

DTMaterialResumen::DTMaterialResumen(std::string codigo, std::string titulo) {
    this->codigo = codigo;
    this->titulo = titulo;
}

DTMaterialResumen::~DTMaterialResumen() {}