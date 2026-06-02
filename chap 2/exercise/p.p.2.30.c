/* 
    Write a function with the following prototype:
    // Determine whether arguments can be added without overflow

    int tadd_ok(int x, int y);
    This function should return 1 if argument x and y can be added without causing an overflow
*/

#include <stdio.h>
#include <limits.h>

int tadd_ok(int x, int y){
    int sum = x + y;
    int neg_over = x < 0 && y < 0 && sum >= 0;
    int pos_over = x >=0 && y >= 0 && sum < 0;
    return !neg_over && !pos_over;
}

int main(){
    int a = INT_MAX, b = 35;
    printf("%d\n", tadd_ok(a,b));
    return 0;
}
