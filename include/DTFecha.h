#ifndef DTFECHA_H
#define DTFECHA_H

class DTFecha
{
private:
    int dia;
    int mes;
    int anio;

public:
    DTFecha();
    DTFecha(int dia, int mes, int anio);
    DTFecha(DTFecha &c);
    int getDia();
    int getMes();
    int getAnio();
    ~DTFecha();
};
#endif