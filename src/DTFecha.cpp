#include "../include/DTFecha.h"
#include <string>

DTFecha::DTFecha()
{
    dia = 0;
    mes = 0;
    anio = 0;
}
DTFecha::DTFecha(int dia, int mes, int anio)
{
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}
DTFecha::DTFecha(DTFecha &c)
{
    this->dia = c.dia;
    this->mes = c.mes;
    this->anio = c.anio;
}
int DTFecha::getDia()
{
    return dia;
}
int DTFecha::getMes()
{
    return mes;
}
int DTFecha::getAnio()
{
    return anio;
}
DTFecha::~DTFecha()
{
}