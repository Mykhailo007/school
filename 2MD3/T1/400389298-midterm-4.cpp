#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

void rearrange(vector<int>& data, int i=0, int j=-1) {
    if (j == -1) {
        j = data.size() - 1;}
    
    if (i >= j) return;

    if (data[i] % 2 == 0) rearrange(data, i+1, j);
    
    else if (data[j] % 2 == 1) rearrange(data, i, j-1);

    else {
        swap(data[i], data[j]);
        rearrange(data, i++, j--);
    }
}

void print(vector<int>& data) {
    for (int i = 0; i < data.size(); i++) {
        cout << data[i] << ' ';
    }
    cout << endl;
}

int main() {
    // Test 1: empty vector
    vector<int> v1 = {};
    rearrange(v1);
    assert(v1 == vector<int>());

    // Test 2: Already rearranged vector
    vector<int> v2 = {2, 4, 6, 1, 3, 5};
    rearrange(v2);
    print(v2);
    assert(v2 == vector<int>({2, 4, 6, 1, 3, 5}));

    // Test 3: Random vector
    vector<int> v3 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    rearrange(v3);
    print(v3);
    vector<int> expected_v3 = {2, 4, 6, 8, 1, 3, 5, 7, 9};
    assert(v3 == expected_v3);

    cout << "All tests passed." << endl;
    return 0;
}