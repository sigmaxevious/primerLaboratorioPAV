#ifndef DT_MATERIAL_H
#define DT_MATERIAL_H

class DTMaterial
{
public:
    char *codigo;
    char *titulo;
    int anioPublicacion;
    DTMaterial();
    DTMaterial(char *codigo, char *titulo, int anioPublicacion);
    ~DTMaterial();
};
#endif