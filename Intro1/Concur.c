#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "common_threads.h"

volatile int cntr = 0;
int lps;

void *wrk(void *arg){
    (void)arg;  // unused parameter
    int i;
    for (i = 0; i < lps; i++){
        cntr++;
    }
    return NULL;
}

int main(int argc, char *argv[]){
    if (argc != 2){
        fprintf(stderr, "usage: thrds <value>\n");
        exit(1);
    }
    lps = atoi(argv[1]);
    pthread_t p1, p2; // varibales to store the IDs of the Threads....
    printf("Intial Value : %d\n", cntr);

    PThrd_create(&p1, NULL, wrk, NULL);
    PThrd_create(&p2, NULL, wrk, NULL);
    PThrd_join(p1, NULL);
    PThrd_join(p2, NULL);
    printf("Final Value     : %d\n", cntr);
    return 0;
}