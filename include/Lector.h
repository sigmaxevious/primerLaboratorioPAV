#include "Prestamo.h"
#include <string>
#include "DTFecha.h"

class Lector {
    private:
        int ci;
        string nombre;
        DTFecha fechaRegistro;
        Prestamo* prestamos[10];
        int cantidadPrestamos;

    public:
    Lector();
    Lector(int ci, string nombre, DTFecha fechaRegistro);
    Lector(Lector &c);
    int getCi();
    string getNombre();
    DTFecha getFecha();
    void addPrestamo(Prestamo* prestamo);
    ~Lector();
}