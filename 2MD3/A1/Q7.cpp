#include <cstdlib>
#include <iostream>
#include <vector>
#include <random>

class Pair {  //  a generic progression
 public:
    
};


int main() {
    Pair<int, double> p1(1, 7.3);
    p1.print();
    Pair<std::string, double> p2("hello", 7.7);
    p2.print();
    Pair<float, long> p3(1.2, 777777773);
    p3.print();
}
