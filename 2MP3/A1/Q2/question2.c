#include <stdio.h>
#include <assert.h>
#include <math.h>

float onethird (int n);

float onethird (int n){
    float num;
    int i;
    for(i=1; i<=n; i++){
        num += pow(i,2);
    }
    num /= pow(n,3);
    return num;
}

int main () {

    float test = onethird(9999);
    printf("%f\n", test);
    return 0;
}

