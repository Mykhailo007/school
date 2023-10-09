#include <cstdlib>
#include <iostream>

int main(){
    double* dp = new double [10];
    for (int i = 0; i < 10; i++) 
        {dp[i] = 0.0;}

    for (int j = 0; j < 10; j++) 
        {std::cout << dp[j] << std::endl;}
    
    delete dp;

    return EXIT_SUCCESS;
}