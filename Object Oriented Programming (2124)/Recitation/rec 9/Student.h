#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include "Course.h"

namespace BrooklynPoly{

	class Course;


	class Student{
	public:
		Student(const std::string & name);
		void display()const;
		void addClass(Course & newClass);
		std::string getName()const;
	private:
		std::string name;
		std::vector<Course*> classes;
	};
}
#endif