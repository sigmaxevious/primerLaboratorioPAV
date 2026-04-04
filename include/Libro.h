#ifndef LIBRO_H
#define LIBRO_H
#include "Material.h"
#include <string>

class Libro : public Material
{
private:
    std::string autor;
    int cantPaginas;

public:
    std::string getAutor();
    int getCantPaginas();
    void setAutor(std::string autor);
    void setCantPaginas(int cantPaginas);
    Libro();
    Libro(std::string autor, int cantPaginas);
    ~Libro();
    float calcularMulta(int diasAtraso) override;
    DTMaterial* crearDT() override;
};
#endif