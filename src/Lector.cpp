#include "../include/Lector.h"
#include <string>

Lector::Lector(std::string ci, std::string nombre, std::string password, DTFecha fechaRegistro)
    : Usuario(ci, nombre, password), fechaRegistro(fechaRegistro), cantidadPrestamos(0) {
    for (int i = 0; i < 10; i++) prestamos[i] = nullptr;
}
Lector::Lector()
{
    this->fechaRegistro = DTFecha();
    for (int i = 0; i < 10; i++) {
        this->prestamos[i] = nullptr;
    }
    this->cantidadPrestamos = 0;
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
