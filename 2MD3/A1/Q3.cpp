#include <cstdlib>
#include <iostream>

int x = 5;

void f(int x){
    x++;
    std::cout << x << std::endl;
}

void g(int& x){
    x++;
    std::cout << x << std::endl;
}