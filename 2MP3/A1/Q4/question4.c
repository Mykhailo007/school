#include <stdio.h>
#include <assert.h>
#include <math.h>

float compoundInterest (float p, int a, int n);

float compoundInterest (float p, int a, int n){
    float total;
    total = a*pow((1+p), n);
    return total;
}

int main () {

    float test;
    test = compoundInterest(0.06, 800, 2);
    printf("%f\n", test);
    return 0;
}

