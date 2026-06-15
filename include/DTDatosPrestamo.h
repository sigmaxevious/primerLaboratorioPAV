#ifndef DTDATOSPRESTAMO_H
#define DTDATOSPRESTAMO_H
#include "DTFecha.h"

class DTDatosPrestamo {
public:
    DTFecha fechaPrestamo;
    int     diasDevolucion;

    DTDatosPrestamo();
    DTDatosPrestamo(DTFecha fechaPrestamo, int diasDevolucion);
    DTDatosPrestamo(const DTDatosPrestamo &c) = default;
    DTDatosPrestamo &operator=(const DTDatosPrestamo &c) = default;
    ~DTDatosPrestamo();
};
#endif