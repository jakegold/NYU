#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>
#include "Student.h"

namespace BrooklynPoly{

	class Student;


	class Course{
	public:
		Course(const std::string & name);
		void display() const;
		void addStudent(Student & learner);
		std::string getName()const;
		std::vector<Student*> getVector();
	private:
		std::string name;
		std::vector<Student*> students;
	};

}

#endif