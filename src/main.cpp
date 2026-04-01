#include <iostream>
#include <string>
#include "../include/DTMaterial.h"
#include "../include/DTFecha.h"

enum Menu
{
    ing_opcion,
    reg_lector,
    ag_prestamo,
    obt_mats,
    cons_multa,
    ver_prestamos,
    ag_material,
    salir
};

int main()
{
    int opcionUser;

    std::cout << "Para continuar por favor elije una opción:" << "\n";
    std::cout << "1) Registrar un lector" << "\n";
    std::cout << "2) Agregar un préstamo" << "\n";
    std::cout << "3) Obtener materiales prestados" << "\n";
    std::cout << "4) Consultar multa" << "\n";
    std::cout << "5) Ver préstamos" << "\n";
    std::cout << "6) Agregar materiales" << "\n";
    std::cout << "7) Salir" << "\n";

    if (!(std::cin >> opcionUser))
    {
        std::cerr << "Opcion inválida";
        return 1;
    }

    Menu opc = static_cast<Menu>(opcionUser);
    switch (opc)
    {
    case 1:
        std::cout << "Ingresaste: " << opc;
        break;
    case 2:

        std::cout << "Ingresaste: " << opc;
        break;
    case 3:

        std::cout << "Ingresaste: " << opc;
        break;
    case 4:

        std::cout << "Ingresaste: " << opc;
        break;
    case 5:

        std::cout << "Ingresaste: " << opc;
        break;
    case 6:

        std::cout << "Ingresaste: " << opc;
        break;
    case 7:

        std::cout << "Ingresaste: " << opc;
        break;

    default:

        std::cout << "Ingresaste: " << opc;
        0;
    }

    return 1;
}

DTMaterial **verPrestamosAntesDeFecha(std::string ci, DTFecha *fecha, int &cantPrestamos)
{
}