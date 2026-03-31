#ifndef DTLIBRO_H
#define DTLIBRO_H
#include <string>

class DTLibro
{
public:
    std::string autor;
    int cantPaginas;
    DTLibro();
    DTLibro(std::string autor, int cantPaginas);
    ~DTLibro();
};
#endif