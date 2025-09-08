#include <stdio.h>
#include <malloc.h>

void main() {
    char *p[10];

    printf("p: %p\n", p);
    for (int i = 0; i < 10; i++) {
        p[i] = (char *) malloc(1);
        *p[i] = 10 - i;
        printf("p[%d]: %p\n", i, p[i]);
    }

    for (int i = 0; i < 10; i++) {
        printf("*p[%d]: %d\n", i, *p[i]);
    }

    // For a 64-bit machine this will print 80 (bytes).
    // Our array has 10 elements of 8 bytes each (each pointer uses 8 bytes to store the address they are pointing to).
    printf("sizeof(p): %lu\n", sizeof(p));

    for (int i = 0; i < 10; i++) {
        free(p[i]);
    }
}