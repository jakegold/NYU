#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
// COLLECTIONS
	vector<string> vs; // you need to say what is inside this vector...what its made of
	//cout << vs.size() << endl; //should return 0 because nothing inside of it yet

	vs.push_back("hi cisi"); //this is putting something inside of this vector at the back
	// note that this item is being copied and put at the end

	//then how do i get this to display?
	//cout << vs[0] << endl;

	//so now at this point i have 1 if i print:
	//cout << vs.size() << endl;

	vs.push_back("hi misi"); //this is now going to the back...so first is first

	/* how can i get all of these at once?
	for (size_t i = 0; i <vs.size(); ++i){
		cout << vs[i] << endl; 
	}
	aparently this is a bad way to do this...but up until c11 we had to do it this way
	

	// the new better way: (if i run this i will get a warning about c11)
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
			//what happens is that you are taking in the string and changing it 
			//within the vector...meaning that if u want to change it, this is the way to do it
			//but if you just wanted to keep everything how it was then you can super
			// screwed because things can change here...thats why the next way is a thing
	}
*/
// so best way
	for (const string & aString : vs) cout << aString << endl; //not sure why this is so diff..


	// what happens here? because the length is greater than the last index
	//cout << vs[vs.size()] << endl;
		//java can catch this error...cpp chooses not to because its slower
		//this will get something that isnt there...
		// depends on each case but its super screwed up dont ever do it 


	// you can easily add things at the end
	// you can also easliy remove from the end

	vs.pop_back();
	
	cout << "this is now the only thing in my vector: ";
	for (const string & aString : vs) cout << aString << endl;


	// but if i want to keep something before i ditch it...
	cout << vs.back() << endl;
	cout << "or this way" << endl;
	cout << vs[vs.size()-1] << endl;
	vs.pop_back();

	// but this is still getting rid of my last thing in my vector

	cout << "this is now the only thing in my vector: ";
	for (const string & aString : vs) cout << aString << endl;

	return 0;
}