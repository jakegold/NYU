#include "Registrar.h"
#include <iostream>
#include <string>

using namespace std;

namespace BrooklynPoly{
	void Registrar::addCourse(const string & name){
		Course *temp = new Course(name);
		classes.push_back(temp);
	}
	void Registrar::addStudent(const string & name){
		Student *temp = new Student(name);
		students.push_back(temp);
	}
	void Registrar::enrollStudentInCourse(const string & studentName, const string & courseName){
		for(size_t i = 0; i < students.size(); ++i){
			if(studentName == students[i]->getName()){
				for(size_t j = 0; classes.size(); ++j){
					if(courseName == classes[j]->getName()){
						students[i]->addClass(*classes[j]);
						return;
					}
				}
			}
		}
	}
	void Registrar::cancelCourse(const string & courseName){
		for(size_t i = 0; i < classes.size(); ++i){
			if(courseName == classes[i]->getName()){
				for(size_t j = 0; j < classes[i]->getVector().size(); ++j){
					classes[i]->getVector()[j] = nullptr;
				}
				delete classes[i];
				size_t holder = i;
				while(holder<classes.size()){
					classes[i] = classes[i+1];
					++holder;
				}
				classes.pop_back();
				return;
			}
		}
	}
	void Registrar::printReport(){
		cout << "All of the students: ";
		for (size_t i = 0; i < students.size(); ++i){
			cout << "	" << endl;
			students[i]->display();
		}
		cout << endl;
		cout << "All of the classes: ";
		for (size_t i = 0; i < classes.size(); ++i){
			cout << "	" << endl;
			classes[i]->display();
		}
		cout << endl;
	}

	void Registrar::purge(){
		for(size_t i = 0; i < students.size(); ++i){
			students[i] = nullptr;
			delete students[i];
		}
		students.clear();
		for(size_t i = 0; i < classes.size(); ++i){
			classes[i] = nullptr;
			delete classes[i]; 
		}
		classes.clear();
	}
}