#include <stdio.h>
#include <stdlib.h>

int main() {
    // `malloc` goes to the heap memory and allocate the number of provided bytes (4 bytes in the below example) and
    // returns a void pointer that points to the address of this allocation.
    // As `malloc` returns a void pointer, we need to type cast it into the desired data type.
    int *p = (int *)malloc(4);

    printf("before: %d\n", *p);
    *p = 4;
    printf("after: %d\n", *p);

    // `free` will, as the name says, free the pointer allocation, so the freed memory can be used again by other parts
    // of the program.
    free(p);

    // As a side note, if we were to allocate 400 bytes, for example, and malloc is able to provide this space and then
    // assign this to an integer pointer like below, only the first 4 bytes would be occupied by an integer value and
    // the rest of the bytes (396 bytes) would only have garbage value.
    int *p_big = (int *)malloc(400);
    printf("before: %d\n", *p_big);
    // after assigning the value 4, it'll be assigned to the first 4 bytes in the 400 bytes allocated
    *p_big = 4;
    printf("after: %d\n", *p_big);

    return 0;
}