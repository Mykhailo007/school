#include <stdio.h>
#include <assert.h>
#include <math.h>


int bubblesort(int* x, int size);

int bubblesort(int* x, int size){
    int temp, swapNmb = 0;

    for (int i = 0; i < (size-1); i++){
        
        for (int j = 0; j < (size - i - 1); j++){
            if (x[j+1] < x[j]){
                temp = x[j+1];
                x[j+1] = x[j];
                x[j] = temp;
                swapNmb++;
            }
        }
    }
    return swapNmb;
}


int main () {
    int x[]= {548, 845, 731, 258, 809, 522, 73, 385, 906, 891, 988, 289, 808, 128};
    int sizex = sizeof(x)/sizeof(x[0]);

    printf("%d\n", bubblesort(x,sizex));
    return 0;
}