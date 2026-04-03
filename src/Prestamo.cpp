#include "../include/Prestamo.h"
#include "../include/DTFecha.h"
Prestamo::Prestamo()
{
    this->material = nullptr;
    this->fechaPrestamo = DTFecha();
    this->diasPermitidos = 0;

}
Prestamo::Prestamo(Material *material, int diasPermitidos, DTFecha fechaPrestamo)
{
    this->material = material;
    this->fechaPrestamo = fechaPrestamo;
    this->diasPermitidos = diasPermitidos;
}

Prestamo::Prestamo(Prestamo &c)
{
    this->material = c.material;
    this->fechaPrestamo = c.fechaPrestamo;
    this->diasPermitidos = c.diasPermitidos;
}

int Prestamo::getDiasPermitidos()
{
    return diasPermitidos;
}

DTFecha Prestamo::getFechaPrestamo()
{
    return fechaPrestamo;
}

Material Prestamo::getMaterialPrestado()
{
    return *material;
}

Prestamo::~Prestamo() {
    delete material;
}