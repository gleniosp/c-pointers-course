#include <stdio.h>

void function_1() {
    printf("function_1()\n");
}

void function_2() {
    printf("function_2()\n");
}

int main() {
    // Define a function pointer by using the syntax: `function_return_datatype (*desired_pointer_name)(datatypes for the inputs);`
    void (*func_ptr)();

    // Notice that the function name itself is the address, so we don't necessarily need to use & and do something like &function_1.
    // But is also possible to do `func_ptr = &function_1;`. It'll still work and assign the function address to the pointer.
    func_ptr = function_1; // or func_ptr = &function_1;
    // Also, using a parenthesis after the pointer name is the same as dereferencing it, which will call the function that the pointer is pointing to.
    // Different from the address assignment where we can simply do `func_ptr = function_1 or `func_ptr = &function_1`,
    // we can't use * here and do something like *func_ptr or *func_ptr() to call the function. The correct syntax is only `func_ptr()`.
    func_ptr();

    func_ptr = function_2;
    func_ptr();

    return 0;
}