#include "Course.h"
#include <iostream>
#include <string>

using namespace std;

namespace BrooklynPoly{


	Course::Course(const string & name): name(name){}
	void Course::display() const { 
		cout << "Course name: " << name << endl;
		cout << "Students in the course: ";
		for(size_t i = 0; i < students.size(); ++i){
			students[i]->display();
			cout << ' ';
		}
		cout << endl;
	}
	void Course::addStudent(Student & learner){
		students.push_back(&learner);
	}
	string Course::getName()const {return name;}
	vector<Student*> Course::getVector(){ return students;}
}