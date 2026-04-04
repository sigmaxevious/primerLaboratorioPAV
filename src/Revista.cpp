#include "../include/Revista.h"
#include "../include/DTRevista.h"
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

DTMaterial* Revista::crearDT() {
    DTRevista* dtRevista = new DTRevista();
    dtRevista->numeroEdicion = this->numeroEdicion;
    dtRevista->esMensual = this->esMensual;
    dtRevista->codigo = this->getCodigo();
    dtRevista->titulo = this->getTitulo();
    dtRevista->anioPublicacion = this->getAnioPublicacion();
    return dtRevista;
}
