/* 
Jake Goldstein 
CS_1124 10/16/15
This code will take a file that is a list of warriors, nobles, and transactions
that the nobles are making about the warriors.
The nobles will then fight to the death with eachother using warriors as bait
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

// Warrior Class
class Warrior{
public:
    // Constructor
    Warrior(const string & wNm, const double wStr) : name(wNm), strength(wStr){}
    // Get Strength
    double getStrength() const{
        return strength;
    }
    // Set strength
    void setStrength(double newStrength){
        strength = newStrength;
    }  
    // Get Name of Warrior
    string getWarriorName() const{
        return name;
    } 
private:
    // Variables
    double strength;
    string name;
};

// Noble Class
class Noble{
public:
    // Constructor
    Noble(const string & hisName) :name(hisName) {}
    // Get Noble name
    string getNobleName() const{
        return name;
    }
    // Add a warrior to the army
    void hire(Warrior* armyMember){
        army.push_back(armyMember);
    }
    // Delete all warriors from the army
    void cleanUp(){
        // Loop through army deleteing warriors
        for (size_t i = 0; i < army.size(); ++i){   
                delete army[i];
            }
            // Clear the vector
            army.clear();
    }

    // Get the total strength of a nobles army
    double getArmyStrength() const{
        double totalStrength = 0;
        // Loop through all warriors
        for(size_t i = 0; i < army.size(); ++i){
            // Add each strength to a total
            totalStrength += army[i]->getStrength();
        }
        // Return that total
        return totalStrength;
    }

        // Get the size of the army
    size_t getArmySize() const{
       return army.size();
    }

    // Gets the index on a warrior from army
    size_t findArmyMemberIndex(const string & armyMember)const {
        for (size_t i = 0; i < army.size(); ++i){
            if(army[i]->getWarriorName() == armyMember){
                return i;
            }
        }
        return army.size();
    }
    // Get a pointer to a warrior from army
    Warrior* getWarrior(const string & armyMember) const{
        // Loop through army
        for (size_t i = 0; i < army.size(); ++i){
            if(army[i]->getWarriorName() == armyMember){
                return army[i];
            }
        }
        return nullptr;
    }

    // Remove a warrior from the army
    void fire(string & armyMember){
        // Message:
        cout << "You don't work for me anymore " << armyMember << "! -- ";
        cout << getNobleName() << endl;
        // Loop through vector of army
        for(size_t i = 0; i < army.size(); ++i){
            if(army[i]->getWarriorName() == armyMember){
                size_t j = i;
                // Loop through the remaining parts of the vector
                while(j < army.size()-1){
                    // Get rid of warrior and push everyone else back one spot
                    army[j] = army[j+1];
                    ++j;
                }
                // Get rid of the doubles
                army.pop_back();
                return;
            }
        }
    }

    void battle(Noble & challenger){
        // Message:
        cout << name << " battles " << challenger.name << endl;
        // Declare variables
        double totalStrength = getArmyStrength();
        double challengerTotalStrength = challenger.getArmyStrength();
        // Check to see if any nobles are dead
        if (!checkForDeath(challenger)){
            return;
        }
        // Check to see if first noble wins
        else if (totalStrength > challengerTotalStrength){
            winner(challenger);
        }
        // If the challenger noble wins
        else if (totalStrength < challengerTotalStrength){
            challenger.winner(*this);
        }
        // If there is a tie
        else {
            cout << "Mutual Annihalation: " << name << " and ";
            cout << challenger.name << "die at each other's hands" << endl;
            // Run functions
            destroy();
            challenger.destroy();
        }
    }
    // Checks to see if either or both nobles are dead
    bool checkForDeath(Noble & challenger) const {
        // If they are both dead
        if (challenger.dead && dead){
            cout << "Oh, NO! They're both dead! Yuck!" << endl;
            return false;
        }
        // If the challenger is dead
        else if (challenger.dead && !dead){
            cout << "He's dead, " << name << endl;
            return false;
        }
        // If the first noble is dead
        else if (!challenger.dead && dead){
            cout << "He's dead, " << challenger.name << endl;
            return false;
        }
        // If no one is dead
        else return true;
    }
    // The losing noble is pased to the winner
    void winner(Noble & loser){
        // Declare a winner
        cout << name << " deafeats ";
        cout << loser.name << endl;
        // Run functions
        hurt(loser);
        loser.destroy();
    }
    // Makes all warriors strengths zero
    void destroy(){
        for(size_t i = 0; i < army.size(); ++i){
            army[i]->setStrength(0);
        }
        // Makes the noble dead so he can no longer fight
        dead = true;
    }

    // The winner is also hurt (loser is passed)
    void hurt(Noble & loser){
        // Establish how hurt the winner is by the following ratio
        double ratio = loser.getArmyStrength()/getArmyStrength();
        // Loop through vector of winner's warriors
        for(size_t i = 0; i < army.size(); ++i){
            // Lower all of the warrior's health
            army[i]->setStrength(army[i]->getStrength() * (1-ratio));
            // Ensure no one has a health lower than zero
            if (army[i]->getStrength() < 0){
                army[i]->setStrength(0);
            }
        }
    }
    void display() const{
        // Prints out the Noble and the size of his army of warriors
        cout << name << " has an army of: " << army.size() << endl;
        // Loop through the warriors printing each one
        for(size_t i = 0; i < army.size(); ++i){
            cout << "   ";
            cout << army[i]->getWarriorName();
            cout <<  ": " << army[i]->getStrength();
            cout << endl;
        }
    }
private:
    // Noble varabiables
    const string name;
    bool dead;
    vector<Warrior*> army;
};

// Opens the file and returns an error if the file isn't opened
void openFile(ifstream & file);
// Reads the file
void readFile(ifstream & file);
// Returns the index of a noble from a vector of pointers
size_t getNobleIndex(const string & word, const vector<Noble*> & noblePts);
// Returns the index of a warrior from a vector of pointers
size_t getWarriorIndex(const string & word, const vector<Warrior*> & warPts);

int main() {
    // Declare variables
    ifstream infile;
    // Run functions
    openFile(infile);
    readFile(infile);
    close(infile);
    return 0;
}

void openFile(ifstream & file){
    // Open the file
    file.open("nobleWarriors.txt");
    // Print an error if the file cannot open
    if(!file){
        cerr << "Warning! File cannot be opened!" << endl;
        exit(1);
    }
}

void readFile(ifstream & file){
    // Declare variables
    vector<Noble*> noblePointers;
    vector<Warrior*> jobless;
    string command;
    // Get a command from the file
    while(file >> command){
        // If the command is Noble
        if (command == "Noble"){
            // Declare variables and get info from file
            string name;
            file >> name;
            size_t nobleIndex = getNobleIndex(name, noblePointers);
            // Check to see if noble already exists
            if(nobleIndex == noblePointers.size()){
                // If not, make a new noble and add him to vector
                noblePointers.push_back(new Noble(name));
            }
            // If the noble exists
            else{
                cerr << "This Noble already exists!" << endl;
            }
        }
        // If the command is Warrior
        else if (command =="Warrior"){
            // Declare variables and get info from file
            string name;
            int power;
            file >> name >> power;
            size_t warriorIndex = getWarriorIndex(name, jobless);
            // Check to see if warrior already exists
            if(warriorIndex == jobless.size()){
                // If not, make a new warrior and add him to vector
                jobless.push_back(new Warrior(name, power));
            }
            // If the warrior exists
            else{
                cerr << "This Warrior already exists!" << endl;
            }
        }
        // If the command is Hire
        else if (command == "Hire"){
            // Declare variables and get info from file           
            string theNoble, theWarrior;
            file >> theNoble >> theWarrior;
            size_t nobleIndex = getNobleIndex(theNoble, noblePointers);
            size_t warriorIndex = getWarriorIndex(theWarrior, jobless);
            // Checks to see if both noble and warrior exist
            if(nobleIndex != noblePointers.size()){
                if(warriorIndex != jobless.size()){
                    // Noble hires warrior
                    noblePointers[nobleIndex]->hire(jobless[warriorIndex]);
                    // Warrior is removed from vector of all warriors
                    while(warriorIndex < jobless.size()-1){
                        // Vector is adjusted in content and size
                        jobless[warriorIndex] = jobless[warriorIndex + 1];
                        ++warriorIndex;
                    }
                    jobless.pop_back();
                }
                // If warrior does not exist
                else{
                    cerr << "This warrior does not exist, ";
                    cerr << "or is part of an army!" << endl;
                }
            }
            // If noble does not exist
            else{
                cerr << "This noble does not exist!" << endl;
            }
        }
        // If the command is Fire
        else if(command =="Fire"){
            // Declare variables and get info from file
            string theNoble, theWarrior;
            file >> theNoble >> theWarrior;
            size_t nobleIndex = getNobleIndex(theNoble, noblePointers);
            size_t warriorIndex;
            // Noble defined to save line space
            if(nobleIndex != noblePointers.size()){
                Noble* placeHolder = noblePointers[nobleIndex];
                warriorIndex = placeHolder->findArmyMemberIndex(theWarrior);
                size_t armySize = placeHolder->getArmySize();
                // Checks to see if both noble and warrior exist
                if((warriorIndex != armySize)){
                    // Temprary warrior made to push back to vector
                    Warrior* temp = placeHolder->getWarrior(theWarrior);
                    jobless.push_back(temp);
                    // Warrior is fired from noble's army
                    placeHolder->fire(theWarrior);
                }
                // If the warrior does not exist
                else{
                    cerr << "This warrior does not exist, ";
                    cerr << "or is not in this army" << endl;
                }
            }
            // If noble does not exist
            else{
                cerr << "This noble does not exist!" << endl;
            }
        }
        // If the command is battle
        else if(command =="Battle"){
            // Declare variables and get info from file
            string nobleOne, nobleTwo;
            file >> nobleOne >> nobleTwo;
            size_t firstNobleIndex = getNobleIndex(nobleOne, noblePointers);
            size_t secondNobleIndex = getNobleIndex(nobleTwo, noblePointers);
            // Checks to see if either noble does not exist
            // or if the nobles are the same person
            // Note the first if statment is on two lines
            if((firstNobleIndex != noblePointers.size()) 
                && (secondNobleIndex != noblePointers.size())){
                if(firstNobleIndex != secondNobleIndex){
                    // Nobles battle
                    // Noble defined to save line space
                    Noble* placeHolder = noblePointers[firstNobleIndex];
                    placeHolder->battle(*noblePointers[secondNobleIndex]);
                }
                else{
                    cerr << "A noble cannot battle himself!" << endl;
                }
            }
            else{
                cerr << "At least one of these nobles do not exist" << endl;
            }
        }
         // If the command is Status
        else if(command =="Status"){
            // Messages:
            cout << "Status" << endl;
            cout << "======" << endl;
            cout << "Nobles:" << endl;
            // If there are no nobles print NONE
            if(noblePointers.size() == 0){
                cout << "NONE" << endl;
            }
            // Print all nobles
            for (size_t i = 0; i < noblePointers.size(); ++i){
                noblePointers[i]->display();
            }
            // Warriors
            cout << "Unemployed Warriors:" << endl;
            // If there are no warriors left print NONE
            if(jobless.size() == 0){
                cout << "NONE" << endl;
            }
            // Print all warriors
            for(size_t i = 0; i < jobless.size(); ++i){
                cout << jobless[i]->getWarriorName() << 
                cout << ": " << jobless[i]->getStrength();
                cout << endl;
            }
        }
        //When the command is clear
        else { 
            // Loop through vector of nobles
            for (size_t i = 0; i < noblePointers.size(); ++i){ 
                // Delete army of the noble and then the noble himself
                noblePointers[i]->cleanUp();
                delete noblePointers[i];
            }
            noblePointers.clear();
            // Loop through vector of warriors deleteing all warriors
            for (size_t i = 0; i < jobless.size(); ++i){   
                delete jobless[i];
            }
            jobless.clear();
        }
    }
}


size_t getNobleIndex(const string & word, const vector<Noble*> & noblePts){
    // Loop through vector of noble pointers
    for(size_t i = 0; i < noblePts.size(); i++){
        // Return index if it is the noble being searched for
        if(noblePts[i]->getNobleName() == word){
            return i;
        }
    }
    // Else return the size of the vector
    return noblePts.size();
}

size_t getWarriorIndex(const string & word, const vector<Warrior*> & warPts){
    // Loop through vector of warriors pointers
    for(size_t i = 0; i < warPts.size(); ++i){
        // Return index if it is the noble being searched for
        if(warPts[i]->getWarriorName() == word){
            return i;
        }
    }
    // Else return the size of the vector
    return warPts.size();
}