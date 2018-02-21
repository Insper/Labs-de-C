#include "util.h"
#include <math.h> 

struct pair  {
    double p0, p1;
};

double divide_by_two(double d) {
    return d/2;
}

double true_div(long a, long b) {
    return ((double) a / b);
}

double length(pair_t p) {
    return sqrt(p.p0*p.p0 + p.p1*p.p1);
}