#ifndef REVISTA_H
#define REVISTA_H
#include "Material.h"

class Revista : public Material
{
private:
    int numeroEdicion;
    bool esMensual;

public:
    () int getNumeroEdicion();
    bool isEsMensual();
    void setNumeroEdicion(int cantPaginas);
    void setEsMensual(bool esMensual);
    Revista();
    Revista(int numeroEdicion, bool esMensual);
    ~Revista();
    float calcularMulta(int diasAtraso) override;
};
#endif