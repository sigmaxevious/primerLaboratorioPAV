#include "../include/RelojSistema.h"
#include <sstream>
#include <iomanip>

RelojSistema* RelojSistema::instancia = nullptr;

RelojSistema::RelojSistema() {
    this->dia    = 1;
    this->mes    = 1;
    this->anio   = 2026;
    this->hora   = 0;
    this->minuto = 0;
}

RelojSistema* RelojSistema::getInstancia() {
    if (instancia == nullptr)
        instancia = new RelojSistema();
    return instancia;
}

void RelojSistema::setFecha(int dia, int mes, int anio, int hora, int minuto) {
    this->dia    = dia;
    this->mes    = mes;
    this->anio   = anio;
    this->hora   = hora;
    this->minuto = minuto;
}

DTFecha RelojSistema::getFecha() const {
    return DTFecha(this->dia, this->mes, this->anio);
}

std::string RelojSistema::toString() const {
    std::ostringstream oss;
    oss << std::setfill('0')
        << std::setw(2) << this->dia    << "/"
        << std::setw(2) << this->mes    << "/"
        << this->anio                   << " "
        << std::setw(2) << this->hora   << ":"
        << std::setw(2) << this->minuto;
    return oss.str();
}

RelojSistema::~RelojSistema() {}