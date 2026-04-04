#include "../include/DTRevista.h"
#include <iostream>

DTRevista::DTRevista()
{
    numeroEdicion = 0;
    esMensual = false;
}

DTRevista::DTRevista(int numeroEdicion, bool esMensual)
{
    this->numeroEdicion = numeroEdicion;
    this->esMensual = esMensual;
}

DTRevista::DTRevista(DTRevista &c)
{
    this->numeroEdicion = c.numeroEdicion;
    this->esMensual = c.esMensual;
}

DTRevista::~DTRevista() {}

void DTRevista::imprimirInfo() const {
    std::cout << "--- REVISTA ---\n";
    std::cout << "Código: " << codigo << "\n";
    std::cout << "Título: " << titulo << "\n";
    std::cout << "Año: " << anioPublicacion << "\n";
    std::cout << "Edición: " << numeroEdicion << "\n";
    std::cout << "Es mensual: " << (esMensual ? "Sí" : "No") << "\n";
}
