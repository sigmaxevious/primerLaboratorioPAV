# Nombre del ejecutable
TARGET = programa.exe

# Compilador a usar
CXX = g++

# Opciones de compilación (flags: mostrar todos los warnings y añadir info de debug)
CXXFLAGS = -Wall -g

# Archivos fuente
SOURCES = main.cpp coordenada.cpp segmento.cpp DTFecha.cpp DTLibro.cpp DTRevista.cpp DTMaterial.cpp Material.cpp Libro.cpp Lector.cpp Prestamo.cpp Revista.cpp

# Archivos objeto (reemplaza .cpp por .o)
OBJECTS = $(SOURCES:.cpp=.o)

# Regla principal (se ejecuta al escribir 'make' o 'mingw32-make')
all: $(TARGET)

# Regla para enlazar (linkear) los archivos objeto y crear el ejecutable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Regla genérica para compilar los archivos .cpp a .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para limpiar los archivos compilados (útil para recompilar desde cero)
clean:
	rm -f *.o $(TARGET)
