// Code obtained from lecture: 08 Use of * and & (in the Multi-level Pointers section)

#include <stdio.h>

void main() {
  int i = 0XAA;
  char c = 3;

  int x;
  char *cptr;

  printf("\n");
  printf("&c = %p \n", &c);
  printf("(garbage) x = %d \n", x);
  printf("(garbage) cptr = %p \n", cptr);
  // the %p with a null pointer might show as NIL by printf. So, we also print it as a long long unsigned init below to see that in case it happens to be NIL (sometimes it'll be just a garbage value as the pointer is not initialized  yet), it is simply equal to the 0 address.
  printf("(garbage) cptr = 0x%llx \n\n", (long long unsigned int)cptr);

  /* 1. Use of & before the variable in non-pointer assignment */
  // x = i & c;
  // // this will print 2, because: i = 0xAA = 0b10101010. Then, c = 3 = 0b00000011. As & will be the logic AND operator here, we have 0b00000010 = 2.
  // // As an observation, this is an simplification because int is 4 bytes long, so actually we'll have 32 bits in total for i and c. So, actually
  // // i = 0b00000000000000000000000010101010, all of the missing bits are filled with zeros. 'c' will also be expanded to have more 0s so the AND operation can be performed.
  // printf("x = i &c; → %d \n\n", x);

  /* 2. Use of & before the variable in non-pointer assignment */
  // cptr = &c;
  // // this won't compile, it'll return: invalid operands to binary & (have ‘int’ and ‘char *’)
  // x = i & cptr;
  // printf("x = i & &c; → %d \n\n", x);
  // // this won't compile, it'll return: invalid operands to binary & (have ‘int’ and ‘char *’)
  // x = i & &c;
  // printf("x = i & &c; → %d \n\n", x);

  // i = 0xff;
  // // differently from the previous x = i & &c which doesn't compile, this one compiles and returns an integer.
  // // In this case, the address of c is converted to an integer first, then we can compare with 'i' using the logic AND operator.
  // x = i & (int)(&c);
  // // x = i & (int) &c is the same as x = i & (int)(&c). So, the () outside &c isn't required, actually.
  // printf("x = i & (int)(&c); → %x \n\n", x);

  /* 3. Assign pointer a valid address */
  // cptr = &c;
  // printf("cptr = %p, &c = %p \n\n", cptr, &c);

  /* 4. The use of * with a pointer variable */
  // i = 2;
  // // this won't compile, error: invalid operands to binary * (have ‘int’ and ‘char *’). The operands are interpreted as arithmetic operators first, instead of a derefencing to a pointer (which also would be weird in this case).
  // x = i * cptr;
  // printf("x = i * cptr; => %d \n\n", x);

  /* 5. The use of * with a pointer variable */
  // cptr = &c;
  // printf("cptr = %p, &c = %p \n\n", cptr, &c);
  // i = 2;
  // // this compiles, different from the example in 4. above. Now cptr is dereferenced first, then its value is multiplied by i.
  // // x value will be 6. Because by dereferencing cptr we get the value of c, which is 3. Then, 3 * 2 = 6.
  // x = i * *cptr;
  // printf("x = i ** cptr; → %d \n\n", x);

  /* 6. The use of * with a pointer variable */
  // cptr = &c;
  // i = 2;
  // // this is the same example as 5. above and x will still have the value 6.
  // // It is only to show that put the () outside *cptr is optional, but it can improve readability.
  // x = i * (*cptr);
  // printf("x = i * (*cptr); => %d \n\n", x);
}