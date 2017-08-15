//
//  hw04(2.cpp
//  Lab 4
//
//  Created by Jake Goldstein on 10/14/15.
//  Copyright © 2015 Jake Goldstein. All rights reserved.
//

/*
 Jake Goldstein
 CS_1124 10/09/15
 This code will take an input of warriors, nobles and transactions
 that the nobles are making about the warriors.
 The nobles will then fight with eachother using warriors as bait,
 HW03
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
    void cleanUp(){
        for (size_t i = 0; i < army.size(); ++i){
            army[i] = nullptr;
            delete army[i];
        }
        army.clear();
    }
    
    void display() const{
        // Prints out the Noble and the size of his army of warriors
        cout << name << ':' << endl;
        // Loop through the warriors printing each one
        for(size_t i = 0; i < army.size(); ++i){
            cout << "   ";
            cout << army[i]->getWarriorName() << ": " << army[i]->getStrength();
            cout << endl;
        }
    }
private:
    // Noble varabiables
    const string & name;
    bool dead;
    vector<Warrior*> army;
};

// Opens the file and returns an error if the file isn't opened
void openFile(ifstream & file);

// Reads the file
void readFile(ifstream & file);

void makeNoble(string & nobleName, vector<Noble*> & noblePointers);

size_t getNobleIndex(const string & word, const vector<Noble*> & noblePointers);

void makeWarrior(ifstream & file, vector<Warrior*> & warPts);

size_t realWarrior(const string & word, const vector<Warrior*> & warPts);

void hireMe(ifstream & file, vector<Noble*> & nobPts, vector<Warrior*> & warPts);

void displayNoblePointerContents(vector<Noble*> & noblePointers){
    cout << "size of my vector of nobles is: " << noblePointers.size() << endl;
    cout << "the name of everyine in my vector is: " << endl;
    for(size_t i = 0; i < noblePointers.size(); i++){
        cout << noblePointers[i]->getNobleName() << endl;
    }
}

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
    file.open("someNoblesAndWarriors.txt");
    // Print an error if the file cannot open
    if(!file){
        cerr << "Warning! File cannot be opened!" << endl;
        exit(1);
    }
}

void readFile(ifstream & file){
    // Declare variables
    vector<Noble*> noblePoints;
    vector<Warrior*> jobless;
    string command, name;
    // Get a command from the fill
    while(file >> command){
        if (command == "Noble"){
            file >> name;
            makeNoble(name, noblePoints);
            for(size_t i = 0; i < noblePoints.size(); ++i){
                cout << "the name!" << i << "!" << noblePoints[i]->getNobleName() << endl;
            }
        }
        else if (command =="Warrior"){
            //cout << "a warrior" << endl;
            //makeWarrior(file, jobless);
        }
        else if (command == "Hire"){
            //cout << "being hired" << endl;
            //hireMe(file, noblePoints, jobless);
        }
        else if(command =="Fire"){
            // code
        }
        else if(command =="Battle"){
            // code
        }
        else if(command =="Status"){
            /*
             //cout << "a call for status" << endl;
             for (size_t i = 0; i < noblePoints.size(); ++i){
             noblePoints[i]->display();
             }
             cout << "jobless" << ':' << endl;
             for(size_t i = 0; i < jobless.size(); ++i){
             cout << jobless[i]->getWarriorName() << ": " << jobless[i]->getStrength();
             cout << endl;
             }
             }
             }
             else when the command is clear*/{
                 for (size_t i = 0; i < noblePoints.size(); ++i){
                     noblePoints[i]->cleanUp();
                     noblePoints[i] = nullptr;
                     delete noblePoints[i];
                 }
                 noblePoints.clear();
                 for (size_t i = 0; i < jobless.size(); ++i){
                     jobless[i] = nullptr;
                     delete jobless[i];
                 }
                 jobless.clear();
             }
        }
    }
}


void makeNoble(string & nobleName, vector<Noble*> & noblePointers){
    //if(getNobleIndex(name, noblePointers) == noblePointers.size()){
    // then make a new noble
    cout << "the name that is being passed into this function: " << nobleName << endl;
    Noble* placeholder = new Noble(nobleName);
    // cout << "my name is: " << placeholder->getNobleName() << endl;
    noblePointers.push_back(placeholder);
    cout << "my name is: " << noblePointers[noblePointers.size()-1]->getNobleName() << endl;
    
    
    //}
    //displayNoblePointerContents(noblePointers);
}
/*
 size_t getNobleIndex(const string & word, const vector<Noble*> & noblePointers){
 for(size_t i = 0; i < noblePointers.size(); i++){
 if(noblePointers[i]->getNobleName() == word){
 return i;
 }
 }
 return noblePointers.size();
 }
 */

void makeWarrior(ifstream & file, vector<Warrior*> & warPts){
    string name;
    int strength;
    file >> name;
    if(!realWarrior(name, warPts)){
        file >> strength;
        Warrior* placeholder = new Warrior(name, strength);
        warPts.push_back(placeholder);
    }
}

size_t realWarrior(const string & word, const vector<Warrior*> & warPts){
    for(size_t i = 0; i < warPts.size(); ++i){
        if(warPts[i]->getWarriorName() == word){
            return i;
        }
    }
    return warPts.size();
}



/*
 void hireMe(ifstream & file, vector<Noble*> & nobPts, vector<Warrior*> & warPts){
 string noble, warrior;
 file >> noble >> warrior;
 //size_t nobleMan = realNoble(noble, nobPts);
 //size_t armyMan = realWarrior(warrior, warPts);
 if(nobleMan > -1 && armyMan > -1){
 nobPts[nobleMan]->hire(warPts[armyMan]);
 while(armyMan < warPts.size()-1){
 warPts[armyMan] = warPts[armyMan + 1];
 ++armyMan;
 }
 warPts.pop_back();
 return;
 }
 return;
 
 }
 
 */


