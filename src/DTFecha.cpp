#include "DTFecha.h"

DTFecha::DTFecha() {
    dia = 0;
    mes = 0;
    año = 0;
}
DTFecha::DTFecha(int dia, int mes, int año) {
    this->dia = dia;
    this->mes = mes;
    this->año = año;
}
DTFecha::DTFecha(DTFecha &c) {
    this->dia = c.dia;
    this->mes = c.mes;
    this->año = c.año;
}
int DTFecha::getDia() {
    return dia;
}
int DTFecha::getMes() {
    return mes;
}
int DTFecha::getAño() {
    return año;
}
DTFecha::~DTFecha() {
}