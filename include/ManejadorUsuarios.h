#ifndef MANEJADORUSUARIOS_H
#ifndef MANEJADORUSUARIOS_H
#define MANEJADORUSUARIOS_H

#include <string>
#include "Usuario.h"
#include "Lector.h"
#include "Funcionario.h"

class ManejadorUsuarios {
    private: Usuario* usuarios[100];
    int topeUsuarios;

public:
    ManejadorUsuarios();
    ManejadorUsuarios* getInstancia();
    void agregarUsuario(Usuario* usuario);
    Usuario* findUsuario(std::string ci);
    Lector* findLector(std::string ci);
    Funcionario* findFuncionario(std::string ci);
    void eliminarUsuario(std::string ci);
    ~ManejadorUsuarios();
}   