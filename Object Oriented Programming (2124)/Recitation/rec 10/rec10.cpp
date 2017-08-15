/*
  Recitation 10
  CS1124
 
  Focus: Copy Control.  Uses dynamic array of pointers.
 */

#include <string>
#include <iostream>
using namespace std;

class Position {
public:
    Position(const string& aTitle, double aSalary)
	: title(aTitle), salary(aSalary) {}
    string getTitle() const {return title;}
    double getSalary() const {return salary;}
    void changeSalaryTo(double d) {salary = d;}
private:
    string title;
    double salary;
}; // class Position

class Entry {
public:
    Entry(const string& aName, unsigned aRoom, unsigned aPhone,
	  Position& aPosition) 
	: name(aName), room(aRoom), phone(aPhone), pos(&aPosition) {
    }
    friend ostream& operator<<( ostream& os, const Entry& e ) {
        os << e.name << ' ' << e.room << ' ' << e.phone;
        return os;
    } // operato<<

    string getName(){return name;}
    unsigned getRoom(){return room;}
    unsigned getPhone() const {return phone;}
    unsigned& getPhone(){return phone;}
    Position* getPosition(){return pos;}

private:
    string name;
    unsigned room;
    unsigned phone;
    Position* pos;
}; // class Entry

class Directory {
public:
    Directory()
	: capacity(2), size(0), entries(new Entry*[2] )
    {
        // Should we do this?  What do you think?
        for (size_t i = 0; i < capacity; i++) {
            entries[i] = nullptr;
        } // for
    } // Directory()

    Directory(const Directory& dir)
    : capacity(dir.capacity), size(dir.size), entries(new Entry*[dir.capacity]){
        cerr << "copy constructor" << endl;
        for(size_t i = 0; i < size; ++i){
            entries[i] = dir.entries[i];
        }
    } //copy constructor  

    ~Directory() { 
        cerr << "destructor" << endl;
        delete [] entries;
    } //Destructor

    void add(const string& name, unsigned room, unsigned ph, Position& pos) {
        if( size == capacity )	{
            // something is missing!!!  Add it!
            int biggerCap = capacity*2;
            Entry** biggerEntry = new Entry*[biggerCap];
            for(size_t i = 0; i < capacity; ++i){
                biggerEntry[i] = new Entry(entries[i]->getName(), entries[i]->getRoom(),
                entries[i]->getPhone(), *entries[i]->getPosition());
                delete entries[i];           
            }
            delete [] entries;
            entries = biggerEntry;
            capacity = biggerCap;
        } // if
        entries[size] = new Entry(name, room, ph, pos);
        ++size;
    } // add

    Directory& operator=(const Directory& secondDir){
        cerr << "assignment" << endl;
        if(this != &secondDir){
            delete [] entries;
            capacity = secondDir.capacity;
            size = secondDir.size;
            entries = new Entry*[secondDir.capacity];
            for(size_t i = 0; i < size; ++i){
                entries[i] = secondDir.entries[i];
            }
        }
        return *this;
    }// = opperator

    friend ostream & operator <<(ostream & os, const Directory & thisDir);

    unsigned operator[](string theName) const {
        for(size_t i = 0; i < size; ++i){
            // Entry* temp = entries[i];
            if(entries[i]->getName() == theName){
                return entries[i]->getPhone();
            }
        }
        return 0;
    }

    unsigned& operator[](string theName){
        for(size_t i = 0; i < size; ++i){
            // Entry* temp = entries[i];
            if(entries[i]->getName() == theName){
                return entries[i]->getPhone();
            }
        }
    }

private:	
    Entry** entries;
    size_t size;
    size_t capacity;
}; // class Directory

ostream & operator <<(ostream & os, const Directory & thisDir){
    for(size_t i = 0; i < thisDir.size; ++i){
        Entry* temp = thisDir.entries[i];
        cout << *temp << endl;
    }
    return os;
}

void doNothing(Directory dir) { cout << dir << endl; }

int main() {
	
    // Model as if there are these four kinds 
    // of position in the problem:
    Position boss("Boss", 3141.59);
    Position pointyHair("Pointy Hair", 271.83);
    Position techie("Techie", 14142.13);
    Position peon("Peonissimo", 34.79);
	
    // Create a Directory
    Directory d;
    cout << "adding Marilyn to D1" << endl;
    d.add("Marilyn", 123, 4567, boss);
    cout << "Printing d " << endl;
    cout << d << endl;

    unsigned thisNumber = d["Marilyn"];
    cout << "Marilyn's number from her name: " << thisNumber << endl;

    cout << "d2 = d" << endl;
    Directory d2 = d;	// What function is being used??
    cout << "adding Gallagher to D2" << endl;
    d2.add("Gallagher", 111, 2222, techie);
    cout << "adding Carmack to D2" << endl;
    d2.add("Carmack", 314, 1592, techie);
    cout << "Printing d2 " << endl;
    cout << d2 << endl;

    cout << "Calling doNothing\n";
    doNothing(d2);
    cout << "Back from doNothing\n";

    Directory d3;
    d3 = d2;
	
} // main
