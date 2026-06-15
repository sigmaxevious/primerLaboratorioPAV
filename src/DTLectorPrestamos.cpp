#include "../include/DTLectorPrestamos.h"

DTLectorPrestamos::DTLectorPrestamos() : nombreLector("") {}

DTLectorPrestamos::DTLectorPrestamos(std::string nombreLector) {
    this->nombreLector = nombreLector;
}

DTLectorPrestamos::~DTLectorPrestamos() {
    for (DTPrestamo* p : this->prestamos) delete p;
}