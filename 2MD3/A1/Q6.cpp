#include <cstdlib>
#include <iostream>
#include <vector>
#include <random>

using namespace std;

void birthday_paradox(){
    int count;
    srand(time(0)); //creates the seed for rand() function
    for (int n = 5; n < 101; n = n + 5){ //runs through values of n from 5-100
        int experiment = 0;
        for (int i = 0; i < 100; i++){//running through 100 experiments per
                                      //value of n
            int birthdays[n]; //initializes an array that contains the birthdays
                              //of each person in the room
            count = 0;
            for (int j = 0; j < (n+1); j++){ //filling the array with birthdays
                int output = 1 + (rand() % static_cast<int>(364));
                //random numbers from 1 to 365
                birthdays[j] = output; //sets each persons birthday
            }
            for (int k = 0; k < n; k++) {
                for (int l = k + 1; l < n; l++){
                    if (birthdays[k] == birthdays[l]){ //checks each persons 
                    //day of birth and checks to see if anyone else in the room 
                    //also has the same day of birth
                        count ++; //adds one for every person with the same 
                                  //birthday
                    }
                }
            }
            if (count != 0){
                experiment++; //if there is atleast one pair of people who share
                              //a birthday then the experiment is added
                              //as a successful experiment
            }
        }
        cout << n << ',' << experiment << ',' << experiment*0.01 << endl;
    }
}

int main(){
    birthday_paradox();

    return 0;
}