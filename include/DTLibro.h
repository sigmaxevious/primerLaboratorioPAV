#ifndef DTLIBRO_H
#define DTLIBRO_H
#include <string>
#include "DTMaterial.h"

class DTLibro : public DTMaterial
{
public:
    std::string autor;
    int cantPaginas;
    DTLibro();
    DTLibro(std::string autor, int cantPaginas);
    DTLibro(DTLibro &c);
    ~DTLibro();
    void imprimirInfo() const override;
};
#endif