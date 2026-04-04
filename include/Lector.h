#ifndef LECTOR_H
#define LECTOR_H
#include "Prestamo.h"
#include <string>
#include "DTFecha.h"

class Lector {
    private:
        std::string ci;
        std::string nombre;
        DTFecha fechaRegistro;
        Prestamo* prestamos[10];
        int cantidadPrestamos;

public:
    Lector();
    Lector(std::string ci, std::string nombre, DTFecha fechaNacimiento);
    Lector(Lector &c);
    std::string getCi() const;
    std::string getNombre() const;
    DTFecha getFecha() const;
    int getCantidadPrestamos() const;
    Prestamo** getPrestamos();
    void addPrestamo(Prestamo* prestamo);
    ~Lector();
};
#endif