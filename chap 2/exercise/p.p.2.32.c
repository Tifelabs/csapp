/* 
    You are assigned the task of writing code fora function tsub_ok, with arguments
    x and y, that will return 1 if computing x-y does not cause overflow. Having just written
    the code for p.p.2.30.c, you write the following

    //Determine whether arguments can be subtracted without overflow
    //WARNING: This code is buggy

    int tsub_ok(int x, int y){
        return tadd_ok(x, -y)
    }
*/

#include <stdio.h>
#include <limits.h>

int tadd_ok(int x, int y){
    int sum = x + y;
    int neg_over = x < 0 && y < 0 && sum >= 0;
    int pos_over = x >=0 && y >= 0 && sum < 0;
    return !neg_over && !pos_over;
}

int tsub_ok(int x, int y){
    if(y == INT_MIN) return 0;
    return tadd_ok(x, -y);
}

int main(){
    printf("0 - 1:        %d\n", tsub_ok(0, 1));        // 1 (safe)
    printf("0 - INT_MIN:  %d\n", tsub_ok(0, INT_MIN));  // 0 (overflow)
    printf("INT_MIN - 1:  %d\n", tsub_ok(INT_MIN, 1));  // 0 (overflow)
    printf("INT_MAX - -1: %d\n", tsub_ok(INT_MAX, -1)); // 0 (overflow)
}