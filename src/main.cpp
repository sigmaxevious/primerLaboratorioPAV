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
int topeLectores = 0;
Lector lectores[MAX_LECTORES];

// -- FUNCIONES --
void registrarLector(int ci, string nombre, DTFecha fechaRegistro){
    if (topeLectores < MAX_LECTORES) {
        lectores[topeLectores] = new Lector(ci, nombre, fechaRegistro);
        topeLectores++;
    } else {
        std::cout << "No se pueden registrar más lectores. Capacidad máxima alcanzada." << std::endl;
    }
}
void agregarPrestamo(int ciLector, Material* material, int diasPermitidos, DTFecha fechaPrestamo){
    if (topeLectores == 0) {
        std::cout << "No hay lectores registrados. Por favor, registre un lector antes de agregar un préstamo." << std::endl;
        return;
    }   
    if Lector* lector = buscarLectorPorCI(ciLector) {
        Prestamo* nuevoPrestamo = new Prestamo(material, diasPermitidos, fechaPrestamo);
        lector->addPrestamo(nuevoPrestamo);
    } else {
        std::cout << "Lector con CI " << ciLector << " no encontrado. Por favor, registre el lector antes de agregar un préstamo." << std::endl;
    }
}
DTMaterial* obtenerMaterialesPrestados(int ciLector){
    Lector* lector = buscarLectorPorCI(ciLector);
    if (lector) {
        for(int i = 0; i < lector->getCantidadPrestamos(); i++) {
            Prestamo* prestamo = lector->getPrestamos()[i];
            Material materialPrestado = prestamo->getMaterialPrestado();
            std::cout << "Material prestado: " << materialPrestado.getTitulo() << std::endl;
        }
    } else {
        std::cout << "Lector con CI " << ciLector << " no encontrado." << std::endl;
        return nullptr;
    }
}
Lector* buscarLectorPorCI(string ci) {
    for (int i = 0; i < topeLectores; i++) {
        if (lectores[i]->getCi() == ci) {
            return lectores[i]; // Se encontró el lector
        }
    }
    return nullptr; // No se encontró
}

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