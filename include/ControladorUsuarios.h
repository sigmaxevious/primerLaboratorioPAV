#ifndef CONTROLADORUSUARIOS_H
#define CONTROLADORUSUARIOS_H

#include <string>
#include "IControladorUsuarios.h"
#include "DTFecha.h"

class ControladorUsuarios : public IControladorUsuarios {
private:
    // Memoria alta lector
    std::string ciLectorMem;
    std::string nombreLectorMem;
    std::string passwordLectorMem;
    DTFecha fechaRegistroLectorMem;

    // Memoria alta funcionario
    std::string ciFuncionarioMem;
    std::string nombreFuncionarioMem;
    std::string passwordFuncionarioMem;
    int numEmpleadoMem;

    // Memoria préstamo
    Lector* lectorPrestamoMem;
    Material* materialPrestamoMem;
    DTFecha fechaPrestamoMem;
    int diasDevolucionMem;

    // Memoria eliminar lector
    Lector* lectorAEliminarMem;

    // Acceso a colecciones
    ManejadorUsuarios* manejadorUsuarios;
    ManejadorMateriales* manejadorMateriales;

public:
    ControladorUsuarios();
    ~ControladorUsuarios();

    // Alta de usuarios
    DTLector* ingresarDatosLector(std::string ci, std::string nombre,
                                  std::string password, DTFecha fechaRegistro) override;

    DTFuncionario* ingresarDatosFuncionario(std::string ci, std::string nombre,
                                            std::string password, int numEmpleado) override;

    bool confirmarRegistro() override;
    void cancelar() override;

    // Préstamo
    DTLector* ingresarIDLector(std::string ci) override;
    DTMaterial* ingresarCodigoMaterial(std::string codigo) override;
    DTDatosPrestamo* ingresarDatosPrestamo(DTFecha fechaPrestamo, int diasDevolucion) override;
    void confirmarPrestamo() override;
    void cancelarPrestamo() override;

    // Consulta de préstamos
    DTLectorPrestamos* consultarPrestamosLector(std::string ci) override;

    // Eliminar lector
    DTLector* seleccionarLectorAEliminar(std::string ci) override;
    void confirmarEliminacionLector() override;
    void cancelarEliminacionLector() override;
};

#endif