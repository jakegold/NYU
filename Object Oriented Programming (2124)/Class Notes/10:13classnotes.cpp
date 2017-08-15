#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;


// NOTE THAT THE MID-TERM IS ON THIS COMING TUESDAY!!!

/* Protected:
	what does it mean? if there is a base class that has a method that is protected
	that means that any classes that are below, only that class can use that method on itself
	for example if i had a pet with a getName method and under that i had a dog and a cat,
	i can get dog's name in dog, and get cat's name in cat, but i cant get dog's name in cat!



	also for some reason(?) if i call in the main cout << felix.getName();  (where felix is a cat)
	that shouldn't work 
	(i think because in main you cannot use a protected method because its only in a class)
*/

/*
	Things that I should learn for the test:

	loops (specifically for each) ex: for(int cisi: bigVector){code} ....this is when your looping
	though a vector called bigVecot and its all of ints

	who created certain lang.s ex: who made c++(stroustrup), python(van rossum), java(gosling)??

	when to use & because thats super important!

	know which way these things so << >> and when ex: cout << vs. cin >> 

	when i should use pointers (*) and when to use -> !!!!

	when to use const

	understand the heap and when to use delete or new

	go over his notes online and my notes and everything

	what is overloaded? (its a function with the same name and return but different parameter lists)
	note that for overloading it all happens at compile time (which is before it can see the main)

	what is virtual? (note that it can only be used in methods)
	what is polymorphism? (it has to do with virtual) 

	difference between classes and structs
	
	note:key word override can be used before the {} of a method that you are overriding
	and cpp11 will catch it if you screw something up that your trying to override 
	override only works if it is a virtual method

	what is this? (note that it is a pointer)

	what is protected? (see above)

	(WHO IS GALAGER?? he works at poly)

*/
int main(){
	// note that for this class for the most part we are just looking at code that he has
	// and we are tlaking about his code
	return 0;
}