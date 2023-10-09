#include <cstdlib>
#include <iostream>

int divisor(double x){
    int count = 0; //counts the number of divisions
    double i = x; 
    while(i>=2){
        i = i/2;
        if (i>=2){ //when there is no if statement the loop runs one too many times
            count++; //adds one to the counter after every division
        }
    }
    return count;
}

int main(){
    std::cout << "number of times divided by 2: " << divisor(92) << std::endl;
    return 0;
}