#include <stdio.h>

// Leaves the last one the same (will be written over)
void
rotate(char *x[], int size){
	char *temp = x[0];
	for (int i = 0; i < size-1; ++i){
		x[i] = x[i+1];
	}
}

void
editAtIndex(char *x[], int index, char string[]){
	x[index] = string;
}

int
main(){
	char *x[5];

	char zero[] = "zero";
	char one[] = "one";
	char two[] = "two";
	char three[] = "three";
	char four[] = "four";
	char five[] = "five";
	char six[] = "six";
	char seven[] = "seven";
	char eight[] = "eight";
	char nine[] = "nine";
	char ten[] = "ten";
	char eleven[] = "eleven";


	x[0] = zero;
	x[1] = one;
	x[2] = two;
	x[3] = three;
	x[4] = four;




	for (int i = 0; i < 5; ++i)
	{
		printf("%s \n", x[i]);
	}

	printf("\n");
	printf("Rotating \n");
	rotate(x, 5);
	printf("Editing at Index \n \n");
	editAtIndex(x, 4, five);


	for (int i = 0; i < 5; ++i)
	{
		printf("%s \n", x[i]);
	}

	return 0;
}
