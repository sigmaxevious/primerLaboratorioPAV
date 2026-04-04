#ifndef DTREVISTA_H
#define DTREVISTA_H
#include "DTMaterial.h"

class DTRevista : public DTMaterial
{
public:
    int numeroEdicion;
    bool esMensual;
    DTRevista();
    DTRevista(int numeroEdicion, bool esMensual);
    DTRevista(DTRevista &c);
    ~DTRevista();
    void imprimirInfo() const override;
};
#endif