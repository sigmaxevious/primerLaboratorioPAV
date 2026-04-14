# Sistema de Biblioteca en C++

Proyecto de sistema de gestión de biblioteca desarrollado en C++ como parte del curso de Programación Avanzada.  
Permite registrar lectores, materiales (libros y revistas) y gestionar préstamos, incluyendo cálculo de multas y consultas por fecha.

## Características principales

- Registro de lectores con cédula, nombre y fecha de registro.
- Registro de materiales:
  - Libros: autor y cantidad de páginas.
  - Revistas: número de edición y periodicidad.
- Gestión de préstamos:
  - Alta de préstamos con fecha y días permitidos.
  - Cálculo de multa según tipo de material.
  - Consulta de materiales prestados por lector.
  - Consulta de préstamos realizados antes de una fecha dada.
- Interfaz de consola con menú interactivo.

## Tecnologías y conceptos

- Lenguaje: **C++**
- Paradigma: **Programación Orientada a Objetos (POO)**
- Uso de:
  - Clases, herencia y polimorfismo (`Material`, `Libro`, `Revista`, `Lector`, `Prestamo`).
  - Datatypes (`DtFecha`, `DtMaterial`, `DtLibro`, `DtRevista`) para transportar datos y separar lógica de presentación.
  - Manejo de excepciones con `std::invalid_argument`.
  - Manejo básico de memoria dinámica con `new` / `delete`.

## Metodología de trabajo

El desarrollo se realizó aplicando una **metodología ágil basada en sprints**, planificando incrementos pequeños y revisables del sistema en cada iteración.  
Para el control de versiones utilizamos **GitHub** con una estrategia de **branches por funcionalidad**, creando ramas separadas para cada requisito (registro de lectores, préstamos, materiales, multas, etc.) y luego integrándolas a la rama principal mediante *pull requests*.

## Estructura general del proyecto

- `src/`
  - Implementaciones de las clases principales (lectores, materiales, préstamos, datatypes, etc.).
- `include/`
  - Archivos de cabecera (`.h`) con declaraciones de clases e interfaces.
- `main.cpp`
  - Menú interactivo y orquestación de las operaciones.
- `makefile`
  - Script para compilar y ejecutar el proyecto de forma sencilla.

*(Ajustar estos nombres si tu estructura es distinta.)*

## Cómo compilar y ejecutar

Desde la carpeta raíz del proyecto:

```bash
make
./programa
```

O, en su defecto:

```bash
g++ -std=c++11 -Wall -Iinclude src/*.cpp -o programa
./programa
```

*(Adaptar estos comandos a tu estructura real de archivos.)*

## Equipo

Proyecto realizado en equipo junto a:

- **Esteban**  
- **Oscar**

Agradecimientos especiales por el trabajo colaborativo durante los sprints, la revisión de código y la coordinación en el uso de branches de GitHub.

## Repositorio

Puedes clonar el repositorio con:

```bash
git clone https://github.com/sigmaxevious/primerLaboratorioPAV.git
```

