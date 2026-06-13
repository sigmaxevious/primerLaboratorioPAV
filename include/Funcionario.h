#ifndef LECTOR_H
#define LECTOR_H
#include "Prestamo.h"
#include <string>
#include "DTFecha.h"

class Funcionario public : Usuario
{
    private:
        int numEmpleado;

public:
    Lector();
    Lector(DTFecha fechaNacimiento);
    Lector(Lector &c);

    DTFuncionario getDTFuncionario();
    ~Lector();
};
#endif