#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

// There was a class missed the code should be online where its a marrige between two people
// Association and pointers are what we are dealing with now!! GO OVER THE NOTES THAT I MISSED

// Find out what an "& adress of" opperator is
// Also find out what this is: "int* p" i think it means that p is a variables that can hold the adresses of ints
// but not clue what that means

// We new types in order to do this things...i think that P is a pointer
// "*P dereference opperator" also find out what that is... it think it modifies a pointer

// by using the things above we should be able to solve an probles we have with association

// note that a null pointer is written like this in cpp11: "nullptr"

// so we are trying to deal with marrigies so we what did was we added a pointer of a person "*person spouse"
// and if that pointer is null than they are not married...but if it points to a spouse than they are married

// note that if we has something like " *spouse.name " it would be an error because . goes before * so you need to do
// this " (*spouse).name " and then we would get an error
// but there is anoter way to do this that is nicer : spouse - > name (im not sure how the spacing works i think 
// it would still work like how i did it)

// This would be the method that makes people marry eachother and has their pointers point to the respective objects
/* void marries(Person & betrothed){ */
 	// This like is easy it makes sense your setting the spouse to the betrothed that is passed
 	/*spouse = & betrothed;*/
 	// But this line was difficult...you cant do it if you dont use "this"!!! "this" can only be used in a method
 	// now its saying taked the betrothed spouse and set it equal to this...need to see the rest of the code
 	// to really understand whats going on here

 	// wrote this later:
 	// i think it has to with your doing this in a class...so it has to be like name.marries...
 	// so when this is run the this reffurs to the name!
 	/*betrothed.spouse = this;
 } */

// Note that the private part of the class from the method above is:
/*private:
	string name;
	Person* spouse;*/
// this should help understand the above lines better but really go voer notes

// this code (from the method) doesnt account for what happens if some is married to someone else
// but then there is a call for me to marry someone else...then there is a huge bug

// so maybe in order to fix that you need an if statment saying if they are both single...like this:
/*if(spouse == nullptr && betrothed.spouse == nullptr) */// now it should only allow marrigie if they are both single
// but this is a problem because the main doesnt know that it fails...this is called fail silently
// this happens when you have a function but it doesnt do what it wants to do..there should be a return value
// so if the code works return true at the end of the if statment
// if the if doesnt run return false...note that the return type would need to change from void to bool

// anothher way that this could have been done is change the first marrige to null

// dennis ritchie made c (like the language)


// Now dealing with new and delete:
// note that the same way that when you open a file you close it..when you make new things delete them later
	// if i were to assign another new things without deleteing it i would have a memeory leak or
	// garbage on the heap...they are the same thing its when you are just wasting memory
	// note that in java we had a garbage collection and it just did this for us...now we have to do it ourselves
	// this could be dangerous because if i switch from a garbage collection lang to a non one like from java to cpp
	// then you might just be leaving memory eberywhere
int main(){
	int* q = new int(28);
	// q is a pointer that is pointing to 28
	cout << q << " this is gibberish because this is the adress" << endl;
	cout << *q << " this should be 28" << endl;
	delete q; //does not effect q
	// now this spot in my heap..a part of my memory that stores some information if i ask for it
	// gets erased i guess...dont really understand how this works..i think its deleteing the 28 part,
	// but the q part still exists...in fact it is still pointing to the same location
	cout << q << " this is gibberish because this is the adress" << endl;
	cout << *q << " this should be anything that is at this location" << endl;
	// in fact this last line may not compile...im not even using space in memory anymore...who knows whats there
	//im not sure why in my case it is giving me 28 still... but ok

	// now we want to make a collection of pointers: so would look like this if i was reading from a file
	vector<Preson*> poly;
	string name;
	ifstream infile ("people.txt");
	if (!infile) {}
	while (infile >> name){
		Person* personPtr = new Person(name);
		poly.push_back(personPtr);
	}
	people.close();

	for (const Person* pptr : poly){
		pptr - > display();
	}
	for (Person* pptr : poly){
		delete pptr;
	}



// the last couple of lines here are just whhhhuuuuaatttt...need to go over those and my notes from online
	// and all that stuff but it should be chill
	return 0;
}






