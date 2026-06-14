#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
#include "Usuario.h"

class Funcionario : public Usuario {
private:
    int numEmpleado;

public:
    Funcionario();
    Funcionario(std::string ci, std::string nombre, std::string password, int numEmpleado);
    Funcionario(const Funcionario& c);
    int getNumEmpleado() const;
    ~Funcionario();
};
#endif