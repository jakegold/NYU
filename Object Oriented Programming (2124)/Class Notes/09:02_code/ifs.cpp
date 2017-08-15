// loops and conditions
#include <iostream>
#include <string>

using namespace std;

int main(){
	int x;
	cout << "42 might be a good choice, but so would 17" << endl;
	cin >> x;
	string c;
	cout << "maybe try fred?...but maybe only if you chose 17" << endl;
	cin >> c;
	if (x == 42){ /* note: you can use only one = in cpp
		in java that would fail
		you can do it here and its setting the thing equal 
		and testing to see if its true*/ 
		cout << "the answer!\n";
	}
	else if (x == 17 && c == "fred"){ //&& is and, || is or, ! is not
		cout << "some other thing\n";
	}
	else {
		cout << "not the answer\n";
	}
}