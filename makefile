# Nombre del ejecutable
TARGET = programa.exe

# Compilador a usar
CXX = g++

# Opciones de compilación: mostrar warnings, debug y declarar carpeta de headers
CXXFLAGS = -Wall -g -Iinclude

# Archivos fuente (busca todos los .cpp dentro de la carpeta src)
SOURCES = $(wildcard src/*.cpp)

# Archivos objeto (reemplaza src/archivo.cpp por src/archivo.o)
OBJECTS = $(SOURCES:.cpp=.o)

# Regla principal (se ejecuta al escribir 'make' o 'mingw32-make')
all: $(TARGET)

# Regla para enlazar los archivos objeto y crear el ejecutable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Regla genérica para compilar los archivos .cpp a .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para limpiar los archivos compilados
clean:
	rm -f src/*.o $(TARGET)

.PHONY: all clean
