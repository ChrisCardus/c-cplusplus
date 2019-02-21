#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b)
{
    if (a < 0) {
        a = a * -1;
    }
    if (b < 0) {
        b = b * -1;
    }
    if (a == 0 || b == 0) {
        printf("Can't compute greatest common devisor if a or b equal zero.\n");
        exit(0);
    }
    
    
    
    while(a != b){
        if (a > b)
        {
            a = a - b;
        } else {
            b = b - a;
        }
    }
    return a;
}