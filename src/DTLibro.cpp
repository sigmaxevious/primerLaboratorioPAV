#include "../include/DTLibro.h"
#include <string>
#include <iostream>

DTLibro::DTLibro()
{
    autor = "";
    cantPaginas = 0;
}

DTLibro::DTLibro(std::string autor, int cantPaginas)
{
    this->autor = autor;
    this->cantPaginas = cantPaginas;
}

DTLibro::DTLibro(DTLibro &c)
{
    this->autor = c.autor;
    this->cantPaginas = c.cantPaginas;
}

DTLibro::~DTLibro() {}

void DTLibro::imprimirInfo() const {
    std::cout << "--- LIBRO ---\n";
    std::cout << "Código: " << codigo << "\n";
    std::cout << "Título: " << titulo << "\n";
    std::cout << "Año: " << anioPublicacion << "\n";
    std::cout << "Autor: " << autor << "\n";
    std::cout << "Páginas: " << cantPaginas << "\n";
}
