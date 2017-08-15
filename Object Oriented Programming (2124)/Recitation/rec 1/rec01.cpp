/* Jake Goldstein
This will read a file and print out to ther terminal 
how many lines there are in the file, how many words
and how many charachters there are
Recitation 1
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	// Declare variables
	string line, word;
	char letter;
	int lineCounter = 0, wordCounter = 0, letterCounter = 0;
	// open the file
	ifstream infile1("jabberwocky.txt");
	// test to see if the file exists
	if (!infile1){
		cerr << "Error, file does not exist" << endl;
		exit(1);
	}
	// count total lines in file
	while(getline(infile1, line)){
		cout << line << endl;
		++lineCounter;
		//cout << "Line Number: " << lineCounter << endl;
	}
	cout << "Total number of lines: " << lineCounter << endl;
	// close the file
	infile1.close();

	// open the file again to count the words
	ifstream infile2("jabberwocky.txt");
	// test to see if the file exits
	if (!infile2){
		cerr << "Error, file does not exist" << endl;
		exit(1);
	}
	// count total words in file
	while(infile2 >> word)
		++wordCounter;
	cout << "Number of words: " << wordCounter << endl;
	// close file
	infile2.close();

	// open the file again to count charachters
	ifstream infile3("jabberwocky.txt");
	//include the white spaces
	infile3 >> noskipws;
	// test to see if the file exists
		if (!infile3){
		cerr << "Error, file does not exist" << endl;
		exit(1);
	}
	// cout total charachters in file
	while(infile3 >> letter)
		++letterCounter;
	cout << "Number of charachters: " << letterCounter << endl;
	// close file
	infile3.close();
	return 0;
}




