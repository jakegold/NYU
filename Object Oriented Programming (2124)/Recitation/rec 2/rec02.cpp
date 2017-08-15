/*
This code should take a file of two words lines
and put those two word lines into vectors.
Then 
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Opens the file and returns an error if the file isn't opened
void openFile(ifstream & file);
// Fills the bigger vector with vector<string> from the file
void fillVector(ifstream & file, vector<vector<string> > & bigVector);
// Prints all contents of the bigger vector using one type of for loop
void printVector1(const vector<vector<string> > & bigVector);
// Prints all contents of the bigger vector using the other type of for loop
void printVector2(const vector<vector<string> > & bigVector);


int main() {
	// Declare Variables:
	ifstream infile;
	vector<vector<string> > vectorOfChemicals;
	// Run Functions:
	openFile(infile);
	fillVector(infile, vectorOfChemicals);
	cout << "this is test one: " << endl;
	printVector1(vectorOfChemicals);
	cout << "this is test two: " << endl;
	printVector2(vectorOfChemicals);

	// Close File:
	infile.close();

	return 0;

}





void openFile(ifstream & file){
	// Open the file
	file.open("chemicals.txt");
	// Print an error if the file cannot open
	if(!file){
		cerr << "File cannot be opened" << endl;
		exit(1);
	}

}
void fillVector(ifstream & file, vector<vector<string> > & bigVector){
	// Declare variables
	string chemicalName, chemicalProp;
	// Loop through the file
	while (getline(file, chemicalName)) {
		// Declare smaller vector placeholder
		vector<string> oneChemical;
		// Fill the smaller vector with contents from the file
		oneChemical.push_back(chemicalName);
		oneChemical.push_back(chemicalProp);
		// Fill the bigger vector with smaller vector
		bigVector.push_back(oneChemical);
	}

}
void printVector1(const vector<vector<string> > & bigVector){
	// Loop through the big vector (Loop is written out in three lines)
	for (size_t bigVectCount = 0; 
		bigVectCount < bigVector.size(); 
		++bigVectCount){
		// Put all vectors from the big vector into a counter
		vector<string> oneChemical = bigVector[bigVectCount];
		// Loop through the small vectors. (Loop is written out in three lines)
		for (size_t smallVectCount = 0; 
			smallVectCount < oneChemical.size(); 
			++smallVectCount){
			// Print out each element of the small vector
			cout << oneChemical[smallVectCount] << endl;
		}
	}

}
void printVector2(const vector<vector<string> > & bigVector){
	// Make a string holder
	string holder;
	// Loop through the bigger vector
	for (vector<string> oneChemical : bigVector){
		// Loop through the smaller vector
		for (holder : oneChemical){
			// Print out each item of smaller vector
			cout << holder << endl;
		}
	}

}




