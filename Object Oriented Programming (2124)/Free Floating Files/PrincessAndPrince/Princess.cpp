#include "Princess.h"
#include "FrogPrince.h" 
#include <iostream>

using namespace std;

namespace Fantasy{


	Princess::Princess(const string & name) : name(name), spouse(nullptr){}

	void Princess::display() const {
		cout << "Princess: " << name;
		if (spouse != nullptr){
			cout << "; spouse: " << spouse->getName() << endl; 
		}
		else{
			cout << "; single" << endl;
		}
	}
}