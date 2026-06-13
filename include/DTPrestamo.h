#ifndef DTPRESTAMO_H
#define DTPRESTAMO_H
#include "Material.h"
#include "DTFecha.h"

class DTPrestamo
{
    Material *material;
    DTFecha fechaPrestamo;

public:
    std::string codigoMaterial;
    std::string tituloMaterial;
    DTFecha fechaPrestamo;
    int diasPermitidos;
    DTPrestamo();
    DTPrestamo(Material *material, int diasPermitidos, DTFecha fechaPrestamo);
    DTPrestamo(DTPrestamo &c);
    int getDiasPermitidos();
    DTFecha getFechaPrestamo();
    Material* getMaterialPrestado();
    ~DTPrestamo();
};
#endif