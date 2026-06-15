#ifndef MANEJADOUSUARIOS_H
#define MANEJADOUSUARIOS_H
#include <set>
#include <string>
#include "Usuario.h"

class Lector;

class ManejadorUsuarios {
private:
    static ManejadorUsuarios* instancia;
    std::set<Usuario*> usuarios;
    ManejadorUsuarios();
public:
    static ManejadorUsuarios* getInstancia();
    void        agregarUsuario(Usuario* usuario);
    Usuario*    findUsuario(std::string ci);
    Lector*     findLector(std::string ci);
    void        eliminarUsuario(std::string ci);
    std::set<Usuario*> getUsuarios() const;
    ~ManejadorUsuarios();
};
#endif