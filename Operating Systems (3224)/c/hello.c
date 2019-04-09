#include <stdio.h>

int 
main(){
	char name[] = "Jake";
	int age, height;

	age = 21;
	height = 68;

	printf("Hello World! \n \n");

	printf("Hello, my name is %s \n", name);
	printf("I am %d years old \n", age);
	printf("I am %d inches tall \n \n ...give or take \n", height);
	return 0;
}
