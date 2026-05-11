#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len){
    for(int i = 0; i < len; i++){
        printf("%.2x", start[i]);
    }
    printf("\n");
}

int main(){
    int a = 0x12345678;
    byte_pointer ap = (byte_pointer) &a;
    show_bytes(ap, 1); /* A */
    show_bytes(ap, 2); /* B */
    show_bytes(ap, 3); /* C */ 
}
 
/* 
 (A) Little endian = 78         Big endian = 12
 (B) Little endian = 78 56      Big endian = 12 34
 (C) Litle endian  = 78 56 34   Big endian = 12 34 56
*/