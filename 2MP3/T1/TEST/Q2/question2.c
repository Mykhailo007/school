#include<stdio.h>

int highfives (char hall[]) ;

int highfives (char hall[]){
	int SizeHW = sizeof(hall)/sizeof(hall[0]);
	int numHF;
	for (int i = 0; i<SizeHW; i++){
		if (hall[i]=='>'){
			while(i<SizeHW){
				if(hall[i]=='<'){
					++numHF;
				}
				++i;
			}
		}
	}
}

int main () {
	char hall1[] = ">><<";
	char hall2[] = ">-<<->----<><>>-";
	char hall3[] = ">-<->--<<>><->-<-->-<--->-<>->>->>-<<<->";
	printf("Hall 1 should have 4 high fives.  You got %d\n", highfives(hall1));
	printf("Hall 2 should have 7 high fives.  You got %d\n", highfives(hall2));
	printf("Hall 3 should have 63 high fives.  You got %d\n", highfives(hall3));
}


