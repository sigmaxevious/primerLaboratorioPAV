#include "../include/Libro.h"
#include <string>

Libro::Libro()
{
    autor = "";
    cantPaginas = 0;
}

Libro::Libro(std::string autor, int cantPaginas)
{
    this->autor = autor;
    this->cantPaginas = cantPaginas;
}

Libro::Libro(Libro &c)
{
    this->autor = c.autor;
    this->cantPaginas = c.cantPaginas;
}

Libro::~Libro() {}

std::string Libro::getAutor()
{
    return autor;
}

int Libro::getCantPaginas()
{
    return cantPaginas;
}

void Libro::setAutor(std::string autor)
{
    this->autor = autor;
}

void Libro::setCantPaginas(int cantPaginas)
{
    this->cantPaginas = cantPaginas;
}

float Libro::calcularMulta(int diasAtraso)
{
    return diasAtraso * 5.0;
}
