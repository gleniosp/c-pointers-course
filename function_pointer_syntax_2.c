#include <stdio.h>

void function_1(int a) {
    printf("function_1(): a = %d\n", a);
}

void function_2(int b) {
    printf("function_2(): b = %d\n", b);
}

int main() {
    void (*func_ptr)(int);

    func_ptr = function_1;
    func_ptr(10);

    // using & to assign the function address is optional
    func_ptr = &function_2;
    func_ptr(20);

    return 0;
}