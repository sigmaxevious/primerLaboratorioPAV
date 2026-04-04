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

bool DTFecha::esmenorFecha(DTFecha fechaComparada, DTFecha fecha2) {
    if (fechaComparada.anio < fecha2.anio) {
        return true;
    } else if (fechaComparada.anio == fecha2.anio) {
        if (fechaComparada.mes < fecha2.mes) {
            return true;
        } else if (fechaComparada.mes == fecha2.mes) {
            if (fechaComparada.dia < fecha2.dia) {
                return true;
            }
        }
    }
    return false;
}
DTFecha::~DTFecha()
{
}