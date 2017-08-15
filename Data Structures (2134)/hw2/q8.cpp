#include <iostream>
#include <string>

using namespace std;

string & getName(){
	string name;
	cout << "Please enter your name: ";
	cin >> name;
	cout << "Hi " << name << '!' << endl;
	return name;
}

int main(){
	cout << getName();
}