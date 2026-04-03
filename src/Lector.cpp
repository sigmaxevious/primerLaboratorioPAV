#include "../include/Lector.h"
#include <string>

Lector::Lector()
{
    this->ci = 0;
    this->nombre = "";
    this->fechaRegistro = DTFecha();
    for (int i = 0; i < 10; i++) {
        this->prestamos[i] = nullptr;
    }
    this->cantidadPrestamos = 0;
}

Lector::Lector(int ci, string nombre, DTFecha fechaRegistro) {
    this->ci = ci;
    this->nombre = nombre;
    this->fechaRegistro = fechaRegistro;
    for (int i = 0; i < 10; i++) {
        this->prestamos[i] = nullptr;
    }
    this->cantidadPrestamos = 0;
    }

/* Lector::Lector(Lector &c) {
    this->ci = c.ci;
    this->nombre = c.nombre;
    this->fechaRegistro = c.fechaRegistro; 
    for (int i = 0; i < 10; i++) {
        this->prestamos[i] = c.prestamos[i];
    }
    this->cantidadPrestamos = c.cantidadPrestamos;
}
    Constructor por copia es problemático, lo voy a dejar de lado, comentado pa decirle a Carlos si lo necesita */
int Lector::GetCi() const {
    return this->ci;
}
string Lector::getNombre() const  {
    return this->nombre;
}
DTFecha Lector::getFecha() const {
    return this->fechaRegistro;
}
int Lector::getCantidadPrestamos() const {
    return this->cantidadPrestamos;
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
