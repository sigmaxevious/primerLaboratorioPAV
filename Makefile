# 1. VARIABLES
CXX = g++
# Se incluyen las flags pedidas y el acceso a la carpeta include
CXXFLAGS = -Iinclude -Wall -Wextra -g

# 2. DIRECTORIOS
# Organizar el proyecto por carpetas es una buena práctica recomendada
SRC_DIR = src
OBJ_DIR = obj

# 3. FUENTES Y OBJETOS
# Busca automáticamente todos los archivos .cpp en la carpeta src/
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
# Genera los nombres de los .o pero los coloca en la carpeta obj/
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# 4. TARGET (Ejecutable)
TARGET = main.exe

# 5. REGLAS PRINCIPALES
# .PHONY evita conflictos si existen archivos llamados 'all' o 'clean'
.PHONY: all clean

# Regla por defecto: crea la carpeta de objetos y el ejecutable
all: $(OBJ_DIR) $(TARGET)

# Linkeo de los objetos para crear el ejecutable final
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
	@echo "=================================="
	@echo "Compilación exitosa. Ejecutable: $(TARGET)"
	@echo "=================================="

# Compilación de cada .cpp a .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Crear la carpeta de objetos si no existe (indispensable para Linux)
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# 6. LIMPIEZA
# Se ajusta para ser compatible con el estándar Unix de los salones [2]
clean:
	@echo "Limpiando archivos compilados..."
	rm -rf $(OBJ_DIR) $(TARGET)
	@echo "Limpieza finalizada."