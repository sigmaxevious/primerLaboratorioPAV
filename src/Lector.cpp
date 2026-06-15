#include "../include/Lector.h"
#include <string>

Lector::Lector()
{
    this->fechaRegistro = DTFecha();
    for (int i = 0; i < 10; i++) {
        this->prestamos[i] = nullptr;
    }
    this->cantidadPrestamos = 0;
}

Lector::Lector(DTFecha fechaRegistro) {
    this->fechaRegistro = fechaRegistro;
    for (int i = 0; i < 10; i++) {
        this->prestamos[i] = nullptr;
    }
    this->cantidadPrestamos = 0;
    }


std::string Lector::getNombre() const  {
    return this->nombre;
}
DTFecha Lector::getFecha() const {
    return this->fechaRegistro;
}
int Lector::getCantidadPrestamos() const {
    return this->cantidadPrestamos;
}
Prestamo** Lector::getPrestamos() {
    return this->prestamos;
}
void Lector::addPrestamo(Prestamo* prestamo) {
    if (cantidadPrestamos < 10) {
        prestamos[cantidadPrestamos] = prestamo;
        cantidadPrestamos++;
    }
}
Lector::~Lector() {
    for (int i = 0; i < cantidadPrestamos; i++) {
        delete prestamos[i];
    }
}
