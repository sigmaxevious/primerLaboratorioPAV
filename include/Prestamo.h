#ifndef PRESTAMO_H
#define PRESTAMO_H
#include "Material.h"

class Prestamo
{
private:
    Material *material;
    DTFecha fechaPrestamo;
    int diasPermitidos;

public:
    Prestamo();
    Prestamo(Material *material, int diasPermitidos, DTFecha fechaPrestamo);
    Prestamo(Prestamo &c);
    int getDíasPermitidos();
    DTFecha getFechaPrestamo();
    Material getMaterialPrestado();
};
#endif