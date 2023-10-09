#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int vectorMinMax(const vector<int> &A, int index, int &minValue, int &maxValue){
    if (index == A.size()){
        return 0;
    }

    if (A[index] < minValue){
        minValue = A[index];
    }
    if (A[index] > maxValue){
        maxValue = A[index];
    }

    vectorMinMax(A, index + 1, minValue, maxValue);
}

int main(){
    vector<int> A = {1, -2, 0, 6, 66, -7};
    int minValue = A[0];
    int maxValue = A[0];
    vectorMinMax(A, 0, minValue, maxValue);

    cout << "Min " << minValue;
    cout << " Max " << maxValue << endl;
}