#include "../include/DTMaterialInfo.h"

DTMaterialInfo::DTMaterialInfo() : codigo(""), titulo(""), anioPublicacion(0), tipoMaterial(""), puntajePromedio(0.0f) {}

DTMaterialInfo::DTMaterialInfo(std::string codigo, std::string titulo, int anio,
                                std::string tipo, float puntaje) {
    this->codigo          = codigo;
    this->titulo          = titulo;
    this->anioPublicacion = anio;
    this->tipoMaterial    = tipo;
    this->puntajePromedio = puntaje;
}

DTMaterialInfo::~DTMaterialInfo() {}