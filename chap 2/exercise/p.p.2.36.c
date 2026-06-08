/* 
 For the case where data type int has 32 bits, devise a version ofn tmult_ok that
 use the 64-bit precision of data type int64_t, without division.
*/

#include <stdio.h>
#include <stdint.h>

int tmult_ok(int x, int y){
    int64_t p  = (int64_t) x * y;

    /* See if casting works */
    return p == (int) p;
}