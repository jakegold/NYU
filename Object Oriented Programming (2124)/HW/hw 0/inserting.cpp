#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void flipLines(ifstream & file, vector<string> & lineHolder); // will reverse the order of the lines from a file
char fixChar(char letter, int fixer); //decyphers the code letter by letter
void fixString(string word, int fixer); //uses fixChar to decypher words

int main() { 

// Declare Variables:
int lettersBack = 0;
ifstream encryption("encrypted.txt"); //open the encrypted file
vector<string> allTheLines;

// get the number of the cypher 
encryption >> lettersBack;

// Run Fucntions: 
flipLines(encryption, allTheLines); //puts the lines in the correct order
// loop through the vector and stop on each string element
for (int i = 0; i <= allTheLines.size(); ++i){ 
	cout << allTheLines.size();
	// for each string element, fix the string
	//fixString(allTheLines[i], lettersBack);
	// Output Message:
	cout << allTheLines[i] << endl;
}

// Close Files:
encryption.close();
return 0;

} 


void flipLines(ifstream & file, vector<string> & lineHolder){
	// Declare Variables:
	string aLineFromFile;
	vector<string> fake;
	// Put all the lines of the file in a vector in the correct order
	while (getline(file, aLineFromFile)){
		fake.push_back(aLineFromFile);
	}
	// a test...Return to terminal the lines in new order
	for (int numOfLines = fake.size(); numOfLines >=0; --numOfLines){
			string help = fake[numOfLines]; 
			lineHolder.push_back(help);
		}
	}





