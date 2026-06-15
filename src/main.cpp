#include "../include/Fabrica.h"
#include "../include/RelojSistema.h"
#include "../include/DTLector.h"
#include "../include/DTFuncionario.h"
#include "../include/DTDatosPrestamo.h"
#include "../include/DTLectorPrestamos.h"
#include "../include/DTPrestamo.h"
#include "../include/DTMaterial.h"
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

using namespace std;

void cargarDatosPrueba(IControladorUsuarios* cu, IControladorMateriales* cm) {
    // Lectores
    DTFecha f1(1, 3, 2024);
    DTLector* l1 = cu->ingresarDatosLector("11111111", "Ana Garcia", "pass1", f1);
    cu->confirmarRegistro();
    delete l1;

    DTFecha f2(15, 6, 2023);
    DTLector* l2 = cu->ingresarDatosLector("22222222", "Carlos Lopez", "pass2", f2);
    cu->confirmarRegistro();
    delete l2;

    // Funcionario
    DTFuncionario* func = cu->ingresarDatosFuncionario("99999999", "Maria Admin", "admin123", 1001);
    cu->confirmarRegistro();
    delete func;

    // Materiales
    cm->ingresarDatosMaterial("LIB001", "El Principito", 1943);
    cm->ingresarDatosLibro("Antoine de Saint-Exupery", 96);
    cm->confirmarRegistro();

    cm->ingresarDatosMaterial("LIB002", "Cien Anios de Soledad", 1967);
    cm->ingresarDatosLibro("Gabriel Garcia Marquez", 471);
    cm->confirmarRegistro();

    cm->ingresarDatosMaterial("REV001", "National Geographic", 2024);
    cm->ingresarDatosRevista(312, true);
    cm->confirmarRegistro();

    // Prestamo
    DTLector* lp = cu->ingresarIDLector("11111111");
    delete lp;
    DTMaterial* mp = cu->ingresarCodigoMaterial("LIB001");
    delete mp;
    DTFecha fp(10, 6, 2026);
    DTDatosPrestamo* dp = cu->ingresarDatosPrestamo(fp, 14);
    delete dp;
    cu->confirmarPrestamo();

    cout << "  Datos de prueba cargados OK." << endl;
}

int main() {
    Fabrica* fab = Fabrica::getInstancia();
    IControladorSesion*     cs = fab->getControladorSesion();
    IControladorUsuarios*   cu = fab->getControladorUsuarios();
    IControladorMateriales* cm = fab->getControladorMateriales();
    RelojSistema*           reloj = RelojSistema::getInstancia();

    int opcion = -1;
    bool salir = false;

    while (!salir) {
        cout << "\n========== BIBLIOTECA ==========\n";
        cout << "  Fecha sistema: " << reloj->toString() << "\n";
        cout << "---------------------------------\n";
        cout << " 1) Iniciar sesion\n";
        cout << " 2) Cerrar sesion\n";
        cout << " 3) Registrar lector\n";
        cout << " 4) Registrar funcionario\n";
        cout << " 5) Registrar prestamo\n";
        cout << " 6) Consultar prestamos de lector\n";
        cout << " 7) Eliminar lector\n";
        cout << " 8) Agregar material (libro)\n";
        cout << " 9) Agregar material (revista)\n";
        cout << "10) Eliminar material\n";
        cout << "11) Modificar fecha del sistema\n";
        cout << "12) Consultar fecha del sistema\n";
        cout << "13) Cargar datos de prueba\n";
        cout << " 0) Salir\n";
        cout << "Opcion: ";

        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        try {
            switch (opcion) {

            case 1: {
                string ci, pass;
                cout << "CI: "; cin >> ci;
                cout << "Password: "; cin >> pass;
                bool ok = cs->iniciarSesion(ci, pass);
                cout << (ok ? "Sesion iniciada." : "CI o password incorrectos.") << endl;
                break;
            }
            case 2: {
                cs->cerrarSesion();
                cout << "Sesion cerrada." << endl;
                break;
            }
            case 3: {
                string ci, nombre, pass;
                int d, m, a;
                cin.ignore();
                cout << "CI: "; getline(cin, ci);
                cout << "Nombre: "; getline(cin, nombre);
                cout << "Password: "; getline(cin, pass);
                cout << "Fecha registro (dd mm aaaa): "; cin >> d >> m >> a;
                DTFecha fecha(d, m, a);
                DTLector* dt = cu->ingresarDatosLector(ci, nombre, pass, fecha);
                cout << "Confirmar registro? (1=Si 0=No): ";
                int conf; cin >> conf;
                if (conf == 1) { cu->confirmarRegistro(); cout << "Lector registrado." << endl; }
                else { cu->cancelar(); cout << "Cancelado." << endl; }
                delete dt;
                break;
            }
            case 4: {
                string ci, nombre, pass;
                int numEmp;
                cin.ignore();
                cout << "CI: "; getline(cin, ci);
                cout << "Nombre: "; getline(cin, nombre);
                cout << "Password: "; getline(cin, pass);
                cout << "Num empleado: "; cin >> numEmp;
                DTFuncionario* dt = cu->ingresarDatosFuncionario(ci, nombre, pass, numEmp);
                cout << "Confirmar? (1=Si 0=No): ";
                int conf; cin >> conf;
                if (conf == 1) { cu->confirmarRegistro(); cout << "Funcionario registrado." << endl; }
                else { cu->cancelar(); cout << "Cancelado." << endl; }
                delete dt;
                break;
            }
            case 5: {
                string ci, codigo;
                int dias, d, m, a;
                cout << "CI lector: "; cin >> ci;
                DTLector* dl = cu->ingresarIDLector(ci);
                cout << "  Lector: " << dl->nombre << endl;
                delete dl;
                cout << "Codigo material: "; cin >> codigo;
                DTMaterial* dm = cu->ingresarCodigoMaterial(codigo);
                cout << "  Material: " << dm->titulo << endl;
                delete dm;
                cout << "Fecha prestamo (dd mm aaaa): "; cin >> d >> m >> a;
                cout << "Dias devolucion: "; cin >> dias;
                DTFecha fecha(d, m, a);
                DTDatosPrestamo* dp = cu->ingresarDatosPrestamo(fecha, dias);
                cout << "Confirmar? (1=Si 0=No): ";
                int conf; cin >> conf;
                if (conf == 1) { cu->confirmarPrestamo(); cout << "Prestamo registrado." << endl; }
                else { cu->cancelarPrestamo(); cout << "Cancelado." << endl; }
                delete dp;
                break;
            }
            case 6: {
                string ci;
                cout << "CI lector: "; cin >> ci;
                DTLectorPrestamos* dlp = cu->consultarPrestamosLector(ci);
                cout << "Prestamos de " << dlp->nombreLector << ":" << endl;
                if (dlp->prestamos.empty()) cout << "  (sin prestamos)" << endl;
                for (DTPrestamo* p : dlp->prestamos) {
                    cout << "  - " << p->tituloMaterial
                         << " | Codigo: " << p->codigoMaterial
                         << " | Dias: " << p->diasPermitidos << endl;
                }
                delete dlp;
                break;
            }
            case 7: {
                string ci;
                cout << "CI lector a eliminar: "; cin >> ci;
                DTLector* dl = cu->seleccionarLectorAEliminar(ci);
                cout << "  Lector: " << dl->nombre << ". Confirmar? (1=Si 0=No): ";
                int conf; cin >> conf;
                if (conf == 1) { cu->confirmarEliminacionLector(); cout << "Lector eliminado." << endl; }
                else { cu->cancelarEliminacionLector(); cout << "Cancelado." << endl; }
                delete dl;
                break;
            }
            case 8: {
                string codigo, titulo, autor;
                int anio, pags;
                cin.ignore();
                cout << "Codigo: "; getline(cin, codigo);
                cout << "Titulo: "; getline(cin, titulo);
                cout << "Anio: "; cin >> anio;
                cin.ignore();
                cout << "Autor: "; getline(cin, autor);
                cout << "Paginas: "; cin >> pags;
                cm->ingresarDatosMaterial(codigo, titulo, anio);
                cm->ingresarDatosLibro(autor, pags);
                cout << "Confirmar? (1=Si 0=No): ";
                int conf; cin >> conf;
                if (conf == 1) { cm->confirmarRegistro(); cout << "Libro registrado." << endl; }
                else { cm->cancelar(); cout << "Cancelado." << endl; }
                break;
            }
            case 9: {
                string codigo, titulo;
                int anio, edicion, mensualInt;
                cin.ignore();
                cout << "Codigo: "; getline(cin, codigo);
                cout << "Titulo: "; getline(cin, titulo);
                cout << "Anio: "; cin >> anio;
                cout << "Num edicion: "; cin >> edicion;
                cout << "Es mensual? (1=Si 0=No): "; cin >> mensualInt;
                cm->ingresarDatosMaterial(codigo, titulo, anio);
                cm->ingresarDatosRevista(edicion, mensualInt == 1);
                cout << "Confirmar? (1=Si 0=No): ";
                int conf; cin >> conf;
                if (conf == 1) { cm->confirmarRegistro(); cout << "Revista registrada." << endl; }
                else { cm->cancelar(); cout << "Cancelado." << endl; }
                break;
            }
            case 10: {
                string codigo;
                cout << "Codigo material a eliminar: "; cin >> codigo;
                DTMaterial* dm = cm->seleccionarMaterialAEliminar(codigo);
                cout << "  Material: " << dm->titulo << ". Confirmar? (1=Si 0=No): ";
                int conf; cin >> conf;
                if (conf == 1) { cm->confirmarEliminacionMaterial(); cout << "Material eliminado." << endl; }
                else { cm->cancelarEliminacionMaterial(); cout << "Cancelado." << endl; }
                delete dm;
                break;
            }
            case 11: {
                int d, m, a, h, mn;
                cout << "Nueva fecha [dd mm aaaa hh mm]: ";
                cin >> d >> m >> a >> h >> mn;
                reloj->setFecha(d, m, a, h, mn);
                cout << "Fecha actualizada: " << reloj->toString() << endl;
                break;
            }
            case 12: {
                cout << "Fecha actual del sistema: " << reloj->toString() << endl;
                break;
            }
            case 13: {
                cargarDatosPrueba(cu, cm);
                break;
            }
            case 0:
                salir = true;
                cout << "Hasta luego." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
            }
        } catch (const exception& e) {
            cerr << "ERROR: " << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    delete cs;
    delete cu;
    delete cm;
    return 0;
}