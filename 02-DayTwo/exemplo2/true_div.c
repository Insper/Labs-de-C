#include "util.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    long a, b;
    scanf("%ld, %ld", &a, &b);
    printf("%lf\n", true_div(a, b));
    return 0;
}