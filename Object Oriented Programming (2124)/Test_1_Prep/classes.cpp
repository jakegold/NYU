#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Vorlon {
public:
   Vorlon(const string& aName): myName(aName){}  // This will NOT COMPILE
   Vorlon() {}
   void setName(const string & newName){
   		myName = newName;
   }
   void display() {cout << "Displaying a Vorlon named " << myName << endl;}  // Note will be done better, later on.
private:
   string myName;  // Note that nyName is now const
};

class Cat{
public:
   Cat(const string& theName, const string& theColor, double theWeight) : name(theName), weight(theWeight), color(theColor) {}
   Cat() : name("Nameless"), weight(1), color("black"){}
   Cat(const string & newName) : name(newName), weight(5), color("red") {}
   void display() const {
      cout << "Displaying a Cat named" << name << " with color " << color << " and weight " << weight << endl;
   }
private:
   string name;
   string color;
   double weight;
};

int main(){
	/*
	Vorlon mean;
	mean.setName("meany"); // if the private stirng name is const than this will not work
	mean.display();
	Vorlon baby("baby");
	baby.display();
	*/
	Cat c1("cisi", "orange", 123);
	Cat c2;
	Cat c3("raizy");

	vector<Cat> kitties;
	kitties.push_back(c1);
	kitties.push_back(c2);
	kitties.push_back(c3);

	for (int i = 0; i < kitties.size(); ++i){
		kitties[i].display();
	}
	return 0;
}