//takes in a doc and flips the lines in that doc and displays it in the terminal

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void flipLines(ifstream & file);

int main(){
	ifstream infile("lab3part3_output.txt");
	flipLines(infile);
	return 0;
}

void flipLines(ifstream & file){
	string lineFromFile = "";
	vector<string> lines;
	while (getline(file, lineFromFile)){
		lines.push_back(lineFromFile);
	}
	for (int size = lines.size(); size >=0; --size){
		cout << lines[size] << endl;
		}
	}