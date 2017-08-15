/* 
Jake Goldstein 
CS_1124 09/21/15
This code will take a file that is a list of warriors
and some instructions about those warriors.
It will run those instructions, even if it means some warriors must die.
HW01
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

// Define Warrior
struct Warrior{
	string name;
	int strength;
};

// Opens the file and returns an error if the file isn't opened
void openFile(ifstream & file);

// This will run all of the commands from the file
void runCommands (ifstream & file);

// This will make a warrior, and add it to the vector of warriors
void makeMeAWarrior(ifstream & file, vector<Warrior> & myWarriors);

// This will fight two warriors against eachother
void fight(ifstream & file, vector<Warrior> & myWarriors);

// This will find me the two warriors who are in a battle
int getIndex(string & name, const vector<Warrior> & soilders, ifstream & file);

// This will get the name of the warrior from file (to be used in BattlerIndex)
void getTheirName(ifstream & file, string & warriorName);

// This will test to see who wins the battle and adjust their strength
void theBattle(vector<Warrior> & soilders, int hero1, int hero2);

// The winner is passed first, changes status if winner and loser
void winner(Warrior & winner, Warrior & loser);

// Checks to see if a warrior is dead
bool isHeDead(int power);

// If there is a tie change status
void tie(Warrior & winner, Warrior & loser);

// This will print the status of all Warriors
void status(const vector<Warrior> & myWarriors);


int main(){
	// Declare variables
	ifstream infile;
	vector<Warrior> fighters;
	string command;
	// Open the file
	openFile(infile);
	// Run Functions
	runCommands(infile);
	// Close file
	infile.close();
	return 0; 
}

void openFile(ifstream & file){
	// Open the file
	file.open("warriors.txt");
	// Print an error if the file cannot open
	if(!file){
		cerr << "File cannot be opened" << endl;
		exit(1);
	}
}

void runCommands (ifstream & file){
	// Declare variables
	vector<Warrior> fighters;
	string command;
	// Get my command from the file
	while (file >> command){
		// If the command is warrior, make a new warrior
		if (command == "Warrior"){
			makeMeAWarrior(file, fighters);
		}
		// If the command is battle, then battle the warriors
		else if (command == "Battle"){
			fight(file, fighters);
		}
		// if the command is status present the status of everyone
		else {
			status(fighters);
		}
	}
}

void makeMeAWarrior(ifstream & file, vector<Warrior> & myWarriors){
	// Declare variables
	Warrior newWarrior;
	string name;
	int strength;
	// Get details from file
	file >> name;
	file >> strength;
	// Give the new Warrior these details
	newWarrior.name = name;
	newWarrior.strength = strength;
	// Add the Warrior to a vector of Warriors
	myWarriors.push_back(newWarrior);
}

void fight(ifstream & file, vector<Warrior> & myWarriors){
	// Declare variables
	string attackerName, defenderName;
	int attackerIndex, defenderIndex;
	Warrior attacker, defender;
	// Get the index of each Warrior from vector by using their names
	attackerIndex = getIndex(attackerName, myWarriors, file);
	defenderIndex = getIndex(defenderName, myWarriors, file);
	
	/* Declare new variables for convenience, 
	note that they are not nesaccary,
	but they make code easier to read
	*/
	attacker = myWarriors[attackerIndex];
	defender = myWarriors[defenderIndex];

	cout << attacker.name << " battles " << defender.name << endl;
	// Battle the two warriors against eachother
	theBattle(myWarriors, attackerIndex, defenderIndex);
}	

int getIndex(string & name, const vector<Warrior> & soilders, ifstream & file){
	// Get the names of the Warriors from file
	getTheirName(file, name);
	// Loop through vector to find warrior
	for (size_t index = 0; index <= soilders.size(); ++index){
		// If the warrior is found
		if (soilders[index].name == name){
			// Return their index
			return index;
		}
	}
	// If it doesn't work:
	return -1;
}

void getTheirName(ifstream & file, string & warriorName){
	// Get warrior's name from file
	file >> warriorName;
}

void theBattle(vector<Warrior> & soilders, int hero1, int hero2){
	// If the first warrior wins
	if (soilders[hero1].strength > soilders[hero2].strength){
		winner(soilders[hero1], soilders[hero2]);	
	}
	// If second warrior wins
	else if (soilders[hero1].strength < soilders[hero2].strength){
		winner(soilders[hero2], soilders[hero1]);
	}
	// If there is a tie
	else {
		tie(soilders[hero1], soilders[hero2]);	
	}
}

void winner(Warrior & winner, Warrior & loser){
	// If the loser is already dead
	if (isHeDead(loser.strength)){
		cout << "He's dead, " << winner.name << endl;
	}
	else {
		cout << winner.name << " defeats ";
		cout << loser.name << endl;
	}
	// Adjust stengths
	winner.strength -= loser.strength;
	loser.strength = 0;
}

bool isHeDead(int power){
	// If someone is dead
	if (power == 0){
		return true;
	}
	// If they are not dead
	else {
		return false; 
	}
}

void tie(Warrior & contenderOne, Warrior & contenderTwo){
	// If both contenders are dead
	if (isHeDead(contenderOne.strength) && isHeDead(contenderTwo.strength)){
		cout << "Oh, NO! They're both dead! Yuck!" << endl;
	}
	else { 
		cout << "Mutual Annihilation: "; 
		cout << contenderOne.name << " and ";
		cout << contenderTwo.name;
		cout << " die at each other's hands" << endl;
		// Adjust stenghts
		contenderOne.strength = 0;
		contenderTwo.strength = 0;
	}
}

void status(const vector<Warrior> & myWarriors){
	// Display total number of warriors in vector
	cout << "There are: " << myWarriors.size() << " warriors" << endl;
	// Then loops through the vector putting out names and strengths
	for (size_t counter = 0; counter < myWarriors.size(); ++counter){
		Warrior placeHolder = myWarriors[counter];
		cout << "Warrior: " << placeHolder.name << ", ";
		cout << "Strength: " << placeHolder.strength << endl; 
	}
}