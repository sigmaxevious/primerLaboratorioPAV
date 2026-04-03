#include "../include/Revista.h"
#include <string>

Revista::Revista()
{
    numeroEdicion = 0;
    esMensual = false;
}

Revista::Revista(int numeroEdicion, bool esMensual)
{
    this->numeroEdicion = numeroEdicion;
    this->esMensual = esMensual;
}

Revista::Revista(Revista &c)
{
    this->numeroEdicion = c.numeroEdicion;
    this->esMensual = c.esMensual;
}

Revista::~Revista() {}

int Revista::getNumeroEdicion()
{
    return numeroEdicion;
}

bool Revista::siesMensual()
{
    return esMensual;
}

void Revista::setNumeroEdicion(int numeroEdicion)
{
    this->numeroEdicion = numeroEdicion;
}

void Revista::setEsMensual(bool esMensual)
{
    this->esMensual = esMensual;
}

float Revista::calcularMulta(int diasAtraso)
{
    return diasAtraso * 2.0;
}
