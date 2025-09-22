#include <stdio.h>
#include <stdlib.h>

#define REQUEST 1*1024*1024*1024 // 1 GB

int main() {
    // `malloc` memory allocation will fail if there isn't enough space available. Here we try to simulate this case by
    // asking 1 GB of memory each time we iterate in the below loop and not reclaiming/freeing this allocated memory.
    // If `malloc` fails, it'll return (void *)0x0, which is essentially the NULL definition adopted by the libraries in C.
    // Be aware that malloc can't take more than a `size_t` maximum value as a request: https://man7.org/linux/man-pages/man3/malloc.3.html
    // While `size_t` is usually equivalent to `int` or `unsigned int`, that's why we're requesting around 1 GB only
    // so we don't get to close to this limit.
    int *p;

    for (int i = 0; i < 1000000; i++) {
        p = (int *)malloc(REQUEST);
        printf("i:%d, p: %p\n", i, p);
        if (p == NULL) {
            return -1;
        }
    }

    // By the way, never allocate memory without freeing it with `free`. Otherwise, the allocated memory will never
    // be freed because we lost the reference to it and this is what causes *memory leaks*.
    // We did this here only to see how `malloc` behaves when it is unable to allocate memory.

    return 0;
}