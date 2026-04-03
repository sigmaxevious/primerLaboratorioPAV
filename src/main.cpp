#include <iostream>
#include <string>
#define MAX_LECTORES 50

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

// -- FUNCIONES --
void registrarLector(int ci, string nombre, DTFecha fechaRegistro);
void agregarPrestamo(int ciLector, Material* material, int diasPermitidos, DTFecha fechaPrestamo);
DTMaterial* obtenerMaterialesPrestados(int ciLector);

int main () {
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
    switch (opc) {
        case 1:
                std::cout << "Registrar un lector" << std::endl;
                std::cout << "Ingrese nombre del lector: ";
                std::fflush(stdin); // Limpiar el buffer si vienes de leer un int
                std::getline(std::cin, nombreLector); 
                std::cout << "Ingrese la CI: ";
                std::cin >> ciLector;
                std::cout << "Ingrese la fecha de registro (dd mm aaaa): ";
                std::cin >> dia >> mes >> anio;
                registrarLector(ciLector, nombreLector, fechaActual);
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

bool esPrestamoAnterioraFecha(DTFecha *fechaPrestamo, DTFecha *fecha)
{
    if (fechaPrestamo->getAnio() > fecha->getAnio())
        return false;
    else if (fechaPrestamo->getAnio() < fecha->getAnio())
        return true;
    else
    {
        if (fechaPrestamo->getMes() > fecha->getMes())
            return false;
        else if (fechaPrestamo->getMes() < fecha->getMes())
            return true;
        else
        {
            return fechaPrestamo->getDia() < fecha->getDia();
        }
    }
}