#ifndef CONTROLADORMATERIALES_H
#define CONTROLADORMATERIALES_H

#include <set>
#include <string>
#include "IControladorMateriales.h"
#include "Material.h"
#include "DTMaterial.h"
#include "DTMaterialResumen.h"

class ControladorMateriales : public IControladorMateriales {
private:
    std::string codigoMem;
    std::string tituloMem;
    int anioMem;
    bool esLibroMem;
    std::string autorMem;
    int cantPagMem;
    int numEdicionMem;
    bool esMensualMem;

    Material* materialMem;
    Material* materialAElim;

public:
    ControladorMateriales();
    ~ControladorMateriales();

    void ingresarDatosMaterial(std::string codigo, std::string titulo, int anio) override;
    void ingresarDatosLibro(std::string autor, int cantPag) override;
    void ingresarDatosRevista(int numEdicion, bool esMensual) override;
    bool confirmarRegistro() override;
    void cancelar() override;

    std::set<DTMaterialResumen*> listarMateriales() override;
    DTMaterial* seleccionarMaterial(std::string codigo) override;

    DTMaterial* seleccionarMaterialAEliminar(std::string codigo) override;
    void confirmarEliminacionMaterial() override;
    void cancelarEliminacionMaterial() override;

    Material* getMaterial(std::string codigo) override;
};

#endif