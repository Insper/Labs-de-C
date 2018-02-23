#include "modulo1.h"

long my_pow(long b, long e) {
    long r = 1;
    while (e-- > 0) {
        r *= b;
    }
    return r;
}
