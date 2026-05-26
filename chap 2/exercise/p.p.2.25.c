/* 
 Consider the following code that attempts to sum the elements in an
 array a, where the number is given by parameter lenght
*/

#include <stdio.h>

/* WARNING: This is a buggy code */
float sum_elements(float a[], unsigned length){
    int i;
    float result = 0;

    for(i = 0; i <= length - 1; i++)
        result += a[i];
        return result;
}

/* Corrected Code */
float sum_elements(float a[], int length){
    float result = 0;
    for(int i = 0; i < length; i++)
        result += a[i];
    return result;
}