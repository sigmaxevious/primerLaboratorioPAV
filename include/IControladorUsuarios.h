#ifndef ICONTROLADORUSUARIOS_H
#define ICONTROLADORUSUARIOS_H

#include <string>
#include "DTFecha.h"
#include "DTMaterial.h"
#include "DTPrestamo.h"
#include "DTLector.h"
#include "DTFuncionario.h"
#include "DTDatosPrestamo.h"
#include "DTLectorPrestamos.h"

class IControladorUsuarios {
public:
    virtual DTLector* ingresarDatosLector(std::string ci, std::string nombre,
                                          std::string password, DTFecha fechaRegistro) = 0;

    virtual DTFuncionario* ingresarDatosFuncionario(std::string ci, std::string nombre,
                                                    std::string password, int numEmpleado) = 0;

    virtual bool confirmarRegistro() = 0;
    virtual void cancelar() = 0;

    virtual DTLector* ingresarIDLector(std::string ci) = 0;
    virtual DTMaterial* ingresarCodigoMaterial(std::string codigo) = 0;
    virtual DTDatosPrestamo* ingresarDatosPrestamo(DTFecha fechaPrestamo, int diasDevolucion) = 0;
    virtual void confirmarPrestamo() = 0;
    virtual void cancelarPrestamo() = 0;

    virtual DTLectorPrestamos* consultarPrestamosLector(std::string ci) = 0;

    virtual DTLector* seleccionarLectorAEliminar(std::string ci) = 0;
    virtual void confirmarEliminacionLector() = 0;
    virtual void cancelarEliminacionLector() = 0;

    virtual ~IControladorUsuarios() {}
};

#endif