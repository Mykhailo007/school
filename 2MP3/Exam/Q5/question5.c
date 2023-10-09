#include<stdio.h>
#include<string.h>

void incBytes (void* array, int size_of_type, int size_of_array);

void printHexArray(int* arr, int size) {
	printf("[");
	for (int i = 0; i < size; i++) {
		printf("0x%08X", arr[i]);
		if (i < size - 1) printf(", ");
	}
	printf("]\n");
}

int main () {
	int test1[5] = {0,0,0,0,0};
	int expected1[5] = {0x01010101, 0x01010101, 0x01010101, 0x01010101, 0x01010101};
	incBytes(test1, sizeof(int), 5);
    printf("Test Case 1 : ");
    if (!memcmp(expected1, test1, 5*sizeof(int))) {
        printf("Passed!\n");
    } else {
        printf("Failed!\nExpected : ");
       	printHexArray(expected1, 5);
       	printf("But I got : ");
		printHexArray(test1, 5);
    }
    
    printf("Test Case 2 : ");
    int test2[8] = {0xFFFFFFFF,0xFFFFFFFE,0xFFFFFFFD,0xFFFFFFFC,0xFFFFFFFF,0xFFFFFFFA,0xFFFFFFF9,0xFFFFFFF8};
    int expected2[8] = {0x00000000, 0x000000FF, 0x000000FE, 0x000000FD, 0x00000000, 0x000000FB, 0x000000FA, 0x000000F9};
    incBytes(test2, sizeof(int), 8);
    if (!memcmp(expected2, test2, 8*sizeof(int))) {
        printf("Passed!\n");
    } else {
        printf("Failed!\nExpected : ");
       	printHexArray(expected2, 8);
       	printf("But I got : ");
		printHexArray(test2, 8);
    }
	
    printf("Test Case 3 : ");
	float test3[6] = {4.4, 8.8, 15.15, 16.16, 23.23, 42.42};
	int expected3[6] = {0x418DCDCE, 0x420DCDCE, 0x42736767, 0x428248AF, 0x42BAD80B, 0x432AAF15};
    incBytes(test3, sizeof(float), 6);
    if (!memcmp(expected3, test3, 6*sizeof(float))) {
        printf("Passed!\n");
    } else {
        printf("Failed!\nExpected : ");
       	printHexArray((int*)expected3, 6);
       	printf("But I got : ");
		printHexArray((int*)test3, 6);
    }
	
    printf("Test Case 4 : ");
	char test4[65] = "I do not like green eggs and ham.  I do not like them, Sam I am!";
	char expected4[65] = "J!ep!opu!mjlf!hsffo!fhht!boe!ibn/!!J!ep!opu!mjlf!uifn-!Tbn!J!bn\"";
	incBytes(test4, sizeof(char), 64);
	if (!memcmp(expected4, test4, 64*sizeof(char))) {
        printf("Passed!\n");
    } else {
        printf("Failed!\nExpected : %s\n", expected4);
       	printf("But I got :         %s\n", test4);
    }
	
}
