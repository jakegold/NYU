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
	++x
}
//this is a copy! Copy is a waste of time
void printAString(string cisi){
	cout << cisi << endl;
}
//but this may lead to bugs...because string can still be changed..unless u want to change it
void printABetterString(string & cisi){
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


int main(){
// COLLECTIONS
	vector<string> vs; // you need to say what is inside this vector...what its made of
	cout << vs.size() << endl; //should return 0 because nothing inside of it yet

	vs.push_back("hi cisi"); //this is putting something inside of this vector at the back
	// note that this item is being copied and put at the end

	//then how do i get this to display?
	cout << vs[0] << endl;

	vs.push_back("hi misi"); //this is now going to the back...so first is first

	// how can i get all of these at once?
	for (size_t i = 0; i <vs.size(); ++i){
		cout << vs[i] << endl; 
	}
	// aparently this is a bad way to do this...but up until c11 we had to do it this way

	// the new better way:
	for (string aString : vs){ // (ranged for aka for each)
	//this is saying for each time through this loop copy this item into my new decleration 
		cout << aString << endl;
	}
// note that you can also write your one line loops likewise as long as they are short enough:
	for (string thisString : vs) cout << thisString << endl;

//in this way you are copying things! if i want to avoid that:
	for (string & aString : vs){ //now its not copying its being brought it
		cout << aString << endl;
		//if i then mess with the string...
		//aString = "you fool"; -- because then you are messing with everything...TEST THIS LATER
		//then you screwed up everything
	}

// so best way
	for (const string & aString : vs) cout << aString << endl; //not sure why this is so diff..

	// what happens here? because the length is greater than the last index
	cout << vs[vs.size()] << endl;
	//java can catch this error...cpp chooses not to because its slower
	//this will get something that isnt there..
	// depends on each case but its super screwed up dont ever do it 


	// so how to do this?
	cout << vs.at(vs.size()) << endl;

	// you can easily add things at the end
	// you can also easliy remove from the end

	vs.pop_back();

	// but if i want to keep something before i ditch it...
	cout << vs.back() << ' ' << vs[vs.size()-1] << endl;
	vs.pop_back();
	// but this is still getting rid of my last thing in my vector

// FUNCTION TESTINGS..SEE ABOVE

	int someInt = 17;
	addOne(someInt); //run our function...
	//that 17 was copied into the function!
	// So what will return????
	cout << someInt << endl;

	// so lets try this
	someInt = addOneNew(someInt);
	//this will give us what we want

	// but is this the best way to do this?
	addOneBest(someInt); //when writing this DONT use the &..only at the top
	//now someint is changed to 18 because thats what we are changing!
	cout << someInt << endl;



	return 0;
}