#include <stdio.h>

void main() {
    // What the compiler does here is to allocate the string "GLENIO" at some place in memory, then get the address of
    // the first character and store it in tthe name_ptr pointer variable.
    char *name_ptr = "GLENIO";
    // The below array could also have been created as: char name_array[] = {"g", "l", "e", "n", "i", "o", "\0"};
    // Notice that in this case we need to explicitly add the null character (\0) in the end, while using a direct
    // string as below, the compiler already adds this for us.
    // Here the compiler allocates "glenio" directly at some place in memory and "name_array" by itself, without the
    // square brackets, automatically becomes a pointer to the first character in this string.
    char name_array[] = "glenio";

    /* 1. similarity between array and pointers */
    // %s formatter here will read all values pointed by the pointer until it finds a \0.
    // While doing *name_ptr or *name_array only and using a %c, will only print the first character pointed by the pointer.
    printf("name_ptr: %s, name_ptr: %p, *name_ptr: %c\n", name_ptr, name_ptr, *name_ptr);
    // Notice how the array behaves like a pointer.
    printf("name_array: %s, name_array: %p, *name_array: %c\n", name_array, name_array, *name_array);

    /* 2. Difference between array and pointers #1 */
    // sizeof(name_ptr) will be 8, which means that it takes 8 bytes (64-bits) in this machine to store a pointer.
    // sizeof(name_array) will be 7, because it'll instead return the total space occupied by the elements in the array.
    // That is, 6 characters of 1 byte each (for the 'glenio' characters) + 1 implicit null character (\0) of 1 byte. Total = 7 bytes.
    // This one one of the differences between array and pointers when interpreted by the compiler, like in these cases of getting their sizes.
    printf("sizeof(name_ptr): %lu, sizeof(name_array): %lu\n", sizeof(name_ptr), sizeof(name_array));

    int x[] = {10, 11, 12};
    int *xptr = x;

    // sizeof(xptr) here will be 8, which means that it takes 8 bytes (64-bits) in this machine to store a pointer.
    // sizeof(x) here will be 12, that is, 3 integer elements of 4 bytes each = 12 bytes.
    printf("sizeof(xptr): %lu, sizeof(x): %lu\n", sizeof(xptr), sizeof(x));

    /* 3. Array cannot be reassigned but pointer can be! */
    int a[] = {110, 111, 112};
    int i = 1024;
    // The two assignments below won't compile. They'll return -> error: assignment to expression with array type
    // a = x;
    // a = &i;

    // However, we can reassign a pointer
    xptr = a;
    int *iptr = &i; // just to show a simple integer pointer
}