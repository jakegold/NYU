// Jake Goldstein HW11pq2

// Code from Lisa Hellerstein.
// This is a bare-bones implementation of the single-source unweighted
// shortest paths algorithm 
// It does not have nice classes.

// Assumption: The vertices of the graph are labeled from 0 to n - 1,
// where n is the number of vertices.
#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <fstream>

using namespace std;

const int DEFAULT_VAL =  -1;      // must be less than 0    //NOT SURE WHY I NEED THIS...

typedef unordered_map <string, list<string>> Graph;        // The graph is given in an adjacency list.   // CHANGED TO A MAP
// Vertices are indexed from 0 to V-1                       //DOES NOT APPLY ANYMORE
// The indices of the vertices adjacent to vertex i         //DOES NOT APPLY ANYMORE
// are in the list Graph[i].                                 //DOES NOT APPLY ANYMORE
// Graph can be directed or undirected.                      //DOES NOT APPLY ANYMORE

struct vertexInf{                    // Stores information for a vertex{                                   
    int dist;  // distance to vertex from the source
    string prev;  // previous node in BFS tree          //NOW A STRING
};



// Everything between these comments is taken from hw10pq2.cpp (some of it was modified)
bool add(const string& key){
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
        bool addKey = add(key);
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
    getline(infile, currLine);
    bool breakHere = false;
    while(true){
        // Create a list to store all the adjacent stops
        list<string> allAdjStops;
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
            breakHere = true;
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
        if (breakHere){
            break;
        }
        lastStop = currStop;
        currLine = nextFullLine;
    }
}

void fillMap(unordered_map <string, list<string>>& myMap){
    ifstream trains;
    // Open all the train stops file

    trains.open("MTA_train_stop_data.txt");
    // trains.open("someStops.txt");

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
    // transfers.open("someTrans.txt");

    if (!transfers){
        cerr << "transfers.txt cannot be opened" << endl;
        exit(1);
    }
    // Trash a garbage line
    getline(transfers, garbageLine);
    // Create all of the values for the map
    makeValues(transfers, myMap);
    transfers.close();
}
// Everything between these comments is taken from hw10pq2.cpp (some of it was modified)


void printpath(const string& start, const string& j, unordered_map <string, vertexInf> & vinfo){
    // Build a stack to store the output
    stack<string> t;
    // Get the final stop
    string current = j;
    // While the first stop is not the current stop and while it the first path connects to the final one
    while (current != start && vinfo[current].dist != DEFAULT_VAL){
        // Add that stop to the stack
        t.push(current);
        // Go to the previous stop
        current = vinfo[current].prev;
    }
    // Add the first stop
    t.push(start);
    // Empty the stack and print contents
    while (!t.empty()){
        cout << t.top() << " ";
        t.pop();
    }
}


// Breadth First Search
// The unweighted shortest path algorithm on the graph g, with vertex i as the source
// Prints the length (number of edges) of the shortest path from the source to every vertex
// in the graph

void shortestpaths(Graph & g, string & starter){
    // Create a queue to hold all stops that connect
    queue<string> waitList;
    // Test to see if the input is actually in the graph
    auto testStart = g.find(starter);
    if (testStart == g.end()){
        cout << "Bad index" << endl;
        return;
    }
    // Stores all of the shortest paths
    unordered_map <string, vertexInf> shortestPaths;              
    // Initialize distances and prev values
    vertexInf temp;
    temp.dist = DEFAULT_VAL;
    temp.prev = "";
    for (auto i = g.begin(); i != g.end(); ++i){ 
        shortestPaths[i->first] = temp;        
    }   
    shortestPaths[starter].dist = 0;
    waitList.push(starter);
    // Get all of the shortest paths (Breadth First Search)
    while (!waitList.empty()){
        string frontOfQueue = waitList.front();
        waitList.pop();
        list<string> allStops = g[frontOfQueue];
        // Loop through the adjacnecy list
        for (auto w = allStops.begin(); w != allStops.end(); w++){ 
            // If that vertex has not yet been seen
            if (shortestPaths[*w].dist == DEFAULT_VAL){          // distance of *w from source not determined yet
                shortestPaths[*w].dist = shortestPaths[frontOfQueue].dist+1;
                shortestPaths[*w].prev = frontOfQueue;
                waitList.push(*w);
            }
        }
    }
    // Print out all of the shortest paths
    for (unordered_map <string, vertexInf>::iterator j = shortestPaths.begin(); j != shortestPaths.end(); j++){        // print distances from source and paths
        cout << "vertex " << j->first << endl;
        cout << "distance: " << j->second.dist << endl;
        cout << "shortest path: "; 
        printpath(starter, j->first, shortestPaths); 
        cout << endl;
        cout << endl;
    } 
}



int main(){ 
    Graph myGraph;
    // Fill the map
    fillMap(myGraph);

    // // Two tests
    // cout << "R16:" << endl;
    string startFrom = "R16";
    // shortestpaths(myGraph, startFrom);

    // (second test)
    cout << "111:" << endl;
    startFrom = "111";
    shortestpaths(myGraph, startFrom);

    return 42;

}
