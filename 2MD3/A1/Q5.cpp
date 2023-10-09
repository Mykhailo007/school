#include <cstdlib>
#include <iostream>

int GCD(int n,int m){
    int large = n; 
    int small = m;
    int temp;
    while (small != 0){
        temp=large%small; //computes the modulus of the 2 numbers
        large = small; //since the modulus is now smaller, I swap the 2 
                       //variables
        small = temp; //reset the small value to the modulus of the two previous
                      //values
        temp = 0; //resets the temporary variable
        std::cout << "Larger num is " << large << " and smaller num is " << small << std::endl;
    }
    std::cout << "The GCD is: " << large << std::endl;
    return large;
}

int main(){
    GCD(12, 12);
    return 0;
}