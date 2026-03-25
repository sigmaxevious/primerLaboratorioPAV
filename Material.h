#ifndef MATERIAL_H
#define MATERIAL_H
#include <string>

class Material
{
private:
    char *codigo;
    char *titulo;
    int anioPublicacion;

public:
    char *getCodigo();
    char *getTitulo();
    int getAnioPublicacion();
    void setCodigo(char *codigo);
    void setTitulo(char *titulo);
    void setAnioPublicacion(int anioPublicacion);
    Material();
    Material(char *codigo, char *titulo, int anioPublicacion);
    virtual ~Material();
    virtual float calcularMulta(int diasAtraso) = 0;
};
#endif