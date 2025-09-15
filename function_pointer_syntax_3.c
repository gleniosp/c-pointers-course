// Another way to define function pointers by using typedef.
// Example is similar to the `function_pointer_syntax_2.c` source code but it uses typedef.

#include <stdio.h>

void function_1(int a) {
    printf("function_1(): a = %d\n", a);
}

void function_2(int b) {
    printf("function_2(): b = %d\n", b);
}

// by doing this we create a new type called `func_ptr`
typedef void (*func_ptr)(int);

int main() {
    // we can now use the new `func_ptr` type.
    func_ptr pf;

    // and different from the `function_pointer_syntax_2.c` source code, we can use `func_ptr` anymore for directly assignment.
    // Now it has become a type and we need to first create a variable of this type (`pf` in this case) and then assign to it.
    pf = function_1;
    pf(10);

    // using & to assign the function address is optional
    pf = &function_2;
    pf(20);

    return 0;
}