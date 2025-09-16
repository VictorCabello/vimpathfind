CC=gcc
CFLAGS=-I./include -I./src

SRC=$(wildcard src/*.c)
OBJ=$(SRC:.c=.o)

all: vimfindpath

vimfindpath: $(OBJ)
	$(CC) $(CFLAGS) -o vimfindpath $(OBJ)

clean:
	rm -f src/*.o vimfindpath

test: vimfindpath
	$(CC) $(CFLAGS) src/list.c tests/test_list.c  -o test_cli
	./test_cli
	$(CC) $(CFLAGS)  tests/test_core.c src/core.c src/list.c -o test_core
	./test_core
	$(CC) $(CFLAGS) tests/test_cli.c src/cli.c src/core.c src/list.c -o test_cli
	./test_cli

.PHONY: all clean test
