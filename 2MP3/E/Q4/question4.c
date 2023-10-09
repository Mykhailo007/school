#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define DEBUG 3
#define VERBOSE 1

void printBoolArray(bool* arr, int size) {
	printf("[");
	for (int i = 0; i < size; i++) {
		printf("%s", arr[i] ? "true" : "false" );
		if (i < size - 1) {
			printf(", ");
		}
	}
	printf("]\n");
}


void printArray(int* arr, int size) {
	printf("[");
	for (int i = 0; i < size; i++) {
		printf("%d", arr[i]);
		if (i < size - 1) {
			printf(", ");
		}
	}
	printf("]\n");
}


// Sorted array contains only those elements which were already in order.  
int* StalinSort (int* cheloveks, int size);
int ascending (int a, int b);
void swap (int* num1, int* num2);
int* insertionsort(int* x, int size, int (*compare)(int a, int b));


//equality is included and all elements smaller than the one previous are removed from the array
int* StalinSort (int* cheloveks, int size){
    int max_val = 0;
    int j = 0;
    int* survivors = (int*)malloc(size*sizeof(int));
    for (int i = 0; i<size; i++){
        if (cheloveks[i] >= max_val){
            max_val = cheloveks[i];
            survivors[j] = cheloveks[i];
            j++;
        }
    }
    printArray(survivors, j);
    printf("\n");
    int* final = insertionsort(survivors, j, ascending);
    return final;
}

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
} 

int* insertionsort(int* x, int size, int (*compare)(int a, int b)){
    int counter = 0;
    int i, j, temp;
    int* alivers = (int*)malloc(size*sizeof(int));

    for (i=0; i<size-1; i++){
        for (j=0; j+i>=0; j--){
            if ((compare((x[j+i]), x[j+i+1])) == true){
                swap((x+j+i), (x+j+i+1));
                counter++;
            }
        }
    }
    printArray(x, size);
    alivers = x;
    return alivers;

}

int main() {

    
    #if DEBUG == 1
    int test1[5] = {3, 4, 5, 1, 9};
    int expected1[4] = {3,4,5,9};
    printf("Test Case 1 : ");
    if (!memcmp(expected1, StalinSort(test1, 5), 4*sizeof(int))) {
        printf("Passed!\n");
    } else {
        printf("Failed!\n");
        #if VERBOSE == 1
		printArray(StalinSort(test1, 5), 4);
		#endif
    }
    #endif
    
    #if DEBUG == 2
    int test2[10] = {30, 8, 73, 16, 22, 1, 0, 55, 58, 81};
    int expected2[3] = {30, 73, 81};    
    printf("Test Case 2 : ");
    if (!memcmp(expected2, StalinSort(test2, 10), 3*sizeof(int))) {
        printf("Passed!\n");
    } else {
        printf("Failed!\n");
        #if VERBOSE == 1
        printArray(StalinSort(test2, 10), 3);
        #endif
    } 
    #endif   
    
    #if DEBUG == 3
    int test3[20] = {231, 376, 596, 83, 879, 460, 569, 804, 331, 671, 533, 857, 351, 717, 133, 48, 725, 253, 15, 525};
    int expected3[4] = {231, 376, 596, 879}; 
    printf("Test Case 3 : ");
    if (!memcmp(expected3, StalinSort(test3, 20), 4*sizeof(int))) {
        printf("Passed!\n");
    } else {
        printf("Failed!\n");
        #if VERBOSE == 1
        printArray(StalinSort(test3, 20), 4);
        #endif
    }    
    #endif
}
