#include "../include/DTLibro.h"
#include <string>

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
