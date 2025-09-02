#include <stdio.h>

void main() {
    char c = 'A';
    char *c_ptr = &c;

    printf("c=%c, &c=%p\n", c, &c);
    printf("c_ptr=%p\n", c_ptr);
}