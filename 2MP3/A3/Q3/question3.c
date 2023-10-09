#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>


int shellsort (int *array, int size, int *h_gaps, int (*subsort)(int* array, int size));
int bubblesort(int* x, int size);
void subarraymaker(int *array, int **subarray, int *sublen, int hgap, int size);
void arraymaker(int **subarray, int *sublen, int *array,int hgap);

int bubblesort(int* x, int size) {
    int temp;
    int swaps = 0;
    for (int i = 0; i < size; i ++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (x[j] > x[j+1]) {
                temp = x[j];
                x[j] = x[j + 1];
                x[j+1] = temp;
                swaps ++;
            }
        }
    }
    return swaps;
}

void subarraymaker(int *array, int **subarray, int *sublen, int hgap, int size){
    
    for(int i=0;i<size;i++){
        subarray[i%(hgap+1)][sublen[i%(hgap+1)]]=array[i];
        sublen[i%(hgap+1)]++;
    }
}

void arraymaker(int **subarray, int *sublen, int *array,int hgap){
    int k=0;
    for(int i=0; i<sublen[0]; i++){
        for(int j=0; j<=hgap; j++){
            if(i<sublen[j]){
                array[k]=subarray[j][i];
                k++;
            }
        }
    }
}

void printarr(int *arr, int len){
        for(int j = 0; j < len; j++) {
        printf("%d,", arr[j]);
    }
    printf("\n");
}

int shellsort(int *array, int size, int *h_gaps, int (*subsort)(int* array, int size)){
        int num_count = 0;
        int i=0;
        int current_h= h_gaps[i];
        while(1){
                        
            int **subarray=(int**)malloc((current_h+1)*sizeof(int *));
            for (int j=0;j<current_h+1;j++){subarray[j]=malloc((size/current_h+1)*sizeof(int));}
            int *sublen=malloc((current_h+1)*sizeof(int));
            for (int j=0; j<current_h+1; j++){sublen[j] = 0;}

            subarraymaker(array,subarray,sublen,current_h, size);
            for(int j=0; j<current_h+1;j++){
                num_count+=(*subsort)(subarray[j],sublen[j]);
            }
            
            arraymaker(subarray,sublen,array, current_h);
            
            //free
            for (int j=0;j<current_h+1;j++){free(subarray[j]);}
            free(subarray);
            free(sublen);
            
            if (current_h==1){
                break;
            }
            current_h= h_gaps[++i];
            
        }
        
        
        num_count+=(*subsort)(array, size);
        
        return num_count;
}
int main () {
    
    
    return 0;
}