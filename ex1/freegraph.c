#include <stdlib.h>
#include "freegraph.h"
#include <stdio.h>

void deallocate(struct N *p) {
    if(p){
        printf("True\n");
    } else {
        printf("False\n");
    }
    while (p) {
        //printf("1");
        deallocate(p->x);
        //printf("2");
        deallocate(p->y);
        //printf("3");
        deallocate(p->z);
        //printf("4");
    }
    free(p);
}