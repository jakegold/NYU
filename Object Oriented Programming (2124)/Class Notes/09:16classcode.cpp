#include <iostream>
#include <fstream>
#include <vector>
#include <string>
//not sure what this next one is for:
#include <cstdlib>

using namespace std;

/* note I missed a class on the 13th
also note that this is prob the end to intro of this class
go over intro things maybe...write more code
also make sure that you use the correct parameter passings always
*/



/* we want to deal with words and tokens...if we have a file we want to analize it so 
that if we were asked a q on the file we would be able to answer it ealisly

note im going to need to bring in a file

so maybe we store every single word in a vector and then we would be able to accsess it
by making loops and so on...

another way to do it is make a collection of the word and all the places it came up..
so this is making a collection of objects where each object has a name 
and a collection of positions where the word came up

note there are faster ways to do this but were going to stick with this way
*/

//so each object has a token and a vector of positions
struct Word{
	string token;
	vector<int> positions;
};

//checks to see if a token is in a collection yet
size_t isTokenInCollection(const string & theWord, const vector<Word> & listOfWords){
	// loop through the vector of Words
	for (size_t index = 0; index < listOfWords.size(); ++index){
		// if it exists already, return only the string part of Word
		if (theWord == listOfWords[index].token) {
			return index;
		}
	// if it isnt, returns the size of the vector..where you cant have a word
	return listOfWords.size();
	}
}

// display all words
void displayWords(const vector<Word> & listOfWords){
	// loop thorugh all the vector making new words
	for (const Word & theWord : listOfWords){
		// returns the word itself
		cout << theWord.token << ": ";
		// loop through the vector of numbers and give all the numbers
		for (int thisNumber : theWord.positions){
			cout << ' ' << thisNumber;
		}
		cout << endl;
	}
}

void fixMyToken(string & theWord){
	for (int count = 0; count < theWord.length(); ++count){
		char checker = theWord[count];
		if (!isalpha(checker)){
			checker.erase(count, count+1);
			--count;
		}

	}
}

int main(){
	//bring in a file
	ifstream infile ("afile");
	// make sure the file workds
	if (!infile) {
		cerr << "could not open file!" << endl;
		exit(1);
	}
	
	//start up my vector of the objects
	vector<Word> allOfTheWords;
	int location = 0;
	// loop through my file for words
	string theToken;
	while (infile >> theToken){
		//this will make the token nicer
		fixMyToken(theToken);
		// check to see if the word exists
		size_t foundIndex = isTokenInCollection(theToken, allOfTheWords);
		// if it does...
		if (foundIndex < allOfTheWords.size()){
			// put this new position into the vector of ints of my position in the struct Word
			// which already existed...a new position in a pre-exisiting word
			allOfTheWords[foundIndex].positions.push_back(location);
		}
		// if it doesnt exist already
		else {
			// make a new word
			Word wordToAdd;
			// assign the new word part
			wordToAdd.token = theToken;
			// assign the new position part to the word itself
			wordToAdd.positions.push_back(location);
			// assign the new wordtoadd to the vector of all pre-existing words
			allOfTheWords.push_back(wordToAdd);
		}
		++location;
	}
	infile.close();

	displayWords(allOfTheWords);

	return 0;
}















