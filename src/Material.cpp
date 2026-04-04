#include "../include/Material.h"

Material::Material()
{
    codigo = "";
    titulo = "";
    anioPublicacion = 0;
}

Material::Material(std::string codigo, std::string titulo, int anioPublicacion)
{
    this->codigo = codigo;
    this->titulo = titulo;
    this->anioPublicacion = anioPublicacion;
}

Material::Material(Material &c)
{
    this->codigo = c.codigo;
    this->titulo = c.titulo;
    this->anioPublicacion = c.anioPublicacion;
}

std::string Material::getCodigo() const
{
    return codigo;
}

std::string Material::getTitulo() const
{
    return titulo;
}

int Material::getAnioPublicacion() const
{
    return anioPublicacion;
}

void Material::setCodigo(std::string codigo)
{
    this->codigo = codigo;
}

void Material::setTitulo(std::string titulo)
{
    this->titulo = titulo;
}

void Material::setAnioPublicacion(int anioPublicacion)
{
    this->anioPublicacion = anioPublicacion;
}

DTMaterial *Material::crearDT()
{
    return nullptr;
}

Material::~Material() {}
