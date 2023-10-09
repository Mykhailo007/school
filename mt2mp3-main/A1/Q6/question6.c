#include <stdio.h>
#include <assert.h>
#include <math.h>

int FactorialWhile (int n);

int FactorialWhile (int n){
    int sum;
    sum = 1;
    while (n>0){
        sum *= n;
        n -= 1;
    }
    return sum;
}

int FactorialDoWhile (int n);

int FactorialDoWhile (int n){
    int sum;
    sum = 1;
    do{
        sum *= n;
        n -= 1;
        if (sum == 0){
            sum = 1;
        }
    }while(n>0);
    return sum;
}

int main () {
    int test;
    test = FactorialWhile(10);
    printf("While: %d\n", test);

    int test_do;
    test_do = FactorialDoWhile(10);
    printf("DoWhile: %d\n", test_do);

    return 0;
}

