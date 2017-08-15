#include "Student.h"
#include <iostream>
#include <string>

using namespace std;

namespace BrooklynPoly{


	Student::Student(const string & name): name(name){}
	void Student::display()const { cout << "Student's name: " << name;}
	void Student::addClass(Course & newClass){
		classes.push_back(&newClass);
		newClass.addStudent(*this);
	}
	string Student::getName()const{return name;}
	

}