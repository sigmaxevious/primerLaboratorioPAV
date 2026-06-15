#ifndef DTMATERIALDETALLE_H
#define DTMATERIALDETALLE_H
#include <string>

class DTMaterialDetalle {
public:
    std::string titulo;
    int         totalPuntajes;
    float       puntajePromedio;

    DTMaterialDetalle();
    DTMaterialDetalle(std::string titulo, int totalPuntajes, float puntajePromedio);
    DTMaterialDetalle(const DTMaterialDetalle &c) = default;
    ~DTMaterialDetalle();
};
#endif