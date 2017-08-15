/* 
Jake Goldstein 
CS_1124 09/20/15
This code will take a file that is a list of hyrdocarbons
and will sort the elements based of their carbon values.
It will run those instructions, even if it means some warriors must die.
HW01
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

struct Molecule{
	int numOfC;
	int numOfH;
	vector<string> names;
};

// Opens the file and returns an error if the file isn't opened
void openFile(ifstream & file);

// Reads the file and fills a vector with molecules from the file
void readFile(ifstream & file, vector<Molecule> & hydrocarbons);

// Checks a vector for a molecule with the same make-up and returns the index
size_t checker(int cNumber, int hNumber, const vector<Molecule> & hydrocarbons);

// Displays all molecules
void displayList(const vector<Molecule> & hydrocarbons);

// Loop through vector and return highest number of carbon
int getLargestCarbon(const vector<Molecule> & hydrocarbons);

// Loop through vector and return smallest number of carbon
int getSmallestCarbon(const vector<Molecule> & hydrocarbons);

int main(){
	// Declare molecules
	ifstream infile;
	vector <Molecule> myMolecules;
	// Run functions
	openFile(infile);
	readFile(infile, myMolecules);
	displayList(myMolecules);
	infile.close();
	return 0;

}

void openFile(ifstream & file){
	// Open the file
	file.open("hydrocarbons.txt");
	// Print an error if the file cannot open
	if(!file){
		cerr << "File cannot be opened" << endl;
		exit(1);
	}
}

void readFile(ifstream & file, vector<Molecule> & hydrocarbons){
	// Declare variables
	string newName; 
	char useless;
	vector <string> names;
	int carbon, hydrogen;
	// While file can be read
	while (file >> newName){
		// Get information from file
		file >> useless >> carbon >> useless >> hydrogen;
		// Run functions to make code easier to read
		size_t index = checker(carbon, hydrogen, hydrocarbons);
		size_t size = hydrocarbons.size();
		// If this is a new carbon and a new hydrogen
		if (index == size){  
			// Put the new element in the vector
			Molecule placeHolder;
			placeHolder.names.push_back(newName);
			placeHolder.numOfC = carbon;
			placeHolder.numOfH = hydrogen;
			hydrocarbons.push_back(placeHolder);
		}
		else {
			hydrocarbons[index].names.push_back(newName);
		}
	}
}

size_t checker(int carbonNumber, int hydrogenNumber, const vector<Molecule> & hydrocarbons){
	// Declare variables
	Molecule moleculeNew;
	// Loop through the vector on each element
	for (size_t i = 0; i < hydrocarbons.size(); ++i){
		moleculeNew = hydrocarbons[i];
		// If an element has the same carbon and hydrogen numbers as number passed
		if (moleculeNew.numOfC == carbonNumber && moleculeNew.numOfH == hydrogenNumber){
			// Return the index
			return i;
		}
		
	}
	// Avoids warrnings
	return hydrocarbons.size();
}

void displayList(const vector<Molecule> & hydrocarbons){
	// Gets largest and smallest carbon from vector of all elements
	int big = getLargestCarbon(hydrocarbons);
	int small = getSmallestCarbon(hydrocarbons);
	while (big >= small){
		// Loop through the vector of elements
		for (size_t i = 0; i < hydrocarbons.size(); ++i){
			// If this is the smallest carbon
			if (hydrocarbons[i].numOfC == small){ 
				// Print out its chemical make-up
				cout << 'C' << hydrocarbons[i].numOfC;
				cout << 'H' << hydrocarbons[i].numOfH << endl;
				// Print out chemical name
				for (int j = 0; j < hydrocarbons[i].names.size(); ++j){
					cout << hydrocarbons[i].names[j] << endl;
				}
				cout << endl;
			}
		}
		++small;	
	}	

}

int getLargestCarbon(const vector<Molecule> & hydrocarbons){
	// Declare variables
	int result = 0;
	// Loop through vector
	for (size_t i = 0; i < hydrocarbons.size(); ++i){
		// If this element has the largest carbon
		if (hydrocarbons[i].numOfC > result){
			// Return that number
			result = hydrocarbons[i].numOfC;
		}
		
	}
	return result;
}

int getSmallestCarbon(const vector<Molecule> & hydrocarbons){
	// Declare variables
	int result = hydrocarbons[0].numOfC;
	// Loop through vector
	for (size_t i = 0; i < hydrocarbons.size(); ++i){
		// If element has the largest hydrogen
		if (hydrocarbons[i].numOfC < result){
			// Return that number
			result = hydrocarbons[i].numOfC;
		}
		
	}
	return result;
}