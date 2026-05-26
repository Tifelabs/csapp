/*  
    You are given the assignment of writing a function that determines whether one string is 
    longer than another. You decide to make use of the string library function
    strlen having the following declaration
*/

#include <stdio.h>
#include <string.h>

/* Prototype for library function strlen */
size_t strlen(const char *s);

/* Determine whether string s is longer than string t */
/* WARNING: This function is buggy */
int strlonger(char *s, char *t){
    return strlen(s) - strlen(t) > 0;
}

/* 
    When compiled as 32-bit program, data type size_t is defined
    (via typedef) in header file stdio.h to be unsigned

    A. For what cases will this function produce and incorrect result?
    The incorrect result happens when t is longer than s. 
    That's the exact case. Doesn't matter if it's 32-bit or 64-bit the bug exists on both.


    B. Explain how this incorrect result comes about.
    strlen(s) - strlen(t)
    strlen returns size_t which is UNSIGNED
    if strlen(t) > strlen(s), say s="hi"(2), t="hello"(5)
    2 - 5 = -3  ... but unsigned can't hold -3
    so it wraps around to 4294967293
    4294967293 > 0 is TRUE
    so the function says s is longer , WRONG

    C. Show how to fix the code so it will work reliably
*/


/* CODE FIX */
int strlonger(char *s, char *t){
    return  strlen(s) > strlen(t);
}
