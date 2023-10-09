#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

void reverse(char* str);
int count(char* str);

void reverse(char* str){
    int length_arr = 1;
    
    while ((str[length_arr]) != '\0'){
        length_arr++;
    }
    char temp_str[length_arr];
    for(int i = 0; i < length_arr; i++){
        temp_str[i] = (str[i]);
    }
    int j = 0;
    //reversing the word
    for(int k = 0; k < length_arr; k++){
        str[k] = temp_str[length_arr-k-1];
    }
    while(temp_str[j] != '\0'){
        printf("%c", temp_str[j]);
        j++;
    }
    printf("\n");
    int f;
    //printing reverse word
    while(str[f] != '\0'){
        printf("%c", str[f]);
        f++;
    }
    printf("\n");
    
}

int count(char* str){
    int counter = 0;
    int length_arr = 1;
    
    while ((str[length_arr]) != '\0'){
        length_arr++;
    }
    for (int i = 0; i < length_arr; i++){
        if (str[i] == 'A'){
            counter++;
        }
        else if (str[i] == 'a'){
            counter++;
        }
        else if (str[i] == 'E'){
            counter++;
        }
        else if (str[i] == 'e'){
            counter++;
        }
        else if (str[i] == 'I'){
            counter++;
        }
        else if (str[i] == 'i'){
            counter++;
        }
        else if (str[i] == 'O'){
            counter++;
        }
        else if (str[i] == 'o'){
            counter++;
        }
        else if (str[i] == 'U'){
            counter++;
        }
        else if (str[i] == 'u'){
            counter++;
        }
    }
    return counter;
}

int main () {
    char test_str[] = "Mykhailo";
    reverse(test_str);

    int num = count(test_str);
    printf("%d\n", num);
    
    return 0;
}