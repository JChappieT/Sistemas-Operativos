# Makefile para compilar el proyecto de multiplicación de matrices

# Compilador
CC = gcc

# Opciones de compilación
CFLAGS = -Wall -pthread

# Archivos fuente y objeto
SRCS = mm_Clasica.c biblioteca.c
OBJS = $(SRCS:.c=.o)

# Nombre del ejecutable
EXEC = mm_Clasica

# Regla principal
all: $(EXEC)

# Compilación del ejecutable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Limpieza de archivos objeto y ejecutable
clean:
	rm -f $(OBJS) $(EXEC)

# Regla para compilar archivos .c a .o
%.o: %.c biblioteca.h
	$(CC) $(CFLAGS) -c $< -o $@
