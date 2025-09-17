#include <stdio.h>

int main() {
    int i = 10;

    void *pi = &i;

    printf("pi: %p, &i: %p\n", pi, &i);
    // A void pointer can't be directly dereferenced without typecasting it first.
    // it'll throw "error: invalid use of void expression" if we try to dereference it as below:
    // printf("*pi: %d\n", *pi);

    return 0;
}