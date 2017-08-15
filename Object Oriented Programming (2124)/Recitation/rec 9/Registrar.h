#ifndef REGISTRAR_H
#define REGISTRAR_H

#include <string>
#include <vector>
#include "Student.h"
#include "Course.h"

namespace BrooklynPoly{
	class Course;
	class Student;

	class Registrar{
	public:
		void addCourse(const std::string & name);
		void addStudent(const std::string & name);
		void enrollStudentInCourse(const std::string & studentName, const std::string & courseName);
		void cancelCourse(const std::string & courseName);
		void printReport();
		void purge();
	private:
		std::vector<Student*> students;
		std::vector<Course*> classes;
	};
}
#endif

