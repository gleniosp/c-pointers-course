#include <stdio.h>

void main() {
    char a[3] = {'A', 'B', 'C'};
    int b[3] = {10, 11, 12};
    short int c[3] = {20, 21, 22};

    char *pa = a;
    int *pb = &b[0];

    // // In pointer arithmetic when you do pa+X, where X is an integer, you're moving to an address X times the
    // // number of bytes represented by the pointer data type. So, for an integer pointer, which is usually 4 bytes
    // // to represent an integer, if you add pa+2 you're moving 2*4 bytes addresses in memory.
    // // Even pointer to other more complex types like a pointer to a struct would move the address by X times the size
    // // of the whole struct in bytes.
    // // You can also decrement a value from a pointer, which decrements the memory address.

    printf("\nMath on char pointer!\n");
    printf("pa   = %p\n", pa);
    // Note that you can also access an pointer like an array: pa[0], for example.
    printf("pa+0 = %p : *(pa+0) = %c, pa[0] = %c\n", pa+0, *(pa+0), pa[0]);
    printf("pa+1 = %p : *(pa+1) = %c, pa[1] = %c\n", pa+1, *(pa+1), pa[1]);
    printf("pa+2 = %p : *(pa+2) = %c, pa[2] = %c\n", pa+2, *(pa+2), pa[2]);
    // // Pointer arithmetic only works for + and - operations. So, the code below won't compile.
    // printf("pa*2 = %p : *(pa*2) = %c, pa[2] = %c\n", pa*2, *(pa*2), pa[2]);

    printf("\nMath on int pointer!\n");
    printf("pb   = %p\n", pb);
    printf("pb+0 = %p : *(pb+0) = %d, pb[0] = %d\n", pb+0, *(pb+0), pb[0]);
    printf("pb+1 = %p : *(pb+1) = %d, pb[1] = %d\n", pb+1, *(pb+1), pb[1]);
    printf("pb+2 = %p : *(pb+2) = %d, pb[2] = %d\n", pb+2, *(pb+2), pb[2]);

    printf("\nMath on short int pointer!\n");
    short int *pc = &c[1];
    printf("pc   = %p\n", pc);
    printf("pc+0 = %p : *(pc+0) = %d, pc[0] = %d \n", pc+0, *(pc+0), pc[0]);
    printf("pc-1 = %p : *(pc-1) = %d, pc[-1] = %d \n", pc-1, *(pc-1), pc[-1]);
    printf("pc+1 = %p : *(pc+1) = %d, pc[1] = %d \n", pc+1, *(pc+1), pc[1]);
}