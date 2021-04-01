#define _DEFAULT_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <assert.h>

void *my_malloc(size_t size) {
    return malloc(size); // TODO: implement with sbrk() and/or brk()
}

void my_free(void *p) {
    free(p); // TODO: implement with sbrk() and/or brk()
}

void test1() {
    int *p = my_malloc(sizeof(int));
    int *q = my_malloc(sizeof(int));
    int *r = my_malloc(sizeof(int));
    printf("%p: %d\n", (void *) p, *p);
    printf("%p: %d\n", (void *) q, *q);
    printf("%p: %d\n", (void *) r, *r);
    // call my_free() in reverse order
    my_free(r);
    my_free(q);
    my_free(p);
    // assert memory has been freed
    //assert(sbrk(0) == (void *) p);
    printf("%p: sbrk(0)\n\n", sbrk(0));
}

void test2() {
    int *p = my_malloc(sizeof(int));
    int *q = my_malloc(sizeof(int));
    int *r = my_malloc(sizeof(int));
    printf("%p: %d\n", (void *) p, *p);
    printf("%p: %d\n", (void *) q, *q);
    printf("%p: %d\n", (void *) r, *r);
    // call my_free() in any order
    my_free(p);
    my_free(r);
    my_free(q);
    // assert memory has been freed
    //assert(sbrk(0) == (void *) p);
    printf("%p: sbrk(0)\n\n", sbrk(0));
}

int main() {
    test1();
    test2();
}
