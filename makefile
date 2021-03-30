CC=gcc 
CFLAGS=-std=c99 -pedantic -pedantic-errors -Werror -Wall -Wextra

all: my_malloc

my_malloc: my_malloc.c
	$(CC) $(CFLAGS) -Wno-deprecated -o my_malloc my_malloc.c

clean:
	rm -f my_malloc
