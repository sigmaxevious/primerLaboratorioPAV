#include "../include/Usuario.h"

Usuario::Usuario() {
    this->ci       = "";
    this->nombre   = "";
    this->password = "";
}

Usuario::Usuario(std::string ci, std::string nombre, std::string password) {
    this->ci       = ci;
    this->nombre   = nombre;
    this->password = password;
}

std::string Usuario::getCi() const {
    return this->ci;
}

std::string Usuario::getNombre() const {
    return this->nombre;
}

std::string Usuario::getPassword() const {
    return this->password;
}

bool Usuario::checkPassword(std::string password) const {
    return this->password == password;
}

Usuario::~Usuario() {}