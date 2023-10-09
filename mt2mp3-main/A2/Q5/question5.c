#include <stdio.h>
#include <assert.h>
#include <math.h>


int binsearch(int* x, int y, int size);

int binsearch(int* x, int y, int size){
    int a = 0, b = size-1, m = floor((a+b)/2), count = 0;
    for (int i = 0; i < size; i++){
        m = floor((a+b)/2);
        if (y == x[m] || y == x[a] || y == x[b]){
            return ++count;
        }
        else if (x[m]<y){
            a = floor((a+b)/2)+1;
            ++count;
        }
        else if(x[m]>y){
            b = floor((a+b)/2)-1;
            ++count;
        }
    }
    return -1;
}

int main () {
    int x[] = {100};
    int sizex = sizeof(x)/sizeof(x[0]);
    int y = 100;

    printf("%d\n", binsearch(x,y,sizex));
    return 0;
}
