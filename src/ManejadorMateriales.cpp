#include "../include/ManejadorMateriales.h"
#include <stdexcept>

ManejadorMateriales* ManejadorMateriales::instancia = nullptr;

ManejadorMateriales::ManejadorMateriales() {}

ManejadorMateriales* ManejadorMateriales::getInstancia() {
    if (instancia == nullptr)
        instancia = new ManejadorMateriales();
    return instancia;
}

void ManejadorMateriales::agregarMaterial(Material* material) {
    if (findMaterial(material->getCodigo()) != nullptr)
        throw std::invalid_argument("Ya existe un material con ese codigo.");
    materiales.insert(material);
}

Material* ManejadorMateriales::findMaterial(std::string codigo) {
    for (Material* m : materiales)
        if (m->getCodigo() == codigo) return m;
    return nullptr;
}

void ManejadorMateriales::eliminarMaterial(std::string codigo) {
    for (auto it = materiales.begin(); it != materiales.end(); ++it) {
        if ((*it)->getCodigo() == codigo) {
            delete *it;
            materiales.erase(it);
            return;
        }
    }
    throw std::invalid_argument("Material no encontrado.");
}

ManejadorMateriales::~ManejadorMateriales() {
    for (Material* m : materiales) delete m;
}