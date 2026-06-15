#include "../include/ControladorMateriales.h"
#include "../include/ManejadorMateriales.h"
#include "../include/Libro.h"
#include "../include/Revista.h"
#include "../include/DTMaterial.h"
#include "../include/DTMaterialResumen.h"
#include <stdexcept>

ControladorMateriales::ControladorMateriales()
    : codigoMem(""), tituloMem(""), anioMem(0),
      esLibroMem(false), autorMem(""), cantPagMem(0),
      numEdicionMem(0), esMensualMem(false),
      materialMem(nullptr), materialAElim(nullptr) {}

ControladorMateriales::~ControladorMateriales() {}

// guardar datos generales en memoria
void ControladorMateriales::ingresarDatosMaterial(std::string codigo, std::string titulo, int anio) {
    this->codigoMem = codigo;
    this->tituloMem = titulo;
    this->anioMem   = anio;
}

void ControladorMateriales::ingresarDatosLibro(std::string autor, int cantPag) {
    this->esLibroMem  = true;
    this->autorMem    = autor;
    this->cantPagMem  = cantPag;
}

void ControladorMateriales::ingresarDatosRevista(int numEdicion, bool esMensual) {
    this->esLibroMem    = false;
    this->numEdicionMem = numEdicion;
    this->esMensualMem  = esMensual;
}

bool ControladorMateriales::confirmarRegistro() {
    Material* nuevo = nullptr;

    if (esLibroMem) {
        Libro* libro = new Libro(autorMem, cantPagMem);
        libro->setCodigo(codigoMem);
        libro->setTitulo(tituloMem);
        libro->setAnioPublicacion(anioMem);
        nuevo = libro;
    } else {
        Revista* revista = new Revista(numEdicionMem, esMensualMem);
        revista->setCodigo(codigoMem);
        revista->setTitulo(tituloMem);
        revista->setAnioPublicacion(anioMem);
        nuevo = revista;
    }

    try {
        ManejadorMateriales::getInstancia()->agregarMaterial(nuevo);
    } catch (...) {
        delete nuevo;
        throw;
    }

    // limpiar memoria
    codigoMem = tituloMem = autorMem = "";
    anioMem = cantPagMem = numEdicionMem = 0;
    esLibroMem = esMensualMem = false;

    return true;
}

void ControladorMateriales::cancelar() {
    codigoMem = tituloMem = autorMem = "";
    anioMem = cantPagMem = numEdicionMem = 0;
    esLibroMem = esMensualMem = false;
}

std::set<DTMaterialResumen*> ControladorMateriales::listarMateriales() {
    // stub: por ahora devuelve vacío
    return std::set<DTMaterialResumen*>();
}

DTMaterial* ControladorMateriales::seleccionarMaterial(std::string codigo) {
    Material* m = ManejadorMateriales::getInstancia()->findMaterial(codigo);
    if (m == nullptr)
        throw std::invalid_argument("Material no encontrado.");
    return m->crearDT();
}

DTMaterial* ControladorMateriales::seleccionarMaterialAEliminar(std::string codigo) {
    materialAElim = ManejadorMateriales::getInstancia()->findMaterial(codigo);
    if (materialAElim == nullptr)
        throw std::invalid_argument("Material no encontrado.");
    return materialAElim->crearDT();
}

void ControladorMateriales::confirmarEliminacionMaterial() {
    if (materialAElim == nullptr)
        throw std::invalid_argument("No hay material seleccionado para eliminar.");
    ManejadorMateriales::getInstancia()->eliminarMaterial(materialAElim->getCodigo());
    materialAElim = nullptr;
}

void ControladorMateriales::cancelarEliminacionMaterial() {
    materialAElim = nullptr;
}

Material* ControladorMateriales::getMaterial(std::string codigo) {
    return ManejadorMateriales::getInstancia()->findMaterial(codigo);
}