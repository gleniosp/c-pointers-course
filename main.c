#include <stdio.h>

void main() {
    char c = 'A';
    char *c_ptr = &c;

    // check variable addresses and the address stored by the pointer
    printf("c=%c, &c=%p\n", c, &c);
    printf("c_ptr=%p\n", c_ptr);
    printf("&c_ptr=%p\n", &c_ptr);

    // access value of the variable pointed by the pointer
    printf("*c_ptr=%c\n", *c_ptr);
}