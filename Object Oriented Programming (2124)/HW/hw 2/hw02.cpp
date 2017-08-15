/* 
Jake Goldstein 
CS_1124 10/02/15
This code will take a file that is a list of warriors and their weapons
and some instructions about those warriors.
It will run those instructions, even if it means some warriors must die.
HW02
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

// Weapon Class
class Weapon{
public:
	// Constructor
	Weapon(const string & name, int stren) : wpName(name), wpStrength(stren){}
	// Returns the Weapon's name
	string getWeaponName() const {
		return wpName;
	}
	// Returns the Weapon's strength
	int getWeaponStrength() const {
		return wpStrength;
	}
	// Sets the strength to the int passed
	void setStrength(int newStrength){
		wpStrength = newStrength;
	}

private:
	// Variables of Weapon
	string wpName;
	int wpStrength;
};

// Warrior Class
class Warrior{
public:
	// Constructor
	Warrior(const string & name, const Weapon & wp) : wrName(name), wrWp(wp){}
	// Returns the Warrior's name
	string getWarriorName() const{
		return wrName;
	}
	// Returns the Warrior's Weapon's name
	string getWeaponName() const{
		return wrWp.getWeaponName();
	}
	// Returns the Warrior's Weapon's strength
	int getWeaponStrength() const{
		return wrWp.getWeaponStrength();
	}
	// Change Weapon's strength
	void setWeaponStrength(int newStrength){
		wrWp.setStrength(newStrength);
	}
	// A battle where the challenger has a weaker weapon
	void battle(Warrior & challenger){
		// If the challenger is dead
		if (challenger.isDead()){
			cout << "He's dead, " << getWarriorName() << endl;
			return;
		}
		// Else
		cout << getWarriorName() << " deafeats ";
		cout << challenger.getWarriorName() << endl;
		// Declare variables
		int loserStren = challenger.getWeaponStrength();
		// Adjust strengths
		wrWp.setStrength(wrWp.getWeaponStrength() - loserStren);
		challenger.setWeaponStrength(0);
	}
	// A battle where the weapons are of equal strengths
	void tie(Warrior & challenger){
		// If both warriors are dead
		if(isDead() && challenger.isDead()){
			cout << "Oh, NO! They're both dead! Yuck!" << endl;
			return;
		}
		else{
			cout << "Mutual Annihilation: " << getWarriorName() << " and ";
			cout << challenger.getWarriorName();
			cout << " die at each other's hands" << endl;
		}
		// Adjust strengths
		wrWp.setStrength(0);
		challenger.setWeaponStrength(0);
	}
	// Tests to see if a warrior is dead, returns true if dead
	bool isDead() const{
		// Declare variables
		int death = getWeaponStrength();
		// Test for death
		if (death == 0){
			return true;
		}
		// Else
		return false;
	}
	// Displays the Warrior
	void displayWarrior() const {
		cout << "Warrior " << wrName << ", weapon: ";
		cout << wrWp.getWeaponName() << ", ";
		cout << wrWp.getWeaponStrength() << endl;
	}
private:
	// Variables of Warrior
	string wrName;
	Weapon wrWp;
};
// Opens a file and puts out an error if the file can't open
void openFile(ifstream & file);
// Reads the file 
void readFile(ifstream & file);
// Makes a warrior from file and puts it into a vector of warriors
void makeWarrior(ifstream & file, vector<Warrior> & myWarriors);
// Has two warriors fight from file
void fight(ifstream & file, vector<Warrior> & myWarriors);
// Sets up a battle between Warriors
void battlePrep(int attIndex, int defIndex, vector<Warrior> & myWarriors);
// Gets the index of a warrior from vector 
size_t getIndex(const string & name, const vector<Warrior> & myWarriors);
// Prints the Status of all Warriors
void status(const vector<Warrior> & myWarriors);

int main(){
	// Declare variables
	ifstream infile;
	// Run functions
	openFile(infile);
	readFile(infile);
	// Close file
	infile.close();
	return 0;
}

void openFile(ifstream & file){
	// Open the file
	file.open("warriors_2.txt");
	// Print an error if the file cannot open
	if(!file){
		cerr << "File cannot be opened" << endl;
		exit(1);
	}
}

void readFile(ifstream & file){
	// Declare variables
	string command;
	vector<Warrior> fighters;
	// Get a command from the file
	while(file >> command){
		// If the command is make a new warrior
		if(command == "Warrior"){
			// Make a new warrior
			makeWarrior(file, fighters);
		}
		// If the command is battle two warriors
		else if(command == "Battle"){
			// Battle two warriors
			fight(file, fighters);
		}
		// If the command is status
		else {
			status(fighters);
		}
	}
}

void makeWarrior(ifstream & file, vector<Warrior> & myWarriors){
	// Declare variables
	string warriorName, weaponName;
	int weaponStrength;
	// Get information from file
	file >> warriorName >> weaponName >> weaponStrength;
	// Assign information to weapon and warrior
	Weapon newWeapon(weaponName, weaponStrength);
	Warrior newWarrior(warriorName, newWeapon);
	// Add new warrior to vector
	myWarriors.push_back(newWarrior);
}

void fight(ifstream & file, vector<Warrior> & myWarriors){
	// Declare variables
	string attacker, defender;
	// Get who is fighting from file
	file >> attacker >> defender;
	// Display who is fighting
	cout << attacker << " battles " << defender << endl;
	// Get index of both warriors
	int attackerIndex = getIndex(attacker, myWarriors);
	int defenderIndex = getIndex(defender, myWarriors);
	// Send the warriors to battle
	battlePrep(attackerIndex, defenderIndex, myWarriors);
}

void battlePrep(int attIndex, int defIndex, vector<Warrior> & myWarriors){
	// Get weapon strength for both warriors
	int attackerWepStren = myWarriors[attIndex].getWeaponStrength();
	int defenderWepStren = myWarriors[defIndex].getWeaponStrength();
	// If the attacker is stronger than defender
	if (attackerWepStren > defenderWepStren){
		myWarriors[attIndex].battle(myWarriors[defIndex]);
	}
	// If the defender is stronger than attacker
	else if (defenderWepStren > attackerWepStren){
		myWarriors[defIndex].battle(myWarriors[attIndex]);
	}
	// If they are even
	else{
		myWarriors[attIndex].tie(myWarriors[defIndex]);
	}
}

size_t getIndex(const string & name, const vector<Warrior> & myWarriors){
	// Loop through vector of Warriors
	for (size_t i = 0; i < myWarriors.size(); ++i){
		// If a warrior has the name that is being looked for
		if (myWarriors[i].getWarriorName() == name)
		{
			// Return his index
			return i;
		}
	}
	// Else return a value that cannot exist from vector
	return -1;
}

void status(const vector<Warrior> & myWarriors){
	// Display total number of warriors in vector
	cout << "There are: " << myWarriors.size() << " warriors" << endl;
	// Then loops through the vector putting out names and strengths
	for (size_t counter = 0; counter < myWarriors.size(); ++counter){
		Warrior placeHolder = myWarriors[counter];
		placeHolder.displayWarrior();
	}
}