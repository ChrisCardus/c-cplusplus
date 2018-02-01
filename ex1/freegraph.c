#include <stdlib.h>
#include "freegraph.h"
#include <stdio.h>

void deallocate(struct N *p) {

    while(p) {

        free(p);



    
    }

}