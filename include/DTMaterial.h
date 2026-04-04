#ifndef DT_MATERIAL_H
#define DT_MATERIAL_H
#include <string>

class DTMaterial
{
public:
    std::string codigo;
    std::string titulo;
    int anioPublicacion;
    DTMaterial();
    DTMaterial(std::string codigo, std::string titulo, int anioPublicacion);
    DTMaterial(DTMaterial &c);
    virtual void imprimirInfo() const = 0;
    virtual ~DTMaterial();
};
#endif