// Jake Goldstein Programming Question 2
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;


// Get point values from the file and store them in the vector
void initValues (vector<int>& pointValues) {
    ifstream infile("Letter_point_value.txt");
    if (!infile){
      cerr << "Failure to open file" << endl;  
    }
    string line;
    while(getline(infile, line)){
        // The last letter of the line is letter, the first part is the interger value
        char letter = line[line.size()-1];
        string sValue;
        // If the integer value is a double digit
        if (line.substr(1,1) != " "){
            sValue = line.substr(0,2);
        }
        // If the value is only one digit
        else{
            sValue = line.substr(0,1);
        }
        int value = stoi(sValue);
        // Here it is -65 because the letters are upper case
        pointValues[letter - 65] = value;
    }
}

// Compute point value of a word
int wordValue (const vector<int>& pointValues, const string& word) {
    int result = 0;
    for (int i = 0; i < word.size(); ++i){
        char letter = word[i];
        // Here it is -97 because lower case
        result = result + pointValues[letter - 97];
    }
    return result;
}

// Store all words and their point values in the map
void initWords (const vector<int>& pointValues, map<string, int>& wordValues) {
    ifstream infile("ENABLE.txt");
    if (!infile){
      cerr << "Failure to open file" << endl;  
    }
    string line;
    while(getline(infile, line)){
        int value = wordValue(pointValues, line);
        wordValues[line] = value;
    }
}

SCENARIO("Testing words with friends"){
    GIVEN("Given a map and vector"){
        vector<int> pointValues(26,0); 
        map<string, int> wordValues;
        WHEN("The map is initialized with this vector with word values"){
            initValues(pointValues);
            initWords(pointValues, wordValues);  
            THEN("abacterial should be valued 17"){
                string test = "abacterial";
                map<string, int>::iterator itr = wordValues.find(test);
                REQUIRE(itr->second == 17);
            }
            THEN("zyzzyva should be valued 42"){
                 string test = "zyzzyva";
                 map<string, int>::iterator itr = wordValues.find(test);

                 cout << "if i crash i should not see this." << endl;

                 REQUIRE(itr->second == 42);
             }
             THEN("fuzees should be valued 19"){
                string test = "fuzees";
                map<string, int>::iterator itr = wordValues.find(test);
                REQUIRE(itr->second == 19);
             }
             THEN("poly should be valued 10"){
                string test = "poly";
                map<string, int>::iterator itr = wordValues.find(test);
                REQUIRE(itr->second == 10);
             }
        }
    }
}

