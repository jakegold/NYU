// Jake Goldstein HW 04B Programming questions 1-2
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <set>
#include <unordered_set>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace std;


class trainStopData{
public:
	explicit trainStopData(string stop_id, string stop_name, double stop_lat, double stop_lon)
	 : stop_id(stop_id), stop_name(stop_name), stop_lat(stop_lat), stop_lon(stop_lon){}
	string get_id() const{ return stop_id; }
	string get_stop_name() const { return stop_name; }
	double get_latitude() const { return stop_lat; }
	double get_longitude() const { return stop_lon; }
private:
	string stop_id; // id of train stop (1st token)
	string stop_name; // name of station (4th token)
	double stop_lat; // latitude of train stop location
	double stop_lon; // longitude of train stop location
};

// Opens the file
void openFile(ifstream & file){
	// Open the file
	file.open("MTA_train_stop_data.txt");
	// Print an error if the file cannot open
	if(!file){
		cerr << "File cannot be opened" << endl;
		exit(1);
	}
}

// Fills a vector of TrainStopData from a file
void fillVector(ifstream& file, string& line, vector<trainStopData>& trains){
	while(getline(file, line)){
		string temp, stopID, stopName;
		double stopLat, stopLon;
		// After the 5th element in the line, the data is garbage
		for (int i = 0; i < 6; ++i){
			// Find the location of the next ','
			int location = line.find(',');
			// Create a substring until the ','
			string smallerString = line.substr(0,location);
			// Chop off that part of the string for the next iteration
			line = line.substr(location+1,line.size());
			// The first index of the file
			if (i == 0){
				stopID = smallerString;
			}
			// Second index of file (the third is garbage)
			else if(i == 2){
				stopName = smallerString;
			}
			// The 4th index of the file
			else if(i == 4){
				stopLat = stod(smallerString); 
			}
			// The last index of the file
			else if(i == 5){
				stopLon = stod(smallerString);
				// Create a trainStopData with relvent info and add it to vector
				trainStopData myTSD(stopID, stopName, stopLat, stopLon);
				trains.push_back(myTSD);
			}
		}
	}
}

// Was used for debugging, displays all elements in the vector of trainStopData
void display(const vector<trainStopData>& trains){
	for (int i = 0; i < trains.size(); ++i){
		cout << "id: " << trains[i].get_id() << " stop_name: " << trains[i].get_stop_name();
		cout << " latitude " << trains[i].get_latitude() << " longitude " << trains[i].get_longitude() << endl;
	}
}

// Question 1
void parseTrainData(vector<trainStopData>& vecData){
	// Open the file
	ifstream infile;
	openFile(infile);
	string line;
	// Get the first garbge line from the file
	getline(infile, line);
	// Fill the vector
	fillVector(infile, line, vecData);
	// display(vecData);
	// Close file
	infile.close();
}

// Question 2
template <class Object>
bool dupTestList(const vector<Object>& vec){
	bool result = false;
	// Create a list using the vector
	list<Object> myList(vec.begin(), vec.end());
	// Loop through each element
	for (auto iterFirst = myList.begin(); iterFirst != myList.end(); ++iterFirst){
		auto iterSecond = iterFirst;
		// And through the rest of the vector after that element
		for (++iterSecond; iterSecond != myList.end(); ++iterSecond){
			// If any item is the same
			if (*iterFirst == *iterSecond){
				result = true;
				break;
			}
		}
	}
	return result;
}

template <class Object>
bool dupTestSort(const vector<Object>& vec){
	bool result = false;
	// Sort the vector
	vector<Object> sorted = vec;
	sort(sorted.begin(), sorted.end());
	auto first = sorted.begin();
	auto last = sorted.end();
	// Loop thorugh all elements of the vector
	for (auto i = first; i != last; ++i){
		// If the count of any given element is bigger than 1
		if (count(first, last, *i) > 1){
			result = true;
			break;
		}	
	}
	return result;
}

template <class Object>
bool dupTestSet(const vector<Object>& vec){
	bool result = false;
	// Create a set from the vector
	set<Object> mySet(vec.begin(), vec.end());
	// Sets have no duplicates so check size, if smaller than there was a duplicate
	if (vec.size() != mySet.size()){
		result = true;
	}
	return result;
}

template <class Object>
bool dupTestUnorderedSet(const vector<Object>& vec){
	bool result = false;
	// Create an unorderedset from the vector
	unordered_set<Object> myUnorderedSet(vec.begin(), vec.end());
	// Unorderedsets have no duplicates so check size, if smaller than there was a duplicate
	if (vec.size() != myUnorderedSet.size()){
		result = true;
	}
	return result;
}


SCENARIO("Testing vector<trainStopData>") {
	GIVEN("A vector with trainStopData") {
		vector<trainStopData> test;
		parseTrainData(test);
		WHEN("Checking the size") {
			int size = test.size();
			THEN("The size should be 1482") {
				REQUIRE(size == 1482); //testing if the vector contains all the data
			}
		}
		WHEN("Getting stop_id") {
			string id = test[100].get_id(); //test a random data
			THEN("A valid id should be not nothing") {
				REQUIRE(id != "");
			}
		}
		WHEN("Getting stop_name") {
			string name = test[1000].get_stop_name(); //test a random data
			THEN("A valid name should be not nothing") {
				REQUIRE(name != "");
			}
		}
		WHEN("Getting latitude") {
			double lat = test[10].get_latitude(); //test a random data
			THEN("A valid latitude should be not nothing") {
				REQUIRE(lat != 0);
			}
		}
		WHEN("Getting longitude") {
			double lon = test[10].get_longitude(); //test a random data
			THEN("A valid longitude should be not nothing") {
				REQUIRE(lon != 0);
			}
		}
	}
}


SCENARIO("Testing check if there is duplicates") {
	GIVEN("A vector of int with no duplicates") {
		vector<int> intvec;
		intvec.push_back(1);
		intvec.push_back(2);
		intvec.push_back(3);
		WHEN("Checking duplicates with list") {
			bool isDup = dupTestList(intvec);
			THEN("It should return false") {
				REQUIRE(isDup == false); 
			}
		}
		WHEN("Checking duplicates with sort+vec") {
			bool isDup = dupTestSort(intvec);
			THEN("It should return false") {
				REQUIRE(isDup == false);
			}
		}
		WHEN("Checking duplicates with set") {
			bool isDup = dupTestSet(intvec);
			THEN("It should return false") {
				REQUIRE(isDup == false);
			}
		}
		WHEN("Checking duplicates with unordered set") {
			bool isDup = dupTestUnorderedSet(intvec);
			THEN("It should return false") {
				REQUIRE(isDup == false);
			}
		}
	}
	GIVEN("A vector of char with duplicates") {
		vector<char> charvec;
		charvec.push_back('a');
		charvec.push_back('c');
		charvec.push_back('a');
		WHEN("Checking duplicates with list") {
			bool isDup = dupTestList(charvec);
			THEN("It should return true") {
				REQUIRE(isDup == true);
			}
		}
		WHEN("Checking duplicates with sort+vec") {
			bool isDup = dupTestSort(charvec);
			THEN("It should return true") {
				REQUIRE(isDup == true);
			}
		}
		WHEN("Checking duplicates with set") {
			bool isDup = dupTestSet(charvec);
			THEN("It should return true") {
				REQUIRE(isDup == true);
			}
		}
		WHEN("Checking duplicates with unordered set") {
			bool isDup = dupTestUnorderedSet(charvec);
			THEN("It should return true") {
				REQUIRE(isDup == true);
			}
		}
	}
	GIVEN("An empty vector of string") {
		vector<string> svec;
		WHEN("Checking duplicates with list") {
			bool isDup = dupTestList(svec);
			THEN("It should return false") {
				REQUIRE(isDup == false);
			}
		}
		WHEN("Checking duplicates with sort+vec") {
			bool isDup = dupTestSort(svec);
			THEN("It should return false") {
				REQUIRE(isDup == false);
			}
		}
		WHEN("Checking duplicates with set") {
			bool isDup = dupTestSet(svec);
			THEN("It should return false") {
				REQUIRE(isDup == false);
			}
		}
		WHEN("Checking duplicates with unordered set") {
			bool isDup = dupTestUnorderedSet(svec);
			THEN("It should return false") {
				REQUIRE(isDup == false);
			}
		}
	}
}