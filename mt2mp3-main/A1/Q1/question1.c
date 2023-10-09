#include <stdio.h>
#include <assert.h>
#include <math.h>

int minutes (int m, int h, int d);

int minutes (int m, int h, int d){
    int ttl_mins = m + 60*(h + d*24);
    return ttl_mins;
}

int main () {

    int test = minutes(0, 0, 0);
    printf("%d\n", test);
    return 0;
}

