#include "../include/ControladorUsuarios.h"
#include "../include/ManejadorUsuarios.h"
#include "../include/ManejadorMateriales.h"
#include "../include/Lector.h"
#include "../include/Funcionario.h"
#include "../include/Prestamo.h"
#include "../include/DTLector.h"
#include "../include/DTFuncionario.h"
#include "../include/DTDatosPrestamo.h"
#include "../include/DTLectorPrestamos.h"
#include "../include/DTPrestamo.h"
#include <stdexcept>

ControladorUsuarios::ControladorUsuarios()
    : numEmpleadoMem(0), lectorPrestamoMem(nullptr),
      materialPrestamoMem(nullptr), diasDevolucionMem(0),
      lectorAEliminarMem(nullptr) {
    manejadorUsuarios  = ManejadorUsuarios::getInstancia();
    manejadorMateriales = ManejadorMateriales::getInstancia();
}

ControladorUsuarios::~ControladorUsuarios() {}

DTLector* ControladorUsuarios::ingresarDatosLector(std::string ci, std::string nombre,
                                                    std::string password, DTFecha fechaRegistro) {
    ciLectorMem       = ci;
    nombreLectorMem   = nombre;
    passwordLectorMem = password;
    fechaRegistroLectorMem = fechaRegistro;
    return new DTLector(ci, nombre, fechaRegistro);
}

DTFuncionario* ControladorUsuarios::ingresarDatosFuncionario(std::string ci, std::string nombre,
                                                               std::string password, int numEmpleado) {
    ciFuncionarioMem       = ci;
    nombreFuncionarioMem   = nombre;
    passwordFuncionarioMem = password;
    numEmpleadoMem         = numEmpleado;
    return new DTFuncionario(ci, nombre, numEmpleado);
}

bool ControladorUsuarios::confirmarRegistro() {
    if (!ciLectorMem.empty()) {
        Lector* l = new Lector(ciLectorMem, nombreLectorMem,
                                passwordLectorMem, fechaRegistroLectorMem);
        manejadorUsuarios->agregarUsuario(l);
        ciLectorMem = nombreLectorMem = passwordLectorMem = "";
    } else if (!ciFuncionarioMem.empty()) {
        Funcionario* f = new Funcionario(ciFuncionarioMem, nombreFuncionarioMem,
                                          passwordFuncionarioMem, numEmpleadoMem);
        manejadorUsuarios->agregarUsuario(f);
        ciFuncionarioMem = nombreFuncionarioMem = passwordFuncionarioMem = "";
        numEmpleadoMem = 0;
    } else {
        throw std::invalid_argument("No hay datos en memoria para confirmar.");
    }
    return true;
}

void ControladorUsuarios::cancelar() {
    ciLectorMem = nombreLectorMem = passwordLectorMem = "";
    ciFuncionarioMem = nombreFuncionarioMem = passwordFuncionarioMem = "";
    numEmpleadoMem = 0;
}

DTLector* ControladorUsuarios::ingresarIDLector(std::string ci) {
    lectorPrestamoMem = manejadorUsuarios->findLector(ci);
    if (lectorPrestamoMem == nullptr)
        throw std::invalid_argument("Lector no encontrado.");
    return new DTLector(lectorPrestamoMem->getCi(),
                        lectorPrestamoMem->getNombre(),
                        lectorPrestamoMem->getFecha());
}

DTMaterial* ControladorUsuarios::ingresarCodigoMaterial(std::string codigo) {
    materialPrestamoMem = manejadorMateriales->findMaterial(codigo);
    if (materialPrestamoMem == nullptr)
        throw std::invalid_argument("Material no encontrado.");
    return materialPrestamoMem->crearDT();
}

DTDatosPrestamo* ControladorUsuarios::ingresarDatosPrestamo(DTFecha fechaPrestamo, int diasDevolucion) {
    fechaPrestamoMem   = fechaPrestamo;
    diasDevolucionMem  = diasDevolucion;
    return new DTDatosPrestamo(fechaPrestamo, diasDevolucion);
}

void ControladorUsuarios::confirmarPrestamo() {
    if (lectorPrestamoMem == nullptr || materialPrestamoMem == nullptr)
        throw std::invalid_argument("Faltan datos para confirmar el prestamo.");
    Prestamo* p = new Prestamo(materialPrestamoMem, diasDevolucionMem, fechaPrestamoMem);
    lectorPrestamoMem->addPrestamo(p);
    lectorPrestamoMem    = nullptr;
    materialPrestamoMem  = nullptr;
    diasDevolucionMem    = 0;
}

void ControladorUsuarios::cancelarPrestamo() {
    lectorPrestamoMem   = nullptr;
    materialPrestamoMem = nullptr;
    diasDevolucionMem   = 0;
}

DTLectorPrestamos* ControladorUsuarios::consultarPrestamosLector(std::string ci) {
    Lector* lector = manejadorUsuarios->findLector(ci);
    if (lector == nullptr)
        throw std::invalid_argument("Lector no encontrado.");
    DTLectorPrestamos* resultado = new DTLectorPrestamos(lector->getNombre());
    for (int i = 0; i < lector->getCantidadPrestamos(); i++) {
        Prestamo* p = lector->getPrestamos()[i];
        DTPrestamo* dtp = new DTPrestamo(
            p->getMaterialPrestado()->getCodigo(),
            p->getMaterialPrestado()->getTitulo(),
            p->getFechaPrestamo(),
            p->getDiasPermitidos()
        );
        resultado->prestamos.push_back(dtp);
    }
    return resultado;
}

DTLector* ControladorUsuarios::seleccionarLectorAEliminar(std::string ci) {
    lectorAEliminarMem = manejadorUsuarios->findLector(ci);
    if (lectorAEliminarMem == nullptr)
        throw std::invalid_argument("Lector no encontrado.");
    return new DTLector(lectorAEliminarMem->getCi(),
                        lectorAEliminarMem->getNombre(),
                        lectorAEliminarMem->getFecha());
}

void ControladorUsuarios::confirmarEliminacionLector() {
    if (lectorAEliminarMem == nullptr)
        throw std::invalid_argument("No hay lector seleccionado.");
    manejadorUsuarios->eliminarUsuario(lectorAEliminarMem->getCi());
    lectorAEliminarMem = nullptr;
}

void ControladorUsuarios::cancelarEliminacionLector() {
    lectorAEliminarMem = nullptr;
}