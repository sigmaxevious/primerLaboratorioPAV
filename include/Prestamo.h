#ifndef PRESTAMO_H
#define PRESTAMO_H
#include "Material.h"
#include "DTFecha.h"
#include "DTPrestamo.h"

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
    int getDiasPermitidos();
    DTFecha getFechaPrestamo();
    Material* getMaterialPrestado();
    DTPrestamo getDTPermitidos();
    ~Prestamo();
};
#endif