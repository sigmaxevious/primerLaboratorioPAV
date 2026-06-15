#ifndef DTMATERIALINFO_H
#define DTMATERIALINFO_H
#include <string>

class DTMaterialInfo {
public:
    std::string codigo;
    std::string titulo;
    int         anioPublicacion;
    std::string tipoMaterial;
    float       puntajePromedio;

    DTMaterialInfo();
    DTMaterialInfo(std::string codigo, std::string titulo, int anio,
                   std::string tipo, float puntaje);
    DTMaterialInfo(const DTMaterialInfo &c) = default;
    ~DTMaterialInfo();
};
#endif