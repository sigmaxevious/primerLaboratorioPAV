#ifndef DTREVISTA_H
#define DTREVISTA_H

class DTRevista
{
public:
    int numeroEdicion;
    bool esMensual;
    DTRevista();
    DTRevista(int numeroEdicion, bool esMensual);
    DTRevista(DTRevista &c);
    ~DTRevista();
};
#endif