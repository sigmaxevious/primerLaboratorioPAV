#ifndef DTFECHA_H
#define DTFECHA_H

class DTFecha{
    private:
        int dia;
        int mes;
        int anio;
    public:
        DTFecha();
        DTFecha(int dia, int mes, int anio);
        DTFecha(const DTFecha &c);
        int getDia() const;
        int getMes() const;
        int getAnio() const;
        // Compara la primera fecha con la segunda, devuelve true si la primera es menor a la segunda, false en caso contrario
        bool esmenorFecha(DTFecha fechaComparada, DTFecha fecha2);
        ~DTFecha();
};
#endif
