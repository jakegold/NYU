#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

char fixChar(char letter, int fixer);

int main(){
	char c;
	int k;
	cout << "enter letter" << endl;
	cin >> c;
	cout << "enter number" << endl;
	cin >> k;
	char thisone = fixChar(c, k);
	cout << thisone << endl;
	return 0;
}

char fixChar(char letter, int fixer){
	// test to see if the letter is lower case or not
	if (!isalpha(letter) || !islower(letter)){
		return letter;
	}
	else {
		//decrypt the letter
		letter = letter - fixer;
		//make sure that the letter is lower case
		if (!islower(letter)){
			letter = letter + 26;
		}
	}
	return letter;
}