#include<stdio.h>

int getRekt (int n, int* numAdditions, int* numSubtractions) ;

int getRekt(int n, int* numAdditions, int* numSubtractions){
	int len[n];
	int var[n];
	int j=0;
	while (j<n){
		var[j]=j;
		++j;
	}
	for(int i=0; i<n; i++){
		if (i==0){
			len[i]=i;
		}
		else if (i==1){
			len[i]=i;
		}
		else{
			int test_prev = 0;
			for (int y=0; y<=i; y++){
				if (len[y]==len[i-1]-i){
					test_prev = 1;
					break;
				}
				else{}
			}
			int test_val = len[i-1]-i;
			if ((test_prev==0) && (test_val>0)){
				len[i] = len[i-1] - i;
				numAdditions;
			}
			else if (test_prev == 1){
				len[i] = len[i-1] + i;
				++numSubtractions;
			}
			else{
				printf("your code broke\n");
			}

		}
		
		return len[n-1];
	}
}

int main () {
	int additions;
	int subtractions;

	int correct_recaman[20] =      {0, 1, 3, 6, 2, 7, 13, 20, 12, 21, 11, 22, 10, 23, 9, 24,  8, 25, 43};
	int correct_additions[20] =    {0, 1, 2, 3, 3, 4,  5,  6,  6,  7,  7,  8,  8,  9, 9, 10, 10, 11, 12};
	int correct_subtractions[20] = {0, 0, 0, 0, 1, 1,  1,  1,  2,  2,  3,  3,  4,  4, 5,  5,  6,  6,  6};

	int x;

	for (int i = 1; i <= 19; i++) {
		additions = 0;
		subtractions = 0;
		x = getRekt(i,&additions,&subtractions);
		printf("For n = %d...\n", i);
		if (x == correct_recaman[i-1]) {
			printf("\tThe return value (%d) is correct.\n", x);
		} else {
			printf("\tThe return value (%d) is incorrect and should be %d.\n", x, correct_recaman[i-1]);
		} 
		if (additions == correct_additions[i-1]) {
			printf("\tThe number of additions (%d) is correct.\n", additions);
		} else {
			printf("\tThe number of additions (%d) is incorrect and should be %d.\n", additions, correct_additions[i-1]);
		} 
		if (subtractions == correct_subtractions[i-1]) {
			printf("\tThe number of subtractions (%d) is correct.\n", subtractions);
		} else {
			printf("\tThe number of subtractions (%d) is incorrect and should be %d.\n", subtractions, correct_subtractions[i-1]);
		} 
	}
}
