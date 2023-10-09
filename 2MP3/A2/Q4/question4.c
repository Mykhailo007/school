#include <stdio.h>
#include <assert.h>
#include <math.h>


int insertionsort(int* x, int size);
/*
int insertionsort(int* x, int size){
    int examinations = 0;
    
    for(int i = 0; i < size; i++){
        int first = x[i];
        int second = x[i+1];
        int j = i+1;
        if(first > second){

            while(first > second && j >= 1){
                x[j-1] = second;
                x[j] = first;
                j -= 1;
                first = x[j-1];
                second = x[j]; 
                examinations += 1;
            }
            if(j > 1){
                examinations += 1;
            }
        }
        else {
            examinations += 1;
        }
    }
    return examinations;
}
*/
#include <stdio.h>
#include <assert.h>
#include <math.h>

int insertionsort(int* x, int size){
    int counter = 0;
    int i, j, temp;

    for (i=0; i<size-1; i++){
        for (j=0; j+i>=0; j--){
            if (x[j+i]>x[j+i+1]){
                temp = x[j+i];
                x[j+i] = x[j+i+1];
                x[j+i+1] = temp;
                counter++;
            }
            else {
                counter++;
                break;
            }
        }
    }
    return counter;

}
int main () {

    int x[] = {548, 845, 731, 258, 809, 522, 73, 385, 906, 891, 988, 289, 808, 128};
    int sizex = sizeof(x)/sizeof(x[0]);

    printf("%d\n", insertionsort(x, sizex));
    return 0;
}
