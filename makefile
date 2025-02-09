CC=gcc 
CFLAGS=-std=c99 -pedantic -pedantic-errors -Werror -Wall -Wextra

all: args environ impl malloc malloc_v2 my_sigint my_malloc pause pid segments

args: args.c
environ: environ.c
impl: impl.c
malloc: malloc.c
malloc_v2: malloc_v2.c
my_sigint: my_sigint.c
my_malloc: my_malloc.c
	$(CC) $(CFLAGS) -Wno-deprecated -o my_malloc my_malloc.c
pause: pause.c
pid: pid.c
segments: segments.c

clean:
	rm -f args
	rm -f environ
	rm -f impl
	rm -f malloc
	rm -f malloc_v2
	rm -f my_sigint
	rm -f my_malloc
	rm -f pause
	rm -f pid
	rm -f segments

create:
	touch args.c
	touch environ.c
	touch impl.c
	touch malloc.c
	touch malloc_v2.c
	touch my_sigint.c
	touch my_malloc.c
	touch pause
	touch pid.c
	touch segments.c
