#include <stdio.h>
#include <assert.h>
#include <math.h>

void mileage (void);

void mileage (void){
    
    float total_distance = 0;
    float input_distance;
    float total_fuel = 0;
    float input_fuel;
    char y_or_n[1];

    do {
        printf("How much fuel have you used? : ");
        scanf("%f", &input_fuel);
        printf("How far did you travel? : ");
        scanf("%f", &input_distance);
        printf("Do you have more data to enter? (y/n) : ");
        scanf("%1s", y_or_n);

        total_distance += input_distance;
        total_fuel += input_fuel;
    }
    while (y_or_n[0] == 'y');

    printf("Your gas mileage is %f", total_distance/total_fuel);
}

int main () {
	mileage();
    return 0;
}

