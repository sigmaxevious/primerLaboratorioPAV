#ifndef MATERIAL_H
#define MATERIAL_H
#include <string>
#include "DTMaterial.h"
#include "DTMaterialResumen.h"

class Material
{
private:
    std::string codigo;
    std::string titulo;
    int anioPublicacion;
public:
    std::string getCodigo() const;
    std::string getTitulo() const;
    int getAnioPublicacion() const;
    void setCodigo(std::string codigo);
    void setTitulo(std::string titulo);
    void setAnioPublicacion(int anioPublicacion);
    Material();
    Material(std::string codigo, std::string titulo, int anioPublicacion);
    Material(Material &c);
    virtual DTMaterial* crearDT() = 0;
    virtual DTMaterialResumen* crearDTMaterialResumen() = 0;
    virtual ~Material();
    virtual float calcularMulta(int diasAtraso) = 0;
};
#endif  