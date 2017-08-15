//we said that you can read from the code to the terminal...but not the opposite 

#include <iostream>
#include <string>

using namespace std;

int main(){
	int x;
	string s;
	// note that s and x are bad names...
	cout << "first a number then a word or line" << endl;
	cin >> x; //this will fail if you dont type what type its expecting
	cin >> s;
	cout << x << endl;
	cout << s << endl;
	//strings only work on words..how do you get a line?
	getline(cin, s); //it has two parameters 
	//and asks how are u giving me this info and to what variable
	return 0;
}