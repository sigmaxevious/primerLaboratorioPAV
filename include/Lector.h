#ifndef LECTOR_H
#define LECTOR_H
#include "Prestamo.h"
#include <string>
#include "DTFecha.h"

class Lector
{
private:
    int ci;
    std::string nombre;
    DTFecha fechaNacimiento;
    Prestamo *prestamos[10];

public:
    Lector();
    Lector(int ci, std::string nombre, DTFecha fechaNacimiento);
    Lector(Lector &c);
    int getCi();
    std::string getNombre();
    DTFecha getFecha();
    ~Lector();
};
#endif