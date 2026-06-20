#ifndef DTFECHA_H
#define DTFECHA_H
#include <string>
#include <sstream>

class DTFecha
{
private:
    int dia;
    int mes;
    int anio;

public:
    DTFecha();
    DTFecha(int dia, int mes, int anio);
    DTFecha(const DTFecha &c) = default;
    DTFecha &operator=(const DTFecha &c) = default;
    int getDia() const;
    int getMes() const;
    int getAnio() const;
    // Compara la primera fecha con la segunda, devuelve true si la primera es menor a la segunda, false en caso contrario
    bool esAnterior(const DTFecha &otra) const;
    ~DTFecha();
    std::string toString() const;
};
#endif
