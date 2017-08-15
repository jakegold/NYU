// Jake Goldstein HW 05 Programming questions 1-2
#define USE MATH DEFINES.
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <functional>
#include <math.h>

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
void openFile(ifstream & file);

// Fills a vector of TrainStopData from a file
void fillVector(ifstream& file, string& line, vector<trainStopData>& trains);

// Was used for debugging, displays all elements in the vector of trainStopData
void display(const vector<trainStopData>& trains);

// Question 1
void parseTrainData(vector<trainStopData>& vecData);

bool add(vector<trainStopData>& trains, const trainStopData& element);

void questionTwo(const vector<trainStopData>& trains, vector<trainStopData>::iterator first, vector<trainStopData>::iterator last);

// Functions from Haversine.txt
double degrad(double d);
double haverdist(double lat1, double longit1, double lat2, double longit2);

template <class iter, class object, class thing>
int perform_if(iter itrStart, iter itrEnd, object pred, thing op);

// Question 2
// First functor
class isStopOnRoute{
public:
	isStopOnRoute(char route) : route(route){}
	bool operator()(const trainStopData& myTrain) const {
		char compare = myTrain.get_id().at(0);
		return (compare == route) ? true : false;
	}
private:
	char route;
};

// Second functor
class isSubwayStop{
public:
	isSubwayStop(string stopID) : stopID(stopID){}
	bool operator()(const trainStopData& myTrain) const{
		return (myTrain.get_id() == stopID) ? true : false;
	}
private:
	string stopID;
};

// Third Functor
class isSubwayStopNearX{
public:
	isSubwayStopNearX(double longitude, double latitude, double d) : longitude(longitude), latitude(latitude), d(d){}
	bool operator()(const trainStopData& myTrain) const {
		double myDist = haverdist(latitude, longitude, myTrain.get_latitude(), myTrain.get_longitude());
		return (myDist > d) ? false : true;
	}
private:
	double longitude;
	double latitude;
	double d;
};

// Fourth Functor
class printTrainStopInfo{
public:
	void operator()(const trainStopData& myTrain) const {
		cout << "id: " << myTrain.get_id() << " stop_name: " << myTrain.get_stop_name();
		cout << " latitude " << myTrain.get_latitude() << " longitude " << myTrain.get_longitude() << endl;
	}
};


int main(){
	vector<trainStopData> vecData;
	parseTrainData(vecData);
	vector<trainStopData>::iterator first = vecData.begin();
	vector<trainStopData>::iterator last = vecData.end();
	questionTwo(vecData, first, last);
	return 42;
}

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
				add(trains, myTSD);
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

// The important part of question one
bool add(vector<trainStopData>& trains, const trainStopData& element){
	bool result = true;
	for (int i = trains.size()-1; i > -1; --i){
		if (trains[i].get_longitude() == element.get_longitude()){
			return false;
			break;
		}
	}
	if (result){
		trains.push_back(element);
	}
	return result;
}

// Functions from Haversine.txt
double degrad(double d){
   return d * M_PI / 180;
}

double haverdist(double lat1, double longit1, double lat2, double longit2){
     double r = 6371;
     double dlat = degrad(lat2 - lat1);
     double dlongit = degrad(longit2 - longit1);
     double a = sin(dlat/2)*sin(dlat/2)+
        cos(degrad(lat1))*cos(degrad(lat2))*sin(dlongit/2)*sin(dlongit/2);
     double c = 2*atan2(sqrt(a),sqrt(1-a));
     return r*c;
}

// Question 2
template <class iter, class object, class thing>
int perform_if(iter itrStart, iter itrEnd, object pred, thing op){
	auto itr = itrStart;
	int how_many = 0;
	for (itr; itr != itrEnd; ++itr){
		if (pred(*itr)){
			op(*itr);
			how_many++;
		}
	}
	return how_many;
}


void questionTwo(const vector<trainStopData>& trains, vector<trainStopData>::iterator first, vector<trainStopData>::iterator last){
	while(true){
		string command;
		cout << "Please insert a command of either: 'Routes', 'Stops', 'Dist', or 'Quit'. " << endl;
		cin >> command;
		if (command == "Quit"){
			break;
		}
		else if (command == "Routes"){
			cout << "OK, Please enter a route." << endl;
			char route;
			cin >> route;
			int counter = perform_if(first, last, isStopOnRoute(route), printTrainStopInfo());
			if (counter == 0){
				cout << "No stops on that route" << endl;
			}
		}
		else if (command == "Stops"){
			cout << "OK, Please enter a stop." << endl;
			cin >> command;
			int counter = perform_if(first, last, isSubwayStop(command), printTrainStopInfo());
			if (counter == 0){
				cout << "No stops by that ID" << endl;
			}
		}
		else if (command == "Dist"){
			cout << "OK, Please enter a latitude." << endl;
			double lat;
			double longi;
			double dist;
			cin >> lat;
			cout << "And now a longitude." << endl;
			cin >> longi;
			cout << "And now a distance from those coordinates." << endl;
			cin >> dist;
			int counter = perform_if(first, last, isSubwayStopNearX(longi, lat, dist), printTrainStopInfo());
			if (counter == 0){
				cout << "No stops on that route" << endl;
			}
		}
		else{
			cout << "I'm sorry, I didn't get that. Please try again." << endl;
		}
	}
}
