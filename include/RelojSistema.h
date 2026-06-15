#ifndef RELOJSISTEMA_H
#define RELOJSISTEMA_H
#include <string>
#include "DTFecha.h"

class RelojSistema {
private:
    static RelojSistema* instancia;
    int dia, mes, anio, hora, minuto;
    RelojSistema();
public:
    static RelojSistema* getInstancia();
    void        setFecha(int dia, int mes, int anio, int hora, int minuto);
    DTFecha     getFecha() const;
    std::string toString() const;
    ~RelojSistema();
};
#endif