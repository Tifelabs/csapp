/* 
Assume data type int is 32 bits long and uses a two's complement representation fro signed values.
Right shifts are performed arithmetically for signed values and logically for unsigned values. The variables are declared 
and initialized as follows
*/

#include <stdio.h>

int x = foo();  /* Arbitrary value */
int y = bar();  /* Arbitrary vaue */

unsigned ux = x;
unsigned uy = y;

/* 
For each of the following C expression, either(1) argument that is true (evaluates to 1)
for all values of x and y, or (2) give values of x and y for which is false (evaluates to 0)
*/

/* 
    (A) (x > 0) || (x-1 < 0)
    (B) (x & 7) != 7 || (x << 29 < 0)
    (C) (x * x) >= 0
    (D) x < 0 || -x <= 0
    (E) x > 0 || -x >= 0
    (F) x + y == uy + ux
    (G) x *- y + uy * ux == -x
*/