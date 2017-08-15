// Jake Goldstein Programming Q2
#define CATCH_CONFIG_MAIN
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <list>
#include <vector>
#include "catch.hpp"
using namespace std;

bool add(const unordered_map <string, list<string>>& myMap, const string& key){
	// Test to see if the stop is a double
	char tester = key.at(key.size()-1);
	if (tester == 'N' || tester == 'S'){
		return false;
	}
	return true;
}

void makeKeys(ifstream& infile, unordered_map <string, list<string>>& myMap){
	string key;
	while(getline(infile, key)){
		// Get the important information about the stop
		int comma = key.find(',');
		key = key.substr(0,comma);
		bool addKey = add(myMap, key);
		// If the key is not already in the map, add it
		if(addKey){
			myMap[key];
		}
	}
}

string getTransfer(const string& trainStop){
	// Parse string until stop name
	int comma = trainStop.find(',');
	string result = trainStop.substr(comma + 1, trainStop.size()-1);
	// Parse again for transfer name
	comma = result.find(',');
	result = result.substr(0, comma);
	return result;
}

string getStop(const string& trainStop){
	// Parse string for stop name
	int comma = trainStop.find(',');
	string result = trainStop.substr(0, comma);
	return result;
}

void makeValues(ifstream& infile, unordered_map <string, list<string>>& myMap){
	// Create strings for the current, next and previous stop
	string currLine;
	string lastStop = "";
	string nextFullLine;
	// Create a list to store all the adjacent stops
	list<string> allAdjStops;

	getline(infile, currLine);
	while(true){
		// Get the current stop and the transfer with it
		string currTransfer = getTransfer(currLine);
		string currStop = getStop(currLine);
		// If there is a transfer, add it to all the transfers
		if (currTransfer != currStop){
			allAdjStops.push_back(currTransfer);
		}
		// Get the next stop
		getline(infile, nextFullLine);
		// If it is the end of the file, break
		if (nextFullLine == currLine){
			break;
		}
		// Else get the stop and add it
		else{
			string nextStop = getStop(nextFullLine);
			allAdjStops.push_back(nextStop);
		}
		// If it is not the first time through the loop, add the previous stop
		if (lastStop != ""){
			allAdjStops.push_back(lastStop);
		}
		// Set the stops as the value for their key
		myMap[currStop] = allAdjStops;
		lastStop = currStop;
		currLine = nextFullLine;
	}
}

void fillMap(unordered_map <string, list<string>>& myMap){
	ifstream trains;
	// Open all the train stops file
	trains.open("MTA_train_stop_data.txt");
	if (!trains){
		cerr << "MTA_train_stop_data.txt cannot be opened" << endl;
		exit(1);
	}
	// Trash a garbage line
	string garbageLine;
	getline(trains, garbageLine);
	// Create all of the keys for the map
	makeKeys(trains, myMap);
	trains.close();
	ifstream transfers;
	// Open all the transfers file
	transfers.open("transfers.txt");
	if (!transfers){
		cerr << "transfers.txt cannot be opened" << endl;
		exit(1);
	}
	// Trash a garbage line
	getline(transfers, garbageLine);
	// Create all of the values for the map
	makeValues(transfers, myMap);
}




SCENARIO("Checking for adjacency") {
	GIVEN("Some subways with adjacency are tested") {
		unordered_map < string, list<string>> adjList;
		WHEN("The container has been populated") {

			
			/*
			//INSERT FUNCTIONS THAT POPULATE THE UNORDERED MAP HERE
			*/
			fillMap(adjList);


			//checking if stop 125 is there
			unordered_map < string, list<string>> ::iterator adjListItr = adjList.find("125");
			THEN("125 is a stop in the container ") {
				//make sure find returns a true
				REQUIRE(adjListItr != adjList.end());
			}
			THEN("The adjacency list of stop 125 is correctly stored") {
				//go through and check all of adjacency list of station 125 
				vector<string> adjVec;
				//putting all the adjacent stops in a vector so that the order in which they were inserted into the map doesn't matter
				for (list<string>::iterator litr = adjListItr->second.begin(); litr != adjListItr->second.end(); litr++) {
					adjVec.push_back(*litr);
				}

				//Checking to see if stops 124, A24, and 126 are there 
				bool stop124 = false;
				bool stopA24 = false;
				bool stop126 = false;
				for (int i = 0; i < adjVec.size(); i++) {
					if (adjVec[i] == "124") stop124 = true;
					else if (adjVec[i] == "A24") stopA24 = true;
					else if (adjVec[i] == "126") stop126 = true;
				}
				REQUIRE(stop124);
				REQUIRE(stopA24);
				REQUIRE(stop126);

			}

			//checking if stop B16 is there
			unordered_map < string, list<string>> ::iterator adjListItr2 = adjList.find("B16");
			THEN("B16 is a stop in the container ") {
				//make sure find returns a true
				REQUIRE(adjListItr2 != adjList.end());
			}
			THEN("The adjacency list of stop B16 is correctly stored") {
				//go through and check all of adjacency list of station 125 
				vector<string> adjVec;
				//putting all the adjacent stops in a vector so that the order in which they were inserted into the map doesn't matter
				for (list<string>::iterator litr = adjListItr2->second.begin(); litr != adjListItr2->second.end(); litr++) {
					adjVec.push_back(*litr);
				}

				//Checking to see if stops B15, N04 and B17 are there 
				bool stopB15 = false;
				bool stopN04 = false;
				bool stopB17 = false;
				for (int i = 0; i < adjVec.size(); i++) {
					if (adjVec[i] == "B15") stopB15 = true;
					else if (adjVec[i] == "N04") stopN04 = true;
					else if (adjVec[i] == "B17")stopB17 = true;
				}
				REQUIRE(stopB15);
				REQUIRE(stopN04);
				REQUIRE(stopB17);

			}
		}
	}
}
