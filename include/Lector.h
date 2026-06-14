#ifndef LECTOR_H
#define LECTOR_H
#include "Prestamo.h"
#include <string>
#include "DTFecha.h"
#include "Usuario.h"

class Lector : public Usuario
{
    private:
        DTFecha fechaRegistro;
        Prestamo* prestamos[10];
        int cantidadPrestamos;

public:
    Lector();
    Lector(std::string ci, std::string nombre, std::string password, DTFecha fechaRegistro);
    Lector(const Lector& c);
    DTFecha getFecha() const;
    int getCantidadPrestamos() const;
    Prestamo** getPrestamos();
    void addPrestamo(Prestamo* prestamo);
    ~Lector();
};
#endif