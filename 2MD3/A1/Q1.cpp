#include <cstdlib>
#include <iostream>

using namespace std;

int y = 21;
int* A = &y;

int multiply(int* B){
    int x = (*B)*2; 
    
    cout << x << endl;


}

int main(){
    multiply(A);
    for (int i = 0; i < 4; i++){
        cout << i << endl;
    }
    
}