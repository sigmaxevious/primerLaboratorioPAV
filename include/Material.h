#ifndef MATERIAL_H
#define MATERIAL_H
#include <string>

class Material
{
private:
    std::string codigo;
    std::string titulo;
    int anioPublicacion;
    int valorMultaPorDia;

public:
    std::string getCodigo();
    std::string getTitulo();
    int getAnioPublicacion();
    int getValorMultaPorDia();
    
    void setCodigo(std::string codigo);
    void setTitulo(std::string titulo);
    void setAnioPublicacion(int anioPublicacion);
    Material();
    Material(std::string codigo, std::string titulo, int anioPublicacion);
    Material(Material &c);
    virtual ~Material();
    virtual float calcularMulta(int diasAtraso) = 0;
};
#endif