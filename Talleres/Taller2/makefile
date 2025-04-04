# Nombre del compilador
CC = gcc

# Opciones de compilación
CFLAGS = -Wall -g

# Archivos fuente
SRC = taller_procesos.c biblioteca.c

# Archivos objeto (automáticamente derivados de los .c)
OBJ = $(SRC:.c=.o)

# Nombre del ejecutable
TARGET = taller_procesos

# Regla principal
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Regla para ejecutar el archivo compilado
run: $(TARGET)
	./$(TARGET) 4 arch1.txt 4 arch2.txt


# Regla para limpiar archivos generados
clean:
	rm -f $(OBJ) $(TARGET)
