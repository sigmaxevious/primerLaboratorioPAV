#include "../include/ManejadorUsuarios.h"
#include "../include/Lector.h"
#include <stdexcept>

ManejadorUsuarios* ManejadorUsuarios::instancia = nullptr;

ManejadorUsuarios::ManejadorUsuarios() {}

ManejadorUsuarios* ManejadorUsuarios::getInstancia() {
    if (instancia == nullptr)
        instancia = new ManejadorUsuarios();
    return instancia;
}

void ManejadorUsuarios::agregarUsuario(Usuario* usuario) {
    if (findUsuario(usuario->getCi()) != nullptr)
        throw std::invalid_argument("Ya existe un usuario con esa CI.");
    usuarios.insert(usuario);
}

Usuario* ManejadorUsuarios::findUsuario(std::string ci) {
    for (Usuario* u : usuarios)
        if (u->getCi() == ci) return u;
    return nullptr;
}

Lector* ManejadorUsuarios::findLector(std::string ci) {
    for (Usuario* u : usuarios) {
        Lector* l = dynamic_cast<Lector*>(u);
        if (l != nullptr && l->getCi() == ci) return l;
    }
    return nullptr;
}

void ManejadorUsuarios::eliminarUsuario(std::string ci) {
    for (auto it = usuarios.begin(); it != usuarios.end(); ++it) {
        if ((*it)->getCi() == ci) {
            delete *it;
            usuarios.erase(it);
            return;
        }
    }
    throw std::invalid_argument("Usuario no encontrado.");
}

std::set<Usuario*> ManejadorUsuarios::getUsuarios() const {
    return this->usuarios;
}

ManejadorUsuarios::~ManejadorUsuarios() {
    for (Usuario* u : usuarios) delete u;
}  