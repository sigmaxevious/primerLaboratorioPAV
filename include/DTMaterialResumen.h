#ifndef DTMATERIALRESUMEN_H
#define DTMATERIALRESUMEN_H
#include <string>

class DTMaterialResumen {
public:
    std::string codigo;
    std::string titulo;

    DTMaterialResumen();
    DTMaterialResumen(std::string codigo, std::string titulo);
    DTMaterialResumen(const DTMaterialResumen &c) = default;
    ~DTMaterialResumen();
};
#endif