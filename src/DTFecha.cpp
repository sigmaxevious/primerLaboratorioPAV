#include "../include/DTFecha.h"

DTFecha::DTFecha() {
    dia = 1;
    mes = 1;
    anio = 1900;
}
DTFecha::DTFecha(int dia, int mes, int anio)
{
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}
DTFecha::DTFecha(const DTFecha &c) {
    this->dia = c.dia;
    this->mes = c.mes;
    this->anio = c.anio;
}
int DTFecha::getDia() const {
    return dia;
}
int DTFecha::getMes() const {
    return mes;
}
int DTFecha::getAnio() const {
    return anio;
}

bool DTFecha::esAnterior(const DTFecha &otra) const {
    if (this->anio < otra.anio) {
        return true;
    } else if (this->anio == otra.anio) {
        if (this->mes < otra.mes) {
            return true;
        } else if (this->mes == otra.mes) {
            if (this->dia < otra.dia) {
                return true;
            }
        }
    }
    return false;
}
DTFecha::~DTFecha()
{
}