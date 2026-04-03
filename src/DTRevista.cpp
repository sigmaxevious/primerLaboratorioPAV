#include "../include/DTRevista.h"
#include <string>

DTRevista::DTRevista()
{
    numeroEdicion = 0;
    esMensual = false;
}

DTRevista::DTRevista(int numeroEdicion, bool esMensual)
{
    this->numeroEdicion = numeroEdicion;
    this->esMensual = esMensual;
}

DTRevista::DTRevista(DTRevista &c)
{
    this->numeroEdicion = c.numeroEdicion;
    this->esMensual = c.esMensual;
}
