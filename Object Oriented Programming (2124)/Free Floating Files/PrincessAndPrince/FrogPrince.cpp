#include "FrogPrince.h"
#include "Princess.h"
#include <iostream>

using namespace std;

namespace Fantasy{

	class FrogPrince;

	FrogPrince::FrogPrince(const string & name) : name(name), spouse(nullptr) {}
	void FrogPrince::display() const {cout << "FrogPrince: " << name << endl;}
	string FrogPrince::getName() const { return name; }
}