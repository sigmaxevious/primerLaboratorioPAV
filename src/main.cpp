#include <iostream>
#include <istream>
#include <sstream>
#include <string>
#include <vector>
#include "../include/Material.h"
#include "../include/Lector.h"
#include "../include/Libro.h"
#include "../include/Revista.h"
#include "../include/Prestamo.h"
#include "../include/DTMaterial.h"
#include "../include/DTLibro.h"
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
    Lector * lectores[100];
    int cantLectores = 0;
    Material* materiales[100];
    int cantMateriales = 0;
    while ( opcionUser != 7 ) {

        
        std::cout << "Para continuar por favor elije una opción:" << "\n";
        std::cout << "1) Registrar un lector" << "\n"; /// 
        std::cout << "2) Agregar un préstamo" << "\n";
        std::cout << "3) Obtener materiales prestados" << "\n";
        std::cout << "4) Consultar multa de material" << "\n";
        std::cout << "5) Ver préstamos antes de fecha" << "\n";
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
            {
                try {
                    std::cout << "Por favor ingresa los siguientes campos para registrar un nuevo lector: \n";

                    std::cout << "Por favor ingresa los siguientes campos para registrar un nuevo lector: \n";
                    std::cout << "Cédula de identidad: \n";
                    int ci;
                    std::cin >> ci;

                    if (buscarLector(lectores, cantLectores, ci) != nullptr) {
                        throw std::invalid_argument("Ya existe un lector registrado con esa cédula");
                    }
                    
                    std::cout << "Nombre: \n";
                    std::string nombre;
                    
                    std::cin >> nombre;
                    std::getline(std::cin >> std::ws, nombre);
                    if (nombre.empty())
                        throw std::invalid_argument("El nombre no puede estar vacío.");

                    
                    std::cout << "Fecha de nacimiento: (dd/mm/aaaa) \n";
                    std::string fechaString;
                    std::cin >> fechaString;
                    
                    std::stringstream ss(fechaString);
                    std::string segment;
                    std::vector<std::string> seglist;
                    
                    while(std::getline(ss, segment, '/')) {
                        seglist.push_back(segment);
                    }
                    int dia, mes, year;
                        try {
                            dia  = std::stoi(seglist[0]);
                            mes  = std::stoi(seglist[1]);
                            year = std::stoi(seglist[2]);
                        } catch (...) {
                            throw std::invalid_argument("La fecha debe contener solo números.");
                        }
                    DTFecha fechaNacimiento(dia, mes, year);
                    
                    
                    lectores[cantLectores++] = new Lector(ci, nombre, fechaNacimiento);
                    std::cout << "Lector registrado exitosamente \n";
                    } catch (const std::invalid_argument& e) {
                    std::cerr << "Error: " << e.what() << "\n";
                    continue; 
            }
                        break;
                    }
            case 2:
            {
                try {
                    if (cantLectores == 0)
                        throw std::invalid_argument("No hay lectores registrados.");
                    if (cantMateriales == 0)
                        throw std::invalid_argument("No hay materiales registrados.");

                    std::cout << "Cédula del lector: \n";
                    int ci;
                    if (!(std::cin >> ci)) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        throw std::invalid_argument("La cédula debe ser un número entero.");
                    }
                    Lector* lector = buscarLector(lectores, cantLectores, ci);
                    if (lector == nullptr)
                        throw std::invalid_argument("No existe un lector con esa cédula.");

                    std::cout << "Código del material: \n";
                    std::string codigo;
                    std::cin >> codigo;

                    Material* material = nullptr;
                    for (int i = 0; i < cantMateriales; i++) {
                        if (materiales[i]->getCodigo() == codigo) {
                            material = materiales[i];
                            break;
                        }
                    }
                    if (material == nullptr)
                        throw std::invalid_argument("No existe un material con ese código.");

                    std::cout << "Días permitidos: \n";
                    int dias;
                    if (!(std::cin >> dias)) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        throw std::invalid_argument("Los días deben ser un número entero.");
                    }
                    if (dias <= 0)
                        throw std::invalid_argument("Los días deben ser mayor a 0.");

                    std::cout << "Fecha del préstamo: (dd/mm/aaaa) \n";
                    std::string fechaString;
                    std::cin >> fechaString;

                    std::stringstream ss(fechaString);
                    std::string segment;
                    std::vector<std::string> seglist;
                    while (std::getline(ss, segment, '/'))
                        seglist.push_back(segment);

                    if (seglist.size() != 3)
                        throw std::invalid_argument("Formato de fecha inválido. Use dd/mm/aaaa.");

                    int dia, mes, year;
                    try {
                        dia  = std::stoi(seglist[0]);
                        mes  = std::stoi(seglist[1]);
                        year = std::stoi(seglist[2]);
                    } catch (...) {
                        throw std::invalid_argument("La fecha debe contener solo números.");
                    }
                    DTFecha fechaPrestamo(dia, mes, year);
                    lector->agregarPrestamo(new Prestamo(material, dias, fechaPrestamo));
                    std::cout << "Préstamo agregado exitosamente.\n";

                } catch (const std::invalid_argument& e) {
                    std::cerr << "Error: " << e.what() << "\n";
                    continue;
                }
                break;
            }
            case 3:
            
            break;
            case 4:
            // --- para consultar la multa se necesita el codigo del material, obtener el valor de la multa y multiplicar por el numero de dias de atraso
            // --- para obtener el numero de dias de atraso se necesita la fecha del prestamo, la fecha actual y los dias permitidos del prestamo
            // --- la fecha actual se puede obtener con <ctime>
            {
                try {
                    std::cout << "Código del material: \n";
                    std::string codigo;
                    std::cin >> codigo;

                    Material* mat = nullptr;
                    for (int i = 0; i < cantMateriales; i++) {
                        if (materiales[i]->getCodigo() == codigo) {
                            mat = materiales[i];
                            break;
                        }
                    }
                    if (mat == nullptr)
                        throw std::invalid_argument("No existe un material con ese código.");

                    std::cout << "Cédula del lector: \n";
                    int ci;
                    std::cin >> ci;
                    Lector* lector = buscarLector(lectores, cantLectores, ci);
                    if (lector == nullptr)
                        throw std::invalid_argument("No existe un lector con esa cédula.");

                    // Encontrar el prestamo del material recibido
                    Prestamo* prestamo = nullptr;

                    while (lector->getPrestamos() != nullptr) {
                                    Prestamo*p = lector->getPrestamos();
                                    if (p->getMaterialPrestado().getCodigo() == codigo) {
                                        prestamo = p;break;
                                    }
                                }
                    if (prestamo == nullptr)
                        throw std::invalid_argument("El lector no tiene un préstamo de ese material.");

                    int diasFechaPrestamo = fechaADias(prestamo->getFechaPrestamo());
                    int fechaDevolucion = diasFechaPrestamo + prestamo->getDíasPermitidos();
                    int hoy = obtenerHoy();
                    int diasAtraso = hoy - fechaDevolucion;

                    if (diasAtraso <= 0) {
                        std::cout << "El préstamo está al día, no hay multa.\n";
                    } else {
                        float multa = mat->calcularMulta(diasAtraso);
                        std::cout << "Días de atraso: " << diasAtraso << "\n";
                        std::cout << "Multa total: $" << multa << "\n";
                    }

                } catch (const std::invalid_argument& e) {
                    std::cerr << "Error: " << e.what() << "\n";
                    continue;
                }
                break;
            }
            case 5:
            
            break;
            case 6:
            {
                try {
                    if (cantMateriales >= 100)
                        throw std::invalid_argument("No se pueden agregar más materiales.");

                    std::cout << "Tipo de material:\n";
                    std::cout << "1) Libro\n";
                    std::cout << "2) Revista\n";
                    int tipo;
                    if (!(std::cin >> tipo) || (tipo != 1 && tipo != 2)) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        throw std::invalid_argument("Tipo de material inválido.");
                    }

                    std::cout << "Código: \n";
                    std::string codigo;
                    std::getline(std::cin >> std::ws, codigo);
                    if (codigo.empty())
                        throw std::invalid_argument("El código no puede estar vacío.");

                    for (int i = 0; i < cantMateriales; i++)
                        if (materiales[i]->getCodigo() == codigo)
                            throw std::invalid_argument("Ya existe un material con ese código.");

                    std::cout << "Título: \n";
                    std::string titulo;
                    std::getline(std::cin >> std::ws, titulo);
                    if (titulo.empty())
                        throw std::invalid_argument("El título no puede estar vacío.");

                    std::cout << "Año de publicación: \n";
                    int anio;
                    if (!(std::cin >> anio)) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        throw std::invalid_argument("El año debe ser un número entero.");
                    }
                
                    Material* nuevoMaterial = nullptr;

                    if (tipo == 1) {
                        std::cout << "Autor: \n";
                        std::string autor;
                        std::getline(std::cin >> std::ws, autor);
                        if (autor.empty())
                            throw std::invalid_argument("El autor no puede estar vacío.");

                        std::cout << "Cantidad de páginas: \n";
                        int paginas;
                        if (!(std::cin >> paginas)) {
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            throw std::invalid_argument("La cantidad de páginas debe ser un número entero.");
                        }
                        if (paginas <= 0)
                            throw std::invalid_argument("La cantidad de páginas debe ser mayor a 0.");

                        Libro* libro = new Libro(autor, paginas);
                        libro->setCodigo(codigo);
                        libro->setTitulo(titulo);
                        libro->setAnioPublicacion(anio);
                        nuevoMaterial = libro;

                    } else {
                        std::cout << "Número de edición: \n";
                        int edicion;
                        if (!(std::cin >> edicion)) {
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            throw std::invalid_argument("El número de edición debe ser un número entero.");
                        }
                        if (edicion <= 0)
                            throw std::invalid_argument("El número de edición debe ser mayor a 0.");

                        std::cout << "¿Es mensual? (1 = sí, 0 = no): \n";
                        bool esMensual;
                        if (!(std::cin >> esMensual)) {
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            throw std::invalid_argument("Ingresa 1 o 0 para mensual.");
                        }

                        Revista* revista = new Revista(edicion, esMensual);
                        revista->setCodigo(codigo);
                        revista->setTitulo(titulo);
                        revista->setAnioPublicacion(anio);
                        nuevoMaterial = revista;
                    }

                    materiales[cantMateriales++] = nuevoMaterial;
                    std::cout << "Material agregado exitosamente.\n";

                } catch (const std::invalid_argument& e) {
                    std::cerr << "Error: " << e.what() << "\n";
                    continue;
                }
                break;
            }
            case 7:
            break;
            
            default:
            std::cerr << "Opción inválida.\n";
        }
        
    }
        return 1;
    }

DTMaterial **verPrestamosAntesDeFecha(std::string ci, DTFecha *fecha, int &cantPrestamos)
{
}

Lector* buscarLector(Lector* lectores[], int cant, int ci) {
    for (int i = 0; i < cant; i++)
        if (lectores[i]->getCi() == ci)
            return lectores[i];
    return nullptr;
}

int fechaADias(DTFecha fecha) {
    return fecha.getAnio() * 365 + fecha.getMes() * 30 + fecha.getDia();
}

int obtenerHoy() {
    time_t t = time(nullptr);
    tm* hoy = localtime(&t);
    return (hoy->tm_year + 1900) * 365 + (hoy->tm_mon + 1) * 30 + hoy->tm_mday;
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