CC = gcc
CFLAGS = -Wall -Iinclude

SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=build/%.o)

TARGET = build/problemaDelCaballo

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@

build/%.o: src/%.c | build
	$(CC) $(CFLAGS) -c $< -o $@

build:
	mkdir build

run: all
	./$(TARGET)

.PHONY: all clean run