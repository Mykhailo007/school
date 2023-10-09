#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>

int LeapYearCheck (int n);

int LeapYearCheck (int n){
    if (n%4==0){
        if (n%100==0){
            if (n%400==0){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return true;
        }     
    }
    else{
        return false;
    }
}

int main () {

    int test;
    test = LeapYearCheck(2000);
    printf("%d\n", test);

    return 0;
}

