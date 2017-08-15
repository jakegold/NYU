/*
this code has as a function making the charachter fix itself
but it must be passed the letter AND the number of times
it also has in the main the same concept for words
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

char fixChar(char letter, int fixer);
void fixString(string & word, int fixer); 

int main(){
	int counter;
	string word;
	cout << "choose a number" << endl;
	cin >> counter;
	cout << "chose a word" << endl;
	cin >> word;
	fixString(word, counter);
	cout << word << endl;
	return 0;
}

char fixChar(char letter, int fixer){
	if (!isalpha(letter)){
		cout << "not part of abc's" << endl;
		exit(1);
	}
	if (!islower(letter)){
		cout << "it is not lower case" << endl;
		exit(1);
	}
	else {
		letter = letter - fixer;
		if (!islower(letter)){
			letter = letter + 26;
			//cout << letter << endl;
		}
	}
	return letter;
}

void fixString(string & word, int fixer){
	//loop through the whole word
	for (int myword = 0; myword < word.length(); ++myword){
		//fix each letter by using fixChar
		word[myword] = fixChar(word[myword], fixer);
	}
	
}