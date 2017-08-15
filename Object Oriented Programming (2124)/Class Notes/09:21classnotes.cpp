#include <iostream>
#include <fstream>
#include <vector>
#include <string>
// still not sure what this next one is for:
#include <cstdlib>

using namespace std;

//no longer a struct...its a class because your hiding this with private
class Person{
//public says that anyone can get this
public:
	Person(const string & theName, int theAge) : name(theName), age(theAge) {
									// this is not the best way to do this!!
									//name = theName; 
		// this is true because its happening right after the closed parethesis!! so can just leave this blank
		//  and then adding code after parenthesis...that is the initialization list

		// but if i am doing this not a non-primative i can do it!
									//age = theAge
		// however since im already doing an inhtialization list i can just add it on there
	}

	//the const is the same reason for puttng a const in other function...you can change it by accident
	// so now by giving this const the name or the age cannot change...thats why theres a const here
	void display() const {
		cout << "Person: " << name << ' ' << age << endl;
	}
	void setName(const string & theName){
		name = theName;
	}
	// coders like seeing their behaviors first and then what its made of so this comes second
// private says that only by using this you can acsess my names...not really sure what it means...
private:
	string name;
	int age;
	//note that your thigns should be lsited in the order of the initilization list
};

									//void displayPerson(const Person & aPerson);

int main(){
									//Person john;
									//john.name = "John";
									//john.setName("John");
									//displayPerson(john);
	// Now this is new and the fucntion inside the struct is new
									



	// but we dont like this way...so lets do it the following way:
	Person john("John", 18);
	//then i dont need to set a name to john..becuse he has a name
	// then do i need a setname method? --depends on the code


	john.display();

	return 0;
}

									//void displayPerson(const Person & aPerson){
										//cout << "Person: " << aPerson.name << endl;
									//}

//nake my code nicer... and from last time