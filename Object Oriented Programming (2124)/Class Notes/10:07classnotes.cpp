#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

// This is his code from 10/5 which i missed
class Pet {
public:
	// constructors are not inherited!
	Pet(const string & thisName) : name(thisName) {}
    // Polymorphism -- it is not the defulat behavior...in order to get the non-default need virtual
    // you should use it in the highest up class that is being inheritted
    virtual void display() const { cout << "Pet" << name << endl; } 
protected: //not exactly sure what protected does but for some reason now only the cat can gets its name
// for example when i print out the cat in the cat class it becomes protected
// but actually i can if i wanted make the string name protected, not private!
// but generally fields in the class should be made priavte so keep string name private and a proteced getter
    string getName() const {
    	return name;
    }
private:
	string name;
};

class Cat : public Pet {  //this public part is suuuper important
public:
	//Cat(const string & thisName) : name(thisName) {} //this doesnt work
	// that is becaues you need to talk about pets at the same time...you need to make a pet of a cat (i think)
	Cat(const string & thisName) : Pet(thisName) {}
    void display() const { 
    	cout << "Cat " << getName() << endl;   // override 
    	// also note that if i put name in there it wouldnt work 
    	//because he dosnt have a name...the pet has a name and the cat is just a peice of that pet
    	// so how do i get his name...with a method..but by doing this i made his name public...
    	// so instead of public or private, make his name protected!
    	purr();

    	// and if i wanted to call the display from the pet class 
    	cout << "cat";
    	Pet::display(); //need to give this method its full name because otherwise it calls display from cat
    }
    	//this override only will work if the call, the paramters, and the const-ness are the same
    void purr() const {
    	cout << " Purrrrr" << endl;
    }
private:
	string name;
};

void displayAPet(const Pet& aPet) {
    //void displayAPet(Pet aPet) {  //not as good of an idea
    aPet.display(); //better!
    //so now i made a pur method but i cannot call it from here
    // but if i add it to the display method in cat it will work because this display calls to a cats display
}




/* and so on...now what if we didnt have any inheritance. how do i do this?
// this is good for a lang that doesnt have inheritance

// you would need to do this...make a pet and then in pet check everything everytime
class Pet {
public:
	void eat(){
		if (type == "cat"){
			//code goes here
		}
		else if(type == "other"){
			//and so on
		}
	}
private:
	string type;
};
*/




int main(){
	//note that if i was to have a vector and want to get rid of an item in the middle
	// i should then loop through and copy every item to move it to one space closer to the front
	// and when im done with all of that pop_back() which gets rid of the last item (need this for hw03)

	// inheretance (butchered that spelling)


	Pet peeve("cisi");
    peeve.display();
    Cat felix("misi"); //this doesnt work because constructors are not inherited 
    felix.display();


	//this doesnt work so well because push_back is copying and then you lose the fact if it is a cat an not a pet
	vector<Pet> menagerie;
	menagerie.push_back(peeve); 
    menagerie.push_back(felix); 
    for (size_t i = 0; i < menagerie.size(); ++i) {
        menagerie[i].display();
    }


    // this should work because im only pasing the reference of where the cats and or the pets are
    vector<Pet*> menageriePtr;
    menageriePtr.push_back(&peeve); 
    menageriePtr.push_back(&felix); 
    for (size_t i = 0; i < menageriePtr.size(); ++i) {
        menageriePtr[i]->display();
    }

// note that you can make more general things specific things, but you lose some info
// but you cant make specific things general things
    // ex: peeve = felix //but you lose info
    // ex: felix = peeve //not allowed
    // but can do this: Pet* petPtr = &felix
    // note that we actually already did this when we made a vector of pet pointers


}