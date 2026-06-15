#ifndef DTPRESTAMO_H
#define DTPRESTAMO_H
#include <string>
#include "DTFecha.h"

class DTPrestamo {
public:
    std::string codigoMaterial;
    std::string tituloMaterial;
    DTFecha     fechaPrestamo;
    int         diasPermitidos;

    DTPrestamo();
    DTPrestamo(std::string codigoMaterial, std::string tituloMaterial,
               DTFecha fechaPrestamo, int diasPermitidos);
    DTPrestamo(const DTPrestamo &c) = default;
    DTPrestamo &operator=(const DTPrestamo &c) = default;
    ~DTPrestamo();
};
#endif