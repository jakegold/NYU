/* 
Jake Goldstein 
CS_1124 10/30/15
This code will take an input of protectors of all sorts,
different types of nobles and transactions
that the nobles are making about the protectors.
The nobles will then fight with eachother to the death,
using either protectors as bait, or have the audacity to fight themselves
HW05
*/
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

// Forward Decleration of lord class
class Lord;

// Abstract Class Protector (Wizard and Warrior inheret from here)
class Protector{
public:
    // Constructor (Note the intilization list is on the next line)
    Protector(const string & name, double strength)
    : name(name), strength(strength), master(nullptr), alive(true){}
    // Get strength
    double getStrength() const{ return strength; }
    // Set strength
    void setProtectorStrength(double newStrength){ strength = newStrength; }
    // Get Name of the protector
    string getProtectorName() const{ return name; } 
    // Get the protectors Lord (if hired)
    Lord* getLord() const{ return master; }
    // Set the protectors Lord (if hired)
    void setLord(Lord* const newMaster){ master = newMaster; }
    // Abstract method defend
    virtual void defend() const = 0;
    // Get the status of Protector
    bool isAlive() const { return alive; }
    // In the event a protector dies
    void kill(){ 
        // Set his strength to 0
        setProtectorStrength(0);
        // Change his status
        alive = false;
    }
private:
    string name;
    double strength;
    Lord* master;
    bool alive;
};

// Abstract Class Noble (Lord and PersonWithStrenghtToFight inheret from here)
class Noble{
public:
    // Constructor
    Noble(const string & name) : name(name), alive(true){}
    // Battle
    void battle(Noble & attacker){
        // Print out message
        cout << name << " battles " << attacker.name << endl;
        // Declare variables
        double attackerStren = attacker.getTotalStrength();
        double myStren = this->getTotalStrength();
        // If the attacker wins
        if(attackerStren > myStren){
            // If the loser is already dead then print out a message
            if(!alive){ cout << "He's dead, " << attacker.name << endl; }
            // If loser is alive
            else{
                // Have protectors make some noise
                makenoise();
                attacker.makenoise();
                // Set strenghts and adjust status
                setLoserStren();
                attacker.setWinnerStren(*this);
                alive = false;
                // Print out message
                cout << attacker.name << " defeats " << name << endl;
            }
        }
        // If the attacker loses
        else if(myStren > attackerStren){ 
            // If the loser is already dead then print out a message
            if(!attacker.alive){ cout << "He's dead, " << name << endl; }
            // If loser is alive
            else{
                // Have protectors make some noise
                makenoise();
                attacker.makenoise();
                // Set strenghts and adjust status
                attacker.setLoserStren();
                setWinnerStren(attacker);
                attacker.alive = false;
                // Print out message
                cout << name << " defeats " << attacker.name << endl;
            }
        }
        // If there is a tie
        else{ 
            // If they are both dead print out message
            if(!attacker.alive && !alive){
                cout << "Oh, NO!  They're both dead!  Yuck!" << endl;
            }
            // If they are both alive with same strength
            else{
                // Print messages
                cout << "Mutual Annihalation: " << name << " and ";
                cout << attacker.name << " die at each other's hands" << endl;
                // Adjust status
                alive = false;
                attacker.alive = false;
            }
        }
    }
    // Abstract method get strength
    virtual double getTotalStrength() const = 0;
    // Abstract method set the winners strength
    virtual void setWinnerStren(Noble & loser) = 0;
    // Abstract method set the losers strength
    virtual void setLoserStren() = 0;
    // Abstract method make noise
    virtual void makenoise() const = 0;
    // Get the Nolbe's name
    string getName() const { return name; }
    // Get the Noble's status
    bool amIAlive() const { return alive; }
    // Set the Noble's status
    void death(){ alive = false; }
private:
	string name;
    bool alive;
};

// Lord Class
class Lord : public Noble{
public:
    // Constructor
	Lord(const string & name) : Noble(name){}
    // Hire method
    void hires(Protector & fighter){
        // If the Lord is dead he can't hire anyone
        if(!amIAlive()){ return; }
        // If the fighter already has a lord he cant be stolen
        if(fighter.getLord() != nullptr){ return; }
        // Else
        // Add the fighter to Lord's army, and make the fighter point to Lord
        army.push_back(&fighter);
        fighter.setLord(this);
    }
    // Overwritten Get Total Strength
    virtual double getTotalStrength() const {
        // Declare varaibles
        double totStren = 0;
        // Loop through the army 
        for(size_t i = 0; i < army.size(); ++i){
            // Add up all of the protectors strengths
            totStren += army[i]->getStrength();
        }
        // Return total Strength
        return totStren;
    }
    // Overwritten Set Loser Stren
    virtual void setLoserStren(){
        // Loop through army killing all members
        for(size_t i = 0; i < army.size(); ++i){ army[i]->kill(); }
        // Adjust status
        death();
    }
    // Overwritten Set Winner Stren
    virtual void setWinnerStren(Noble & loser){
        // Declare Variable to subtract strength by
        double ratio = loser.getTotalStrength()/getTotalStrength();
        // Loop thorugh army
        for(size_t i = 0; i < army.size(); ++i){
            // Lower all of the warrior's health
            army[i]->setProtectorStrength(army[i]->getStrength() * (1-ratio));
            // Ensure no one has a health lower than zero, if they do kill them
            if (army[i]->getStrength() < 0){ army[i]->kill(); }
        }
    }
    // Overwritten Make Noise
    virtual void makenoise() const {
        // If the Noble is alive
        if(amIAlive()){
            // Loop through army
            for(size_t i = 0; i < army.size();++i){
                // If the army member is alive he defends himself
                if(army[i]->isAlive()){ army[i]->defend();}
            }
        }
    }
private:
    vector<Protector*> army;
};

// Person With Strength To Fight Class
class PersonWithStrengthToFight : public Noble{
public:
    // Constructor (Note the intilization list is on the next line)
	PersonWithStrengthToFight(const string & name, double strength)
    : Noble(name), strength(strength){}
    // Overwritten Get Total Strength 
    virtual double getTotalStrength() const { return strength; }
    // Overwriteen Set Winner Stren
    virtual void setWinnerStren(Noble & loser){
        // Declare Variable to subtract strength by
        double ratio = loser.getTotalStrength()/getTotalStrength();
        // Subtract strength by ratio
        strength *= (1-ratio);
        // Ensure strength is not lower than zero, if it is change status 
        if(strength < 0){ setLoserStren(); } 
    }
    // Overwriteen Set Loser Stren
    virtual void setLoserStren(){
        // Set strength to zero, if it is change status
        strength = 0;
        death();
    }
    // Overwritren Make Noise
    virtual void makenoise() const { return; }
private:
	double strength;
};

// Wizard Class
class Wizard : public Protector{
public:
    // Constructor
	Wizard(const string & name, double strength) : Protector(name, strength){}
    // Overwritten Defend which prints message
    virtual void defend() const { cout << "POOF!" << endl; }
};

// Warrior Class (Archer and Swardsman inherit from here)
class Warrior : public Protector{
public:
    // Constructor
	Warrior(const string & name, double strength) : Protector(name, strength){}
    // Overwritten Defend
    virtual void defend() const {
        // Get Masters name from adress
        Lord* master = getLord();
        string masterName = master->getName();
        // Print message
        cout << getProtectorName() << " says: Take that in the name of my lord, " << masterName << endl;
    }
};

// Archer Class
class Archer : public Warrior{
public:
    // Constructor
	Archer(const string & name, double strength) : Warrior(name, strength){}
    // Overwritten Defend class
    virtual void defend() const{
        // Print out message
        cout << "TWANG!  ";
        // Call Warrior's defend
        Warrior::defend();
    }
};

// Swordsman Class
class Swordsman : public Warrior{
public:
    // Constructor
	Swordsman(const string & name, double strength) : Warrior(name, strength){}
    // Overwritten Defend
    virtual void defend() const{
        // Print out message
        cout << "CLANG!  ";
        // Call Warrior's Defend
        Warrior::defend();
    }
};

int main(){
	
	Lord sam("Sam");
    Archer samantha("Samantha", 200);
    sam.hires(samantha);
    Lord joe("Joe");
    PersonWithStrengthToFight randy("Randolf the Elder", 250); 	
    joe.battle(randy);	
    joe.battle(sam);	
    Lord janet("Janet");	
    Swordsman hardy("TuckTuckTheHardy", 100);
    Swordsman stout("TuckTuckTheStout", 80);
    janet.hires(hardy);	
    janet.hires(stout);	
    PersonWithStrengthToFight barclay("Barclay the Bold", 300);	
    janet.battle(barclay);	
    janet.hires(samantha);	
    Archer pethora("Pethora", 50);	
    Archer thora("Thorapleth", 60);
    Wizard merlin("Merlin", 150);
    janet.hires(pethora);
    janet.hires(thora);
    sam.hires(merlin);
    janet.battle(barclay);	
    sam.battle(barclay);	
    joe.battle(barclay);

	return 0;

}