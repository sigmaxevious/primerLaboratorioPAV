#ifndef USUARIO_H
#define USUARIO_H
#include "Prestamo.h"
#include <string>
#include "DTFecha.h"

class Usuario {

    private:
        std::string ci;
        std::string nombre;
        std::string password;
        // DTFecha fechaRegistro; esto será sólo de LECTOR
        Prestamo* prestamos[10];
        int cantidadPrestamos;

public:
    Usuario();
    Usuario(std::string ci, std::string nombre, std::string password);
    Usuario(Usuario &c);
    std::string getCi() const;
    std::string getNombre() const;
    std::string getPassword() const;
    // DTFecha getFecha() const; esto será sólo de LECTOR
    // int getCantidadPrestamos() const;
    // Prestamo** getPrestamos();
    // void addPrestamo(Prestamo* prestamo);
    ~Usuario();
};
#endif