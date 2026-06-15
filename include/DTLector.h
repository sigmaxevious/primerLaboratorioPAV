#ifndef DTLECTOR_H
#define DTLECTOR_H
#include <string>
#include "DTFecha.h"

class DTLector {
public:
    std::string ci;
    std::string nombre;
    DTFecha     fechaRegistro;

    DTLector();
    DTLector(std::string ci, std::string nombre, DTFecha fechaRegistro);
    DTLector(const DTLector &c) = default;
    DTLector &operator=(const DTLector &c) = default;
    ~DTLector();
};
#endif