#ifndef ICONTROLADORUSUARIOS_H
#define ICONTROLADORUSUARIOS_H
#include "DTLibro.h"
#include "DTMaterial.h"

class IControladorUsuarios{
    public:
virtual void ingresarDatosMaterial(codigo : string, titulo : string, anio : integer) : void
virtual void ingresarDatosLibro(autor : string, cantPaginas : integer) : DTLibro
virtual void ingresarDatosRevista(numEdicion : integer, esMensual : boolean) : DTRevista
virtual bool confirmarRegistro() : bool
virtual void cancelar() : void
virtual Set<DTMaterialResumen> listarMateriales() : Set<DTMaterialResumen>
virtual DTMaterialInfo seleccionarMaterial(codigo : string) : DTMaterialInfo
virtual DTMaterialInfo seleccionarMaterialAEliminar(codigo : string) : DTMaterialInfo
virtual void confirmarEliminacionMaterial();
virtual void cancelarEliminacionMaterial();
}


