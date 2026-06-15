#ifndef DTLECTORPRESTAMOS_H
#define DTLECTORPRESTAMOS_H
#include <string>
#include <vector>
#include "DTPrestamo.h"

class DTLectorPrestamos {
public:
    std::string              nombreLector;
    std::vector<DTPrestamo*> prestamos;

    DTLectorPrestamos();
    DTLectorPrestamos(std::string nombreLector);
    ~DTLectorPrestamos();
};
#endif