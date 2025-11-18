CC      := gcc
CFLAGS  := -std=c11 -Wall -Wextra -Werror -pedantic -g -Iinclude
TARGET  := estructuras_datos


SRC     := main.c src/stack.c src/lista.c src/array.c
OBJ     := $(SRC:.c=.o)

.PHONY: all run clean valgrind

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

valgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)
