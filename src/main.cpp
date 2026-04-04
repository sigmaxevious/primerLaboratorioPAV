#include "../include/DTFecha.h"
#include "../include/DTLibro.h"
#include "../include/DTMaterial.h"
#include "../include/DTRevista.h"
#include "../include/Lector.h"
#include "../include/Libro.h"
#include "../include/Material.h"
#include "../include/Prestamo.h"
#include "../include/Revista.h"
#include <ctime>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

using namespace std;

#define MAX_LECTORES 100
#define MAX_MATERIALES 100

// -- GLOBALS --
int topeLectores = 0;
Lector *lectores[MAX_LECTORES];

int topeMateriales = 0;
Material *materiales[MAX_MATERIALES];

// -- MENÚ ENUM --
enum Menu
{
    ing_opcion = 0,
    reg_lector,
    ag_prestamo,
    obt_mats,
    cons_multa,
    ver_prestamos,
    ag_material,
    salir
};

// -- HELPER FUNCTIONS --
Lector *buscarLectorPorCI(string ci)
{
    for (int i = 0; i < topeLectores; i++)
    {
        if (lectores[i]->getCi() == ci)
        {
            return lectores[i];
        }
    }
    return nullptr;
}

Material *buscarMaterialPorCodigo(string codigo)
{
    for (int i = 0; i < topeMateriales; i++)
    {
        if (materiales[i]->getCodigo() == codigo)
        {
            return materiales[i];
        }
    }
    return nullptr;
}

int fechaADias(DTFecha fecha)
{
    return fecha.getAnio() * 365 + fecha.getMes() * 30 + fecha.getDia();
}

int obtenerHoy()
{
    time_t t = time(nullptr);
    tm *hoy = localtime(&t);
    return (hoy->tm_year + 1900) * 365 + (hoy->tm_mon + 1) * 30 + hoy->tm_mday;
}

// -- MAIN LOGIC FUNCTIONS --

void registrarLector(string ci, string nombre, DTFecha *fechaRegistro)
{
    if (topeLectores >= MAX_LECTORES)
    {
        throw std::invalid_argument(
            "No se pueden registrar más lectores. Capacidad máxima alcanzada.");
    }
    if (buscarLectorPorCI(ci) != nullptr)
    {
        throw std::invalid_argument(
            "Ya existe un lector registrado con esa cédula");
    }
    lectores[topeLectores++] = new Lector(ci, nombre, *fechaRegistro);
    delete fechaRegistro;
}

void agregarPrestamo(string ciLector, string codigoMat, int diasPermitidos,
                     DTFecha *fechaPrestamo)
{
    Lector *lector = buscarLectorPorCI(ciLector);
    if (lector == nullptr)
    {
        throw std::invalid_argument("El lector no existe en el sistema.");
    }
    Material *material = buscarMaterialPorCodigo(codigoMat);
    if (material == nullptr)
    {
        throw std::invalid_argument("El material no existe en el sistema.");
    }

    Prestamo *nuevoPrestamo =
        new Prestamo(material, diasPermitidos, *fechaPrestamo);
    lector->addPrestamo(nuevoPrestamo);
    delete fechaPrestamo;
}

DTMaterial **obtenerMaterialesPrestados(string ciLector, int &cantMateriales)
{
    Lector *lector = buscarLectorPorCI(ciLector);
    if (lector == nullptr)
    {
        throw std::invalid_argument("Lector no encontrado.");
    }

    cantMateriales = lector->getCantidadPrestamos();
    if (cantMateriales == 0)
    {
        return nullptr;
    }

    DTMaterial **resultado = new DTMaterial *[cantMateriales];

    for (int i = 0; i < cantMateriales; i++)
    {
        Prestamo *p = lector->getPrestamos()[i];
        Material *m = p->getMaterialPrestado();
        resultado[i] = m->crearDT();
    }
    return resultado;
}

void agregarMaterial(DTMaterial *dt)
{
    if (topeMateriales >= MAX_MATERIALES)
    {
        throw std::invalid_argument("No se pueden agregar más materiales.");
    }
    if (buscarMaterialPorCodigo(dt->codigo) != nullptr)
    {
        throw std::invalid_argument("Ya existe un material con ese código.");
    }

    Material *nuevoMat = nullptr;

    if (DTLibro *dtLibro = dynamic_cast<DTLibro *>(dt))
    {
        Libro *libro = new Libro(dtLibro->autor, dtLibro->cantPaginas);
        libro->setCodigo(dtLibro->codigo);
        libro->setTitulo(dtLibro->titulo);
        libro->setAnioPublicacion(dtLibro->anioPublicacion);
        nuevoMat = libro;
    }
    else if (DTRevista *dtRevista = dynamic_cast<DTRevista *>(dt))
    {
        Revista *revista =
            new Revista(dtRevista->numeroEdicion, dtRevista->esMensual);
        revista->setCodigo(dtRevista->codigo);
        revista->setTitulo(dtRevista->titulo);
        revista->setAnioPublicacion(dtRevista->anioPublicacion);
        nuevoMat = revista;
    }

    if (nuevoMat)
    {
        materiales[topeMateriales++] = nuevoMat;
    }
    else
    {
        throw std::invalid_argument("Tipo de DTMaterial no reconocido.");
    }
}

float consultarMultaMaterial(string codigoMat, string ciLector)
{
    Material *mat = buscarMaterialPorCodigo(codigoMat);
    if (mat == nullptr)
    {
        throw std::invalid_argument("No existe un material con ese código.");
    }

    Lector *lector = buscarLectorPorCI(ciLector);
    if (lector == nullptr)
    {
        throw std::invalid_argument("No existe un lector con esa cédula.");
    }

    Prestamo *prestamoEncontrado = nullptr;
    for (int i = 0; i < lector->getCantidadPrestamos(); i++)
    {
        Prestamo *p = lector->getPrestamos()[i];
        if (p->getMaterialPrestado()->getCodigo() == codigoMat)
        {
            prestamoEncontrado = p;
            break;
        }
    }

    if (prestamoEncontrado == nullptr)
    {
        throw std::invalid_argument(
            "El lector no tiene un préstamo de ese material.");
    }

    int diasFechaPrestamo = fechaADias(prestamoEncontrado->getFechaPrestamo());
    int fechaDevolucion =
        diasFechaPrestamo + prestamoEncontrado->getDiasPermitidos();
    int hoy = obtenerHoy();
    int diasAtraso = hoy - fechaDevolucion;

    if (diasAtraso <= 0)
    {
        return 0; // Al día
    }
    else
    {
        return mat->calcularMulta(diasAtraso);
    }
}

bool esPrestamoAnterioraFecha(DTFecha fechaPrestamo, DTFecha *fecha)
{
    if (fechaPrestamo.getAnio() > fecha->getAnio())
        return false;
    else if (fechaPrestamo.getAnio() < fecha->getAnio())
        return true;
    else
    {
        if (fechaPrestamo.getMes() > fecha->getMes())
            return false;
        else if (fechaPrestamo.getMes() < fecha->getMes())
            return true;
        else
        {
            return fechaPrestamo.getDia() < fecha->getDia();
        }
    }
}
DTMaterial **verPrestamosAntesDeFecha(std::string ci, DTFecha *fecha, int &cantPrestamos)
{
    Lector *lector = buscarLectorPorCI(ci);
    if (lector == nullptr)
    {
        throw std::invalid_argument("Lector no encontrado.");
    }
    int contador = 0;
    for (int x = 0; x < lector->getCantidadPrestamos(); x++)

    {
        if (esPrestamoAnterioraFecha(lector->getPrestamos()[x]->getFechaPrestamo(), fecha))
            contador++;
    }
    if (contador == 0)
    {
        cantPrestamos = 0;
        return nullptr;
    }
    DTMaterial **resultado = new DTMaterial *[contador];
    int indice = 0;

    for (int x = 0; x < lector->getCantidadPrestamos(); x++)
    {
        if (esPrestamoAnterioraFecha(lector->getPrestamos()[x]->getFechaPrestamo(), fecha))
        {
            Material *material = lector->getPrestamos()[x]->getMaterialPrestado();
            resultado[indice] = material->crearDT();
            indice++;
        }
    }
    cantPrestamos = contador;
    return resultado;
}

void cargarDatosPrueba()
{
    try
    {
        // =========================
        // 📚 MATERIALES
        // =========================
        DTLibro *l1 = new DTLibro("Autor A", 200);
        l1->codigo = "L1";
        l1->titulo = "C++ Básico";
        l1->anioPublicacion = 2020;

        DTLibro *l2 = new DTLibro("Autor B", 350);
        l2->codigo = "L2";
        l2->titulo = "POO Avanzado";
        l2->anioPublicacion = 2018;

        DTLibro *l3 = new DTLibro("Autor C", 150);
        l3->codigo = "L3";
        l3->titulo = "Algoritmos";
        l3->anioPublicacion = 2021;

        DTRevista *r1 = new DTRevista(1, true);
        r1->codigo = "R1";
        r1->titulo = "Tech Monthly";
        r1->anioPublicacion = 2023;

        DTRevista *r2 = new DTRevista(5, false);
        r2->codigo = "R2";
        r2->titulo = "Science Weekly";
        r2->anioPublicacion = 2022;

        DTRevista *r3 = new DTRevista(12, true);
        r3->codigo = "R3";
        r3->titulo = "AI Today";
        r3->anioPublicacion = 2024;

        agregarMaterial(l1);
        agregarMaterial(l2);
        agregarMaterial(l3);
        agregarMaterial(r1);
        agregarMaterial(r2);
        agregarMaterial(r3);

        delete l1;
        delete l2;
        delete l3;
        delete r1;
        delete r2;
        delete r3;

        // =========================
        // 👤 LECTORES
        // =========================
        registrarLector("111", "Juan Perez", new DTFecha(1, 1, 2022));
        registrarLector("222", "Maria Lopez", new DTFecha(5, 5, 2021));
        registrarLector("333", "Carlos Diaz", new DTFecha(10, 10, 2020));

        // =========================
        // 📅 PRÉSTAMOS (6 cada uno)
        // =========================

        // --- Juan (111)
        agregarPrestamo("111", "L1", 5, new DTFecha(1, 3, 2024));
        agregarPrestamo("111", "R1", 7, new DTFecha(5, 3, 2024));
        agregarPrestamo("111", "L2", 10, new DTFecha(10, 2, 2024));
        agregarPrestamo("111", "R2", 3, new DTFecha(15, 1, 2024));
        agregarPrestamo("111", "L3", 8, new DTFecha(20, 3, 2024));
        agregarPrestamo("111", "R3", 6, new DTFecha(25, 3, 2024));

        // --- Maria (222)
        agregarPrestamo("222", "L2", 4, new DTFecha(1, 1, 2023));
        agregarPrestamo("222", "R2", 6, new DTFecha(10, 2, 2023));
        agregarPrestamo("222", "L1", 7, new DTFecha(15, 3, 2023));
        agregarPrestamo("222", "R1", 5, new DTFecha(20, 4, 2023));
        agregarPrestamo("222", "L3", 9, new DTFecha(25, 5, 2023));
        agregarPrestamo("222", "R3", 2, new DTFecha(30, 6, 2023));

        // --- Carlos (333)
        agregarPrestamo("333", "R3", 5, new DTFecha(1, 7, 2022));
        agregarPrestamo("333", "L3", 6, new DTFecha(10, 8, 2022));
        agregarPrestamo("333", "R1", 7, new DTFecha(15, 9, 2022));
        agregarPrestamo("333", "L1", 3, new DTFecha(20, 10, 2022));
        agregarPrestamo("333", "R2", 4, new DTFecha(25, 11, 2022));
        agregarPrestamo("333", "L2", 8, new DTFecha(30, 12, 2022));

        std::cout << "Datos de prueba cargados correctamente.\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error cargando datos: " << e.what() << std::endl;
    }
}

int main()
{
    cargarDatosPrueba();
    int opcionUser = -1;
    bool salirSistema = false;

    while (!salirSistema)
    {
        std::cout << "\n--- BIBLIOTECA ---\n";
        std::cout << "1) Registrar un lector\n";
        std::cout << "2) Agregar un préstamo\n";
        std::cout << "3) Obtener materiales prestados\n";
        std::cout << "4) Consultar multa de material\n";
        std::cout << "5) Ver préstamos antes de fecha\n";
        std::cout << "6) Agregar material\n";
        std::cout << "7) Salir\n";
        std::cout << "Opción: ";

        if (!(std::cin >> opcionUser))
        {
            std::cerr << "Entrada inválida\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        Menu opc = static_cast<Menu>(opcionUser);

        try
        {
            switch (opc)
            {
            case reg_lector:
            {
                std::string nombreLector, ciLector;
                std::cin.ignore();
                std::cout << "Ingrese nombre: ";
                std::getline(std::cin, nombreLector);
                if (nombreLector.empty())
                    throw std::invalid_argument("El nombre no puede estar vacío.");

                std::cout << "Ingrese CI: ";
                std::cin >> ciLector;

                std::cout << "Fecha registro (dd mm aaaa): ";
                int d, m, a;
                if (!(std::cin >> d >> m >> a))
                {
                    throw std::invalid_argument("Formato de fecha inválido.");
                }

                DTFecha *fechaRegistro = new DTFecha(d, m, a);
                registrarLector(ciLector, nombreLector, fechaRegistro);
                std::cout << "Lector registrado éxitosamente.\n";
                break;
            }
            case ag_prestamo:
            {
                std::cout << "Ingrese CI del lector: ";
                std::string ciLector;
                std::cin >> ciLector;

                std::cout << "Ingrese código de material: ";
                std::string codigoMat;
                std::cin >> codigoMat;

                std::cout << "Días permitidos: ";
                int dias;
                if (!(std::cin >> dias) || dias <= 0)
                {
                    throw std::invalid_argument("Días inválidos.");
                }

                std::cout << "Fecha préstamo (dd mm aaaa): ";
                int d, m, a;
                if (!(std::cin >> d >> m >> a))
                {
                    throw std::invalid_argument("Formato de fecha inválido.");
                }

                DTFecha *fechaPrestamo = new DTFecha(d, m, a);
                agregarPrestamo(ciLector, codigoMat, dias, fechaPrestamo);
                std::cout << "Préstamo agregado éxitosamente.\n";
                break;
            }
            case obt_mats:
            {
                std::cout << "Ingrese CI del lector: ";
                std::string ciLector;
                std::cin >> ciLector;

                int cant = 0;
                DTMaterial **mPrestados = obtenerMaterialesPrestados(ciLector, cant);

                if (cant == 0 || mPrestados == nullptr)
                {
                    std::cout << "El lector no tiene materiales prestados.\n";
                }
                else
                {
                    std::cout << "Materiales prestados al lector:\n";
                    for (int i = 0; i < cant; i++)
                    {
                        mPrestados[i]->imprimirInfo();
                        delete mPrestados[i];
                    }
                    delete[] mPrestados;
                }
                break;
            }
            case cons_multa:
            {
                std::cout << "Ingrese CI del lector: ";
                std::string ciLector;
                std::cin >> ciLector;

                std::cout << "Ingrese código de material: ";
                std::string codigoMat;
                std::cin >> codigoMat;

                float multa = consultarMultaMaterial(codigoMat, ciLector);
                if (multa == 0)
                {
                    std::cout << "El material no tiene atraso.\n";
                }
                else
                {
                    std::cout << "Multa generada: $" << multa << "\n";
                }
                break;
            }
            case ver_prestamos:
            {
                std::cout << "Ingrese CI del lector: ";
                std::string ciLector;
                std::cin >> ciLector;

                std::cout << "Ingrese fecha límite (dd mm aaaa): ";
                int d, m, a;
                if (!(std::cin >> d >> m >> a))
                {
                    throw std::invalid_argument("Formato de fecha inválido.");
                }

                DTFecha fechaLimite(d, m, a);
                int cant = 0;
                DTMaterial **mPrestados =
                    verPrestamosAntesDeFecha(ciLector, &fechaLimite, cant);

                if (mPrestados == nullptr)
                {
                    std::cout << "No hay préstamos anteriores a esta fecha.\n";
                }
                else
                {
                    std::cout << "Préstamos antes de fecha:\n";
                    for (int i = 0; i < cant; i++)
                    {
                        mPrestados[i]->imprimirInfo();
                        delete mPrestados[i];
                    }
                    delete[] mPrestados;
                }
                break;
            }
            case ag_material:
            {
                std::cout << "Tipo de material (1=Libro, 2=Revista): ";
                int tipo;
                if (!(std::cin >> tipo) || (tipo != 1 && tipo != 2))
                {
                    throw std::invalid_argument("Tipo inválido.");
                }

                std::cout << "Código: ";
                std::string codigo;
                std::cin >> codigo;

                std::cin.ignore();
                std::cout << "Título: ";
                std::string titulo;
                std::getline(std::cin, titulo);

                std::cout << "Año: ";
                int anio;
                std::cin >> anio;

                DTMaterial *dtNuevo = nullptr;

                std::cin.ignore();
                if (tipo == 1)
                { // Libro
                    std::cout << "Autor: ";
                    std::string autor;
                    std::getline(std::cin, autor);

                    std::cout << "Páginas: ";
                    int pags;
                    std::cin >> pags;

                    DTLibro *dtL = new DTLibro(autor, pags);
                    dtL->codigo = codigo;
                    dtL->titulo = titulo;
                    dtL->anioPublicacion = anio;
                    dtNuevo = dtL;
                }
                else
                { // Revista
                    std::cout << "Edición: ";
                    int edicion;
                    std::cin >> edicion;

                    std::cout << "¿Es mensual? (1=Sí, 0=No): ";
                    int esMensualInt;
                    std::cin >> esMensualInt;
                    bool esMensual = (esMensualInt != 0);

                    DTRevista *dtR = new DTRevista(edicion, esMensual);
                    dtR->codigo = codigo;
                    dtR->titulo = titulo;
                    dtR->anioPublicacion = anio;
                    dtNuevo = dtR;
                }

                agregarMaterial(dtNuevo);
                delete dtNuevo;
                std::cout << "Material agregado éxitosamente.\n";
                break;
            }
            case salir:
                salirSistema = true;
                std::cout << "Saliendo...\n";
                break;
            default:
                std::cout << "Opción no válida.\n";
                break;
            }
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "ERROR: " << e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    // Limpieza de memoria global
    for (int i = 0; i < topeLectores; i++)
    {
        delete lectores[i];
    }
    for (int i = 0; i < topeMateriales; i++)
    {
        delete materiales[i];
    }

    return 0;
}