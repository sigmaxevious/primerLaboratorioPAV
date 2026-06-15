#include "../include/DTDatosPrestamo.h"

DTDatosPrestamo::DTDatosPrestamo() : fechaPrestamo(), diasDevolucion(0) {}

DTDatosPrestamo::DTDatosPrestamo(DTFecha fechaPrestamo, int diasDevolucion) {
    this->fechaPrestamo  = fechaPrestamo;
    this->diasDevolucion = diasDevolucion;
}

DTDatosPrestamo::~DTDatosPrestamo() {}