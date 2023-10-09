#include <stdio.h>
#include <assert.h>
#include <math.h>

    //for(x,y; x<=N, y<=N; x += x, y += y){
    //    sum = sum + x + y;
    //}
    //sum += N;
    //return sum;
int multiples (int x, int y, int N);

int multiples (int x, int y, int N){
    int sum;
    int i;
    for(i=1; i<=N; ++i){
        if(i%x==0 ||i%y==0){
            sum += i;
        }
    }
    
    return sum;
}
int main () {

    int test = multiples(4,10,20);
    printf("%d\n", test);

    return 0;
}

