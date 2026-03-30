#ifndef DTLIBRO_H
#define DTLIBRO_H

class DTLibro
{
public:
    char *autor;
    int cantPaginas;
    DTLibro();
    DTLibro(char *autor, int cantPaginas);
    ~DTLibro();
};
#endif