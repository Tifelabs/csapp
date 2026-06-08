/* 
    You are given the task of patchinf the vulnerability in the XDR code shown below,
    for the casewhere both data types int and size_t are 32-bits. You decide to eleimate the possibility of
    the multiplication overflowing by computing the number of bytes to allocate using data type unint64_t.
    You replaced the original call to malloc as:
        uint64_t asize = ele_cnt * (uint64_t) ele_size;
        void *result = malloc(asize);
    
    Recall that the argumemt to malloc has type size_t
    A. Does your code provide any improvement over the original?
    B. How would you change the code to eliminate the vulnerability
*/


/* 
    Illustration of code vulnerability similar to that found in Sun's XDR Library
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void copy_elements(void *ele_src[], int ele_cnt, size_t ele_size){
    /* 
    Allocate buffer for ele_cnt objects, each of ele_size bytes
    and copy from locations designated by ele_src
    */

    void *result = malloc(ele_cnt * ele_size);
    if(result == NULL)
    /* Malloc failed */
    return NULL;

    void *next = result;
    int i;
    for(i = 0; i < ele_cnt; i++){
        /* Copy object i to destination */
        memcpy(next, ele_src[i], ele_size);
        /* Move pointer to next memory region */
        next += ele_size;
    }
    return result;
}

/* FIX */
void copy_elements(void *ele_src[], int ele_cnt, size_t ele_size){
    /* 
    Allocate buffer for ele_cnt objects, each of ele_size bytes
    and copy from locations designated by ele_src
    */

    uint64_t req_size = ele_cnt * (uint64_t)ele_size;
    uint64_t res_size  = (size_t)req_size;

    if(req_size != res_size)
    /* Overflow must have occurred */
    return NULL;

    void *result = malloc(res_size);
    if(result == NULL)
     /* Malloc failed */
    return NULL;

    void *next = result;
    int i;
    for(i = 0; i < ele_cnt; i++){
        /* Copy object i to destination */
        memcpy(next, ele_src[i], ele_size);
        /* Move pointer to next memory region */
        next += ele_size;
    }
    return result;
}