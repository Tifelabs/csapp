/* 
 What would be printed as a result of the following call to show_bytes?
    const char *m = '"mnopqr"
    show_bytes((byte_pointer) m, streln(m))
*/

#include <stdio.h>
#include <string.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len){
    for(int i = 0; i < len; i++){
        printf("%.2x", start[i]);
    }
    printf("\n");
}

int main(){
    const char *m = "mnopqr";
    show_bytes((byte_pointer) m, strlen(m));
}

/* 
SOLUTION
  This will be printed: 6d6e6f707172
*/