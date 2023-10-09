#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

double mean(int* x, int size);
double median(int* x, int size);
int mode(int* x, int size);


double mean(int* x, int size){
    double count = 0;
    for (int i = 0; i < size; i++){
        count += x[i];
    }
    double final = count/size;
    return final;
}

int mode(int* x, int size){
    int min = 0, count, temp[size], k = 0, c = 0, i, j;  //change var k, c
    for (i = 0; i < size; i++){ //sets the first number in the array
        count = 0; //counter for how many times the number is repeated
        for (j = i + 1; j < size; j++){ //runs through the array to see how many times x[i] is repeated in the array
            if (x[i] == x[j]){
                count++; //+1 for every time the number reappears
            }
        }
        if ((count > min) && (count != 0)){
            k = 0; //resets the array since a new mode has been found
            min = count; //sets the new minimum amount of repeats needed for a new mode to be found
            temp[k] = x[i]; //appends the array 'temp' to hold the number which represents mode
            k++;
        }
        else if (count == min){
            temp[k] = x[i]; //adds the integer to the array since it is found the same number of times as all previous mode values
            k++;
        }
        
        
    }
    for(i = 0; i < size; i++){
        if (x[i] == temp[i]){
            c++;
        }
    }
    if (c == size){
        printf("There is no mode.\n");
    }
    else{
        printf("The Mode is:\t");
        for (i = 0; i < k; i++){
            printf("%d ", temp[i]);
        }
        printf("\n");
    for (i = 0; i< k; i++){
        return temp[i];
        }
        }
    }
    
double median(int* x, int size){
    for(int i = 0; i < size; i++){ //insert sort the array
        int elmt = x[i];
        int j = i - 1;

        while (j >= 0 && x[j] > elmt){ //move elements of x[] that are greater than elmt to one postion ahead of its current position
            x[j+1] = x[j];
            j = j -1;
        }
        x[j + 1] = elmt;
    }
    int middle;
    if (size%2 != 0){
            middle = floor(size/2);
            return x[middle];
    }
    else if (size%2 == 0){
        int mid1 = (size/2);
        int mid2 = (mid1 -1);
        middle = ((x[mid1] +x[mid2])/2);
        return middle;
    }
    
    
}



int main () {
    int x[8];
    int sizex = sizeof(x)/sizeof(x[0]);

    printf("%f\n", mean(x,sizex));

    printf("%f\n", mode(x, sizex));

    printf("%f\n", median(x, sizex));

    for(int i=0; i<sizex; i++){
        printf("%d,\n", x[i]);
    }
    return 0;
}

