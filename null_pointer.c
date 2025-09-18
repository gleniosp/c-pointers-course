#include <stdio.h>

// NULL means nothingness. In the context of pointers what the libraries in C usually do is to define NULL
// as a void pointer pointing to the 0 address in memory (0x0), as in the `#define` below.
// We could also do (void *)0 instead of (void *)0x0. The important is that we provide this (void *) instead of
// simply assigning 0 or 0x0 directly so the compiler understanding that 0 is not a simple number but a memory address.
// If we run the `#define` below, the compiler will throw a warning mentioning that somewhere in `stdio`
// (more specifically `stddef.h`, included by `stdio.h`) it will already have a definition for NULL similar to this one.
//
// #define NULL (void *)0x0

int main() {
    // this will print: `(nil), 0x0`
    printf("%p, 0x%llu\n", NULL, (long long unsigned int) NULL);

    // we could assign NULL to a data pointer, like `int *p = NULL` below. However, as this pointer will point to the
    // 0x0 address and usually there is code there, not data, like the CPU boot up code, if we try to dereference this
    // pointer with *p we might get an error. The code might compile, but it'll probably fail when running with a
    // "Segmentation fault (core dumped)" error. This is because we're trying to read code as an integer data.
    // When we say that this might fail it is because it depends on the hardware. On normal high level OS like
    // Linux, Windows and Mac, there is a Memory Management Unit (MMU) between the CPU and the Memory and this unit
    // assures that for every process that run in the CPU, they will be given only memory addresses that are non zero.
    // If we try to read the memory zero location, MMU will forbit it and send some interrupt to the CPU about it and
    // this will fail with segmentation fault.
    // However, when we do not have a high level OS, you might have a bare metal system or RTOS running with memory
    // management disabled, accessing the 0x0 address won't fail. There won't be any MMU unit coming in the way of
    // CPU while talking to the memory. Also, by having an OS, even the OS might block it by doing some memory
    // management itself, so not having a high level OS is another reason to allow us accessing the 0x0 location.
    int *p = NULL;
    printf("%d\n", *p);
}