#ifndef MANEJADORMATERIALES_H
#define MANEJADORMATERIALES_H

#include <set>
#include <string>
#include "Material.h"

struct CompararMaterial {
    bool operator()(Material* a, Material* b) const {
        return a->getCodigo() < b->getCodigo();
    }
};

class ManejadorMateriales {
private:
    static ManejadorMateriales* instancia;
    std::set<Material*, CompararMaterial> materiales;

    ManejadorMateriales();

public:
    static ManejadorMateriales* getInstancia();
    void agregarMaterial(Material* material);
    Material* findMaterial(std::string codigo);
    void eliminarMaterial(std::string codigo);
    ~ManejadorMateriales();
};

#endif