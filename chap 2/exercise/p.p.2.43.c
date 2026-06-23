/* 
In the following code, we have ommitted the definitions of constants M and N:
*/

#define M /* Mystery number 1 */
#define N /* Mystery number 2 */

int arith(int x, int y){
    int result = 0;
    result = x * M + y/N; /* M and N are mystery numbers */
    return result;
}

/* 
We can compile this code for particular values M and N. Th compiler optimized the multiplication
and division using the methods we have dicussed. The following is the translation of the generated 
machine code back to C
*/

/* Translation of assembly code for arith */
int optarit(int x, int y){
    int t = x;
    x <<= 5;
    x -= t;
    if(y < 0) y+= 7;
    y >>= 3; /* Arithmetic shift */
    return x + y;
}

/* What are the values of M and N ?*/

/*
 Solution
    M IS 31
    N IS 8
*/

