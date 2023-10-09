#include<stdio.h>

int highfives (char hall[]) ;

int highfives (char hall[]){
	int i = 0;
	int numHF = 0;
	while (hall[i]){
		if (hall[i]=='>'){
			int j=i;
			while(hall[j]){
				if (hall[j]=='<'){
					numHF++;
				}
				j++;
			}
		}
		i++;
	}
	return numHF;
}

int main () {
	char hall1[] = ">><<";
	char hall2[] = ">-<<->----<><>>-";
	char hall3[] = ">-<->--<<>><->-<-->-<--->-<>->>->>-<<<->";
	printf("Hall 1 should have 4 high fives.  You got %d\n", highfives(hall1));
	printf("Hall 2 should have 7 high fives.  You got %d\n", highfives(hall2));
	printf("Hall 3 should have 63 high fives.  You got %d\n", highfives(hall3));
}


