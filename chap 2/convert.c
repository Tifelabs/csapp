#include <stdio.h>

int main(){
    short int  v = -12345;
    unsigned short uv = (unsigned)v;
    printf("v = %d, uv = %u\n", v, uv);

    unsigned u = 4294967295u;  /* UMax */
    int tu = (int)u;
    printf("u = %u, tu = %d\n", u, tu);

    return 0;
}