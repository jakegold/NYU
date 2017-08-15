// Jake Goldstein HW02 Questions 2 and 3 Programming part
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Functor class to compare even or odd
class OddOrEven{
public:
	// Will return true if even else false
	bool operator()(const int& num) const{
		return (num % 2 == 0) ? true : false;
	}
};

// Functor class to compare string size
class StringSize{
public:
	// Will return true if the first string is shorter than the second else false
	bool operator()(const string& first, const string& second) const{
		return (first.length() < second.length()) ? true : false;
	}
};

// Functor template (used for OddOrEven)
template <class Object, class Comparator>
bool checkMe(const Object& thing, Comparator comp);

// Functor template (used for StringSize)
template <class Object, class Comparator>
bool checkMe(const Object& item1, const Object& item2, Comparator comp);



int main(){
	// Create a vector of ints (ranging from 1-20) to test functor with
	vector<int> myIntVec;
	for (int i = 0; i < 50; ++i){
		int x = (rand() % 20);
        myIntVec.push_back(x);
	}
	// Test the functor
	cout << "Testing OddOrEven" << endl;
	for (int i = 0; i < myIntVec.size(); ++i){
		// If even print even
		if (checkMe(myIntVec[i], OddOrEven())){
			cout << myIntVec[i] << " Even!" << endl;
		}
		// Else print odd
		else{
			cout << myIntVec[i] << " Odd" << endl;
		}
	}
	cout << "###########################" << endl;
	cout << "Testing StringSize" << endl;
	/* 
	** Create a vector of strings to test functor with 
	** The vector is filled with strings of numbers
	** Because it's easy to create random ints of varrying lengths
	** The ints were then converted to strings to be compared
	*/
	vector<string> myStringVec;
	// Get 50 random ints from 0-20000
	for (int i = 0; i < 50; ++i){
		int x = (rand() % 20001);
		// Convert those ints to strings
		string s = to_string(x);
        myStringVec.push_back(s);
	}
	// Test the functor
	for (int i = 0; i < myStringVec.size()-1; i+=2){
		cout << myStringVec[i] << " VS. " << myStringVec[i+1] << ':';
		// If the first one is smaller print that
		if (checkMe(myStringVec[i], myStringVec[i+1], StringSize())){
			cout << "    The FIRST one is smaller!" << endl;
		}
		// If the second is smaller (or they are the same size) print that
		else{
			cout << "    The SECOND one is smaller (or the same size)" << endl;
		}
	}
	return 0;
}

// Functor template (used for OddOrEven)
template <class Object, class Comparator>
bool checkMe(const Object& thing, Comparator comp){
	return comp(thing);
}

// Functor template (used for StringSize)
template <class Object, class Comparator>
bool checkMe(const Object& item1, const Object& item2, Comparator comp){
	return comp(item1, item2);
}
