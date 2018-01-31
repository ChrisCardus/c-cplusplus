// a test file for exercise 1

#include <stdio.h>
#include <stdlib.h>

#include "freegraph.h"

struct N *mknode(struct N *xp, struct N *yp, struct N *zp, long n)
{
    struct N *p = malloc(sizeof(struct N));
    p->x = xp;
    p->y = yp;
    p->z = zp;
    p->data = n;
    return p;
}

int main(int argc, const char *argv[])
{
  struct N *p1, *p2, *p3, *p4, *p5, *p6;
    
    // construct a graph for testing: 
    // first build some nodes 
    p1 = mknode(NULL, NULL, NULL, 1);
    p2 = mknode(NULL, NULL, NULL, 10);
    p3 = mknode(NULL, NULL, NULL, 100);
    p4 = mknode(p1, p2, p3, 3000);
    p1 = mknode(NULL, NULL, NULL, 1);
    p2 = mknode(NULL, NULL, NULL, 10);
    p3 = mknode(NULL, NULL, NULL, 100);
    p5 = mknode(p1, p2, p3, 4000);
    p5 = mknode(p4, p5, NULL, 50000);
    p6 = mknode(p5, NULL, NULL, 100000);

    // now make it harder by sharing and cycles
    p1->x = p5;
    p2->y = p4;
    p2->z = p2;
    p6->y = p5;
    p6->z = p6; 

    deallocate(p6);
    printf("Now all the nodes should be freed.\n");
    return 0;
}


