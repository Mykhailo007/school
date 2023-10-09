#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>

void removeDups(int* in, int size);

void removeDups(int* in, int size){
    int tracker[size];
    int amnt_added = 0;
    bool if_in = false;
    for (int i = 0; i < size; i++){
        int temp_var = in[i];
        for (int j = 0; j < (amnt_added+1); j++){
            if_in = false;
            if (temp_var == tracker[j]){
                if_in = true;
                printf("%d is a dup\n", temp_var);
                break;
            }
            
        }
        if (if_in == false){
            tracker[amnt_added] = temp_var;
            printf("%d is not a dup and has been added\n", temp_var);
            amnt_added++;
        }
    }
    for (int k = 0; k < (amnt_added+1); k++){
        in[k] = tracker[k];
    }
    while(amnt_added != size){
        in[amnt_added] = 0;
        amnt_added++;
    }
}

int main () {
    int test[] = {1, 2, 2, 2, 3, 3, 4, 2, 4, 5, 6, 6};
    int length_arr = 12;

    int f = 0;
    while(f < length_arr){
        printf("%d ", test[f]);
        f++;
    }
    
    printf("\n");

    printf("%d\n", length_arr);
    removeDups(test, length_arr);
    
    int p = 0;
    while(p < 12){
        printf("%d ", test[p]);
        p++;
    }
    printf("\n");
    return 0;
}