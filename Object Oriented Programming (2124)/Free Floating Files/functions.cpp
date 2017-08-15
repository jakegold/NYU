#include <iostream>
#include <vector>
#include <string>

using namespace std;



// FUNCTIONS: TESTING IS BELOW 
//what is it returning -- the name of the function -- whats passed to the function
void addOne(int x){
	++x;
}

int addOneNew(int x){
	++x;
	return x;
}
//this is keeping that x and changing it not copying it
void addOneBest(int & x){
	++x;
}
//this is a copy! Copy is a waste of time
void printAString(string cisi){
	cisi = "goldstein";
	cout << cisi << endl;
}
//but this may lead to bugs...because string can still be changed..unless u want to change it
void printABetterString(string & cisi){
	cisi = "goldstein";
	cout << cisi << endl;
}

void printBestString(const string & cisi)
{
	cout << cisi << endl;
	//now this line would not run because you cant change the string!
	// cisi = "you are not a cisi!";
}
// Note that the correct way to do this is to make a copy of the function
// at the top of the page and then define it at the bottom
// good code has the first code with words in it be the main

int main () {
	// FUNCTION TESTINGS..SEE ABOVE

	int someInt = 17;
	addOne(someInt); //run our function...
	//that 17 was copied into the function!
	// So what will return????
	cout << "test one: void method no '&'  "<< endl;
	cout << someInt << endl;

	// so lets try this
	cout << "test two: entering the addOneNew function " << endl;
	someInt = addOneNew(someInt);
	cout << "now the int is: " << someInt << endl;
	//this will give us what we want


	// but is this the best way to do this?
	cout << "test three: void with '&' "<< endl;
	addOneBest(someInt); //when writing this DONT use the &..only at the top
	//now someint is changed to 19 because thats what we are changing!
	// (note that for test two it was changed to 18)
	cout << "now the int is: " << someInt << endl;


	cout << "done playing with numbers, now strings" << endl;

	string jake = "jake";
	cout << "test one: print a string" << endl;
	printAString(jake);
	cout << "leaving the function...what is my string? " << jake << endl;

	//that is what happens when you copy
	printABetterString(jake);
	cout << "test two: printABetterString..." << jake << endl;

	cout << "turning the string back to jake.." << endl;
	jake = "jake";

	printBestString(jake);
	cout << "now it cant change in the funtion.." << jake << endl;


	return 0;
}
