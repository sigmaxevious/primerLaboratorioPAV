#include "Prestamo.h"
#include <string>
#include "DTFecha.h"

class Lector {
    private:
    int ci;
    string nombre;
    DTFecha fechaNacimiento;
    Prestamo* prestamos[10];

    public:
    Lector();
    Lector(int ci, string nombre, DTFecha fechaNacimiento);
    Lector(Lector &c);
    int getCi();
    string getNombre();
    DTFecha getFecha();
    ~Lector();
}