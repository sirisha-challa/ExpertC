#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "common.h"

int main(){
    int *p = malloc(sizeof(int)); // a1
    assert(p != NULL);
    printf("(%d) address pointed to by p: %p\n", getpid(), p); //a2
    *p = 0; //a3, stores 0 at the address pointed by P
    while (1) {
        Spin(1);
        *p = *p + 1;
        printf("(%d) p: %d\n", getpid(), *p);
    }
    return 0;
}