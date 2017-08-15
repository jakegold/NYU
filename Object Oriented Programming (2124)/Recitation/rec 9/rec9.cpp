#include "Course.h"
#include "Student.h"
#include "Registrar.h"

#include <iostream>
#include <vector>
#include <string>


using namespace std;
using namespace BrooklynPoly;


int main(){

	Registrar registrar;

    cout << "No courses or students added yet\n";
    registrar.printReport();
     
    cout << "AddCourse CS101.001\n";
    registrar.addCourse("CS101.001");
    registrar.printReport();

    cout << "AddStudent FritzTheCat\n";
    registrar.addStudent("FritzTheCat");
    registrar.printReport();

    cout << "AddCourse CS102.001\n";
    registrar.addCourse("CS102.001");
    registrar.printReport();

    cout << "EnrollStudentInCourse FritzTheCat CS102.001\n";
    registrar.enrollStudentInCourse("FritzTheCat", "CS102.001");
    cout << "EnrollStudentInCourse FritzTheCat CS101.001\n";
    registrar.enrollStudentInCourse("FritzTheCat", "CS101.001");
    registrar.printReport();

    cout << "EnrollStudentInCourse Bullwinkle CS101.001\n";
    cout <<  "Should fail, i.e. do nothing, since Bullwinkle is not a student.\n";
    registrar.enrollStudentInCourse("Bullwinkle", "CS101.001");
    registrar.printReport();

    cout << "CancelCourse CS102.001\n";
    registrar.cancelCourse("CS102.001");
    registrar.printReport();

    cout << "Purge for start of next semester\n";
    registrar.purge();
    registrar.printReport();
}




   
