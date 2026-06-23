/* 
    Wrire a function div16 that returns the value x/16 for argument x. Your
    function should not use division, modulus, multiplication, any conditionals(if or ?:)
    any comparison operators(e.g <, >, or ==), or any loops, You may assume that data type int is 32bits
    long and uses a two's complement representation,and that right shifts are performmed arithmetically
*/

#include <stdio.h>

int div16(int x){
    /* compute bias to be either (x >= 0) or 15(x < 0) */
    int bias = (x >> 31) & 0xF;
    return (x + bias) >> 4;
}