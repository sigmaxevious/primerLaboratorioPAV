#include "Lector.h"
#include <string>

Lector::Lector()
{
    this->ci = 0;
    this->nombre = "";
    this->fechaNacimiento = DTFecha();
    for (int i = 0; i < 10; i++)
    {
        this->prestamos[i] = nullptr;
    }
}

Lector::Lector(int ci, std::string nombre, DTFecha fechaNacimiento)
{
    this->ci = ci;
    this->nombre = nombre;
    this->fechaNacimiento = fechaNacimiento;
    for (int i = 0; i < 10; i++)
    {
        this->prestamos[i] = nullptr;
    }
}
void Lector::agregarPrestamo (Prestamo * prestamo ) {
    for (int i =0; i<10; i++) {
        if (this->prestamos[i] == nullptr) {
            this->prestamos[i] = prestamo;
            break;
        }
    }
}
