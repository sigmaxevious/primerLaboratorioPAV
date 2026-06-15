#ifndef DTFUNCIONARIO_H
#define DTFUNCIONARIO_H
#include <string>

class DTFuncionario {
public:
    std::string ci;
    std::string nombre;
    int         numEmpleado;

    DTFuncionario();
    DTFuncionario(std::string ci, std::string nombre, int numEmpleado);
    DTFuncionario(const DTFuncionario &c) = default;
    DTFuncionario &operator=(const DTFuncionario &c) = default;
    ~DTFuncionario();
};
#endif