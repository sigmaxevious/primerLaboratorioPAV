#include <iostream>
#include <string>
#include <stdexcept> 
#include "../include/Lector.h"
#include "../include/Material.h"
#include "../include/DTMaterial.h"

using namespace std;
Lector* buscarLectorPorCI(string ci);

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
Lector* lectores[MAX_LECTORES];

// -- FUNCIONES --
void registrarLector(string ci, string nombre, DTFecha* fechaRegistro){
    if (topeLectores < MAX_LECTORES) {
        lectores[topeLectores] = new Lector(ci, nombre, *fechaRegistro);
        topeLectores++;
    } else {
        std::cout << "No se pueden registrar más lectores. Capacidad máxima alcanzada." << std::endl;
    }
}
void agregarPrestamo(string ciLector, Material* material, int diasPermitidos, DTFecha* fechaPrestamo) {
    Lector* lector = buscarLectorPorCI(ciLector);
    if (lector == nullptr) {
        throw std::invalid_argument("El lector no existe en el sistema."); // Requisito 
    }
    
    // Se crea el préstamo y se vincula al lector
    Prestamo* nuevoPrestamo = new Prestamo(material, diasPermitidos, *fechaPrestamo);
    lector->addPrestamo(nuevoPrestamo);
}
DTMaterial** obtenerMaterialesPrestados(string ciLector, int& cantMateriales) {
    Lector* lector = buscarLectorPorCI(ciLector);
    if (lector == nullptr) {
        throw std::invalid_argument("Lector no encontrado.");
    }

    cantMateriales = lector->getCantidadPrestamos();
    
    DTMaterial** resultado = new DTMaterial*[cantMateriales];
    
    for(int i = 0; i < cantMateriales; i++) {
        Prestamo* p = lector->getPrestamos()[i];
        Material* m = p->getMaterialPrestado(); // Usar puntero, no el objeto directo
        resultado[i] = m->crearDT(); 
    }
    return resultado;
}
Lector* buscarLectorPorCI(string ci) {
    for (int i = 0; i < topeLectores; i++) {
        if (lectores[i]->getCi() == ci) {
            return lectores[i]; // Se encontró el lector
        }
    }   
    return nullptr; // No se encontró
}

int main() {
    int opcionUser = -1; // Inicializar para entrar al bucle
    bool salirSistema = false;

    while (!salirSistema) {
        // 1. Mostrar el menú completo aquí adentro para que se repita
        std::cout << "\n--- BIBLIOTECA ---" << std::endl;
        std::cout << "1) Registrar un lector" << std::endl;
        std::cout << "2) Agregar un préstamo" << std::endl;
        std::cout << "3) Obtener materiales prestados" << std::endl;
        std::cout << "4) Consultar multa de material" << std::endl;
        std::cout << "5) Ver préstamos antes de fecha" << std::endl;
        std::cout << "6) Agregar material" << std::endl;
        std::cout << "7) Salir" << std::endl;
        std::cout << "Opción: ";

        if (!(std::cin >> opcionUser)) {
            std::cerr << "Entrada inválida" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        Menu opc = static_cast<Menu>(opcionUser);

        try {
            switch (opc) {
                case reg_lector: { // Usa los nombres del Enum
                    std::cout << "Registrar un lector" << std::endl;
                    std::string nombreLector, ciLector;
                    
                    std::cin.ignore(); // LIMPIEZA CLAVE antes de getline
                    std::cout << "Ingrese nombre: ";
                    std::getline(std::cin, nombreLector); 
                    
                    std::cout << "Ingrese CI: ";
                    std::cin >> ciLector;
                    
                    std::cout << "Fecha (dd mm aaaa): ";
                    int d, m, a;
                    std::cin >> d >> m >> a;
                    
                    DTFecha* fechaActual = new DTFecha(d, m, a);
                    registrarLector(ciLector, nombreLector, fechaActual);
                    std::cout << "Lector registrado." << std::endl;
                    break;
                }
                case salir:
                    salirSistema = true;
                    break;
                default:
                    std::cout << "Opción no válida." << std::endl;
                    break;
            }
        } catch (const std::invalid_argument& e) {
            // Aquí atrapas los errores de CI no encontrada, etc. [4]
            std::cerr << "ERROR: " << e.what() << std::endl;
        }
    }
    return 0; // 0 indica éxito
}

DTMaterial **verPrestamosAntesDeFecha(std::string ci, DTFecha *fecha, int &cantPrestamos)
{
    return nullptr; // Implementación por hacer
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