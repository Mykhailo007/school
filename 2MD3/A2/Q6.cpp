#include <iostream>
#include <vector>

using namespace std;

int n, first, x;

void xValueSearch (){
    cin >> n >> first >> x; //the first 3 inputs are added

    vector<pair<int, int>> array(n+1); //initiates the 2D vector array

    for (int i = 1; i <= n; i++){ //creates the singly linked list from user 
                                  //inputs
        int arrayValue, arrayNext;
        cin >> arrayValue >> arrayNext;
        array[i] = {arrayValue, arrayNext};
    }

    int output = -1;
    int cur = first;
    while (cur != -1){ //traverses the singly linked list until the end where
                       //the index is -1
        if (array[cur].first >= x){
            if (output != -1){ 
                //checks to see if there has already been an number greater 
                //than or equal to x
                if (array[cur].first < output){
                    output = array[cur].first; //sets the new value which 
                    //passes all parameters
                    }
                }
            else {
                output = array[cur].first;//if the output hasn't been changed 
                //yet then then we set it to whatever is the first element of
                //the 2D vector array
            }
            }
        cur = array[cur].second; //sets the next index
    }

    cout << output << endl;
}


int main(){
    xValueSearch();

    return 0;
}