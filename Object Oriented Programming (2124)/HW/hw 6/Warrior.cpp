#include "Warrior.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace WarriorCraft{
	
	 // Constructor
	Warrior::Warrior(const string wNm, const double wStr)
	: name(wNm), strength(wStr), master(nullptr){}
	// Get Strength
    double Warrior::getStrength() const { return strength; }
    // Get Name of Warrior
    string Warrior::getWarriorName() const { return name; }
    // Set strength
    void Warrior::setStrength(double newStrength) { strength = newStrength; }
    // Runaway
    void Warrior::runaway(){
        // If the warrior has a Noble
    	if(master != nullptr){
    		master->run(this);
    		master = nullptr;
    	}
        // If the warrior has no noble
    	else {
    		cout << getWarriorName();
            cout << " has no Noble, he is already free." << endl;
    	}
    }
    // Sets the Noble pointer
    void Warrior::assign(Noble* myMaster) { master = myMaster; }
}