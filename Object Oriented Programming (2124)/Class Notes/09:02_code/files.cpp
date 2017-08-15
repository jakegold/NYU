// files 
// note need to run eacg of the whiles differently to get resutls...
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
	string s;
	char c;
	ifstream file("nameOfFile.txt.rtf"); //this will open if the file is there
	if (!file) {
		cerr << "failed to open nameOfFile" << endl; 
		//do this to let u know if ur file exits or if your being a fool
		exit(1);
		//exits program or file not sure (and needs a small pos. number)
	}
	file >> s; //s is holding the next token from the stream every time
	//cout << s << endl;

	/*while (file >> s){//so this is holding it for EVERY token
		cout << s << endl; // this should put out the whole file
		for (int i = 0; i < s.size(); ++i){
			cout << s[i] << ' ';
// so this loop would print out every charachter in a string wiht a space..
..just showing we can accses these charachters
		}
	}
*/
/*	
	while (getline(file,s)){//so now its not just a token..its a whole line
		cout << s << endl;
	}
*/
	while (file >> c){
	//now its not a line or a string...its by chars..but in one word! 
		it doesnt get white spaces..such as spaces
		cout << c << endl;
	}
/*note not all of these are going to run 
its going to stop after the first loop
in order to run another all of these you would need to either
re-open the file or comment out something
*/
}

