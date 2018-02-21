#include <stdio.h>
#include <assert.h>

double media(double arr[], int n) {


}

int main(int argc, char *argv[]) {
    double v1[] = {1.0, 2, 3};
    double v2[] = {2, 2, 2, 2, 2};
    double v3[] = {3, 4, 5, 6};
    
    assert(media(v1, 3) == 2.0);
    assert(media(v1, 2) == 1.5);

    assert(media(v2, 5) == 2.0);
    assert(media(v3, 4) == 4.5);


    return 0;
}