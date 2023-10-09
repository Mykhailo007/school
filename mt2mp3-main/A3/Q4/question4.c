#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>


int insertionsort(int* x, int size, int (*compare)(int a, int b));
int ascending (int a, int b);
int descending (int a, int b);
void swap (int* num1, int* num2);

int ascending (int a, int b){
    if (a < b){
        return false;
    }
    else if (a == b){
        return false;
    }
    else{
        return true;
    }
}
void swap (int* num1, int* num2){
    int temp_num;

    temp_num = *num1;
    *num1 = *num2;
    *num2 = temp_num;
} //swap works
int descending (int a, int b){
    if (a > b){
        return false;
    }
    else if (a == b){
        return false;
    }
    else{
        return true;
    }
}

int insertionsort(int* x, int size, int (*compare)(int a, int b)){
    int counter = 0;
    int i, j, temp;

    for (i=0; i<size-1; i++){
        for (j=0; j+i>=0; j--){
            if ((compare((x[j+i]), x[j+i+1])) == true){
                swap((x+j+i), (x+j+i+1));
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
    int test[] = {548, 845, 731, 258, 809, 522, 73, 385, 906, 891, 988, 289, 808, 128};
    int len_test = sizeof(test)/sizeof(test[0]);
    for(int i = 0; i < len_test; i++){
        printf("%d ", test[i]);
    }
    printf("\n");
    

    int val = insertionsort(test, len_test, ascending);
    printf("%d\n", val);

    for(int k = 0; k < len_test; k++){
        printf("%d ", test[k]);
    }
    printf("\n");


    return 0;
}