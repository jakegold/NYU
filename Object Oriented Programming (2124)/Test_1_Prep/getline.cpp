/*
	Example of how to use getline and the extraction operator. 
	John Sterling
	CS1124
	Polytechnic University
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	// We'll need a string and an int throughout this example.
	string s;
	int n;

	// The function getline is good for reading in a whole line
	cout << "Enter a line of useless text:\n";
	getline(cin, s);
	cout << "You entered:\n" << s << endl << endl;

	// However if you intermix it with C++'s extraction operator
	// some problems can arise.  For example, if first we try to
	// read an integer:
	cout << "Pick a number: ";
	cin >> n;
	// and now we try to use getline, then we're going to have trouble.
	cout << "Enter some more junk:\n";
	getline(cin, s);
	cout << "You entered:\n" << s << endl << endl;
	// See, nothing came out.  If we want to see those words of wisdom,
	// then we would have to get another line:
	getline(cin, s);
	cout << "Ah, found your words:\n" << s << endl << endl;

	// A better solution would look like this
	cout << "Pick another number: ";
	cin >> n;
	cout << "Shower us with wisdom:\n";
	// This next line eats up the newline character that was causing
	// all the trouble.
	cin >> ws;
	getline(cin, s);
	cout << "You entered:\n" << s << endl << endl;

	return 0;
}