#ifndef LIBRO_H
#define LIBRO_H
#include "Material.h"

class Libro : public Material
{
private:
    char *autor;
    int cantPaginas;

public:
    char *getAutor();
    int getCantPaginas();
    void setAutor(char *autor);
    void setCantPAginas(int cantPaginas);
    Libro();
    Libro(char *autor, int cantPaginas);
    ~Libro();
    float calcularMulta(int diasAtraso) override;
};
#endif