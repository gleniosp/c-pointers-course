// This can be compile and executed with: gcc function_pointer_array.c math_library.c && ./a.out
#include "math_library.h"

int main() {
    // the idea is that execute_operation can call any of functions represented by ADD, SUB, MUL and DIV to perform an operation.
    // Behind the scenes, execute_operation will read the provided operation and get the function correspondent to it in an
    // array of function pointers.
    execute_operation(ADD, 100, 5);
    execute_operation(SUB, 100, 5);
    execute_operation(MUL, 100, 5);
    execute_operation(DIV, 100, 5);
    return 0;
}