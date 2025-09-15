CC=gcc
CFLAGS=-I./include -I./src

SRC=$(wildcard src/*.c)
OBJ=$(SRC:.c=.o)

all: cli-tool

cli-tool: $(OBJ)
	$(CC) $(CFLAGS) -o cli-tool $(OBJ)

clean:
	rm -f src/*.o cli-tool

test: cli-tool
	$(CC) $(CFLAGS) tests/test_core.c src/core.c -o test_core
	./test_core
	$(CC) $(CFLAGS) tests/test_cli.c src/cli.c src/core.c -o test_cli
	./test_cli

.PHONY: all clean test
