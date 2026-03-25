#include "Lector.h"
#include "Material.h"

class Prestamo{
    private:
        Material* material;
        DTFecha fechaPrestamo;
        int diasPermitidos;
    public:
        Prestamo();
        Prestamo(int diasPermitidos,DTFecha fechaPrestamo);
        Prestamo(Prestamo &c);
        int getDíasPermitidos();
        DTFecha getFechaPrestamo();
        Material getMaterialPrestado();
    }