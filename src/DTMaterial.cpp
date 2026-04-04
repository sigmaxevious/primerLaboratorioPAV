#include "../include/DTMaterial.h"
#include <string>

DTMaterial::DTMaterial()
{
    codigo = "";
    titulo = "";
    anioPublicacion = 0;
}

DTMaterial::DTMaterial(std::string codigo, std::string titulo, int anioPublicacion)
{
    this->codigo = codigo;
    this->titulo = titulo;
    this->anioPublicacion = anioPublicacion;
}

DTMaterial::DTMaterial(DTMaterial &c)
{
    this->codigo = c.codigo;
    this->titulo = c.titulo;
    this->anioPublicacion = c.anioPublicacion;
}

DTMaterial::~DTMaterial() {}
