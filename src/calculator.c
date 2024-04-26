#include <stdio.h>
#include <stdlib.h>

//Completely diff project which might be incorporated to this one
int main(){
	int numOfNum;
	printf("How many numbers? ");
	scanf("%d", &numOfNum);
	
	int num[numOfNum];
	char operators[numOfNum - 1];
	for (int i = 0; i < numOfNum; i++) {
	
		printf("Insert number %d: ", i + 1);
		scanf("%d", &num[i]);
	}
	for (int i = 0; i < numOfNum - 1; i++) {
		printf("Operators #%d: ", i + 1);
		scanf(" %c", &operators[i]);
	}
	
	printf("Is your equation \"");
	for (int i = 0; i < numOfNum - 1; i++) {
		printf("%d ", num[i]);
		printf("%c ", operators[i]);
	}
	printf("%d\"?\n", num[numOfNum - 1]);
	
	int *effNum;
   	effNum = calloc(numOfNum, sizeof(int));
	
	for (int i = 0; i < sizeof(operators)/sizeof(char); i++){
		if (operators[i] == * || operators [i+1] == *) {
			effNum[i] = num[i] * num[i + 1];
		}
		if (operators[i] == * || operators [i+1] == *) {
			effNum[i] = num[i] * num[i + 1];
		}
	}
	/*
   	int *new_ptr;
   	new_ptr = reallocarray(ptr, 999, sizeof(int));
   	ptr = new_ptr;
*/
	
	
	//printf("%d", );
	
	return 0;
}