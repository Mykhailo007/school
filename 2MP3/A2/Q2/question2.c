#include <stdio.h>
#include <assert.h>
#include <math.h>

int juggler(int n);

int juggler(int n){
    
    int n_next = n;
    int n_temp = 0;
        if (n_next %2 == 0){
            n_temp = floor(sqrt(n_next));
            n_next = n_temp;
            return juggler(n_next) + 1;
            }
        else if (n_next != 1){
            n_temp = floor(sqrt(n_next)*sqrt(n_next)*sqrt(n_next));
            n_next = n_temp;
            return juggler(n_next) + 1;
        }
    
        else{
            return 0;
        }
    
}

int main () {
    printf("%d\n", juggler(10001));

    return 0;
}
