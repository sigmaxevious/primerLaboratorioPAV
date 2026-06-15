#include "../include/DTMaterialDetalle.h"

DTMaterialDetalle::DTMaterialDetalle() : titulo(""), totalPuntajes(0), puntajePromedio(0.0f) {}

DTMaterialDetalle::DTMaterialDetalle(std::string titulo, int totalPuntajes, float puntajePromedio) {
    this->titulo          = titulo;
    this->totalPuntajes   = totalPuntajes;
    this->puntajePromedio = puntajePromedio;
}

DTMaterialDetalle::~DTMaterialDetalle() {}