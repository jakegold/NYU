/* 
Jake Goldstein 
CS_1124 09/13/15
This code will take a file that is decrypted using the ceaser cypher
and decrypt it. It will print out to the terminal the de-coded message.
HW00
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Will reverse the order of the lines from a file
void flipLines(ifstream & file, vector<string> & lineHolder); 
//Decyphers a letter that is decrypted by a ceaser code
char fixChar(char letter, int fixer); 
//Uses fixChar to decypher whole words
void fixString(string & word, int fixer); 

int main() { 

	// Declare Variables:
	int cypherNum = 0;
	ifstream encryption("encrypted.txt"); //Open the encrypted file
	vector<string> allTheLines;

	// Get the number of the cypher from file and put that into an int
	encryption >> cypherNum;

	// Run Fucntions: 
	flipLines(encryption, allTheLines);//Puts lines from file in correct order

	// Loop through the vector and stop on each string element
	for (size_t vectSize = 0; vectSize < allTheLines.size(); ++vectSize){ 
		// For each string element in the vector, fix the string
		fixString(allTheLines[vectSize], cypherNum);
		// Output Message:
		cout << allTheLines[vectSize] << endl;
	}

	// Close Files:
	encryption.close();

	return 0;

} 


void flipLines(ifstream & file, vector<string> & lineHolder){
	// Declare Variables:
	string aLineFromFile;
	vector<string> vectorHolder; //This is a place holder vector of strings
	// Put all the lines of the file in the place holder vector
	while (getline(file, aLineFromFile)){
		vectorHolder.push_back(aLineFromFile);
	}
	// Loop through placeholder putting lines in correct order in corrct vector
	for (size_t numOfLines = vectorHolder.size(); numOfLines > 0; --numOfLines){
			//This is a string place holder
			string wordHolder = vectorHolder[numOfLines-1];
			//Put the lines in the correct vector in order
			lineHolder.push_back(wordHolder);
	}
}

char fixChar(char letter, int fixer){
	// Test to see if the letter is not a lower case letter
	if (!islower(letter)){
		// If not, return input
		return letter;
	}
	else {
		//Decrypt the letter
		letter = letter - fixer;
		//Check to see if letter is not lower case
		if (!islower(letter)){
			// If not make lowercase
			letter = letter + 26;
		}
	}
	return letter;
}

void fixString(string & word, int fixer){
	//Loop through the whole word
	for (int myLetter = 0; myLetter < word.length(); ++myLetter){
		//Fix each letter by using fixChar
		word[myLetter] = fixChar(word[myLetter], fixer);
	}
	
}