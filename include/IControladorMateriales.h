#ifndef ICONTROLADORMATERIALES_H
#define ICONTROLADORMATERIALES_H

#include <set>
#include <string>
#include "DTMaterial.h"

class Material;

class IControladorMateriales {
public:
    virtual void ingresarDatosMaterial(std::string codigo, std::string titulo, int anio) = 0;
    virtual void ingresarDatosLibro(std::string autor, int cantPag) = 0;
    virtual void ingresarDatosRevista(int numEdicion, bool esMensual) = 0;
    virtual bool confirmarRegistro() = 0;
    virtual void cancelar() = 0;

    virtual std::set<DTMaterialResumen*> listarMateriales() = 0;
    virtual DTMaterial* seleccionarMaterial(std::string codigo) = 0;

    virtual DTMaterial* seleccionarMaterialAEliminar(std::string codigo) = 0;
    virtual void confirmarEliminacionMaterial() = 0;
    virtual void cancelarEliminacionMaterial() = 0;

    virtual Material* getMaterial(std::string codigo) = 0;

    virtual ~IControladorMateriales() {}
};

#endif