#include <stdio.h>
#include "modulo1.h"

int main(int argc, char *argv[]) {
    long base, expo;
    scanf("%ld %ld", base, expo);
    printf("%ld\n", my_pow(base, expo));
 
    return 0;
}