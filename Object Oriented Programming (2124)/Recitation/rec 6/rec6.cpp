#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

class TimeSlot{
public:
	// Displays the time in standard 12 hour convention
	TimeSlot(const string & weekDay, const int tS) : weekDate(weekDay), hour(tS) {}
	void displayTime() const{
		cout << weekDate << ' ';
		if(hour > 12){
			cout << (hour - 12) << "PM" << endl;
		}
		else {
			cout << hour << "AM" << endl;
		}
	}

private:
	string weekDate;
	unsigned hour;
};

class StudentRecord{
public:
	StudentRecord(const string & theirName) : name(theirName),grades(13,-1){}

	void changeGrades(const int index, const int newGrade){
		grades[index] = newGrade;
	}

	void displayGrades() const {
		cout << "Student: " << name << "; Grades: ";
		int i = 0;
		while (i < 13){
			cout << grades[i] << ' ';
			++i;
		}
		cout << endl;
	}
	string getName(){
		return name;
	}

private:
	string name;
	vector<int> grades;
};

class Section{
public:
	Section(const string & secName, const string & weekDay, const int tS) : sectionName(secName), classTime(weekDay, tS){}
	void display() const {
		cout << sectionName << "; ";
		classTime.displayTime();
		for(size_t i = 0; i < students.size(); ++i){
			students[i]->displayGrades();
		}
	}
	void addStudent(const string & studentName){
		StudentRecord* student= new StudentRecord(studentName);
		students.push_back(student);
	}
	void changeGrade(const string & studentName, const int newGrade, const int index){
		for(size_t i = 0; i < students.size(); ++i){
			if(students[i]->getName() == studentName){
				students[i]->changeGrades(index, newGrade);
			}
		}
	}
	void reset(){
		for (size_t i = 0; i < students.size(); ++i){	
			students[i] = nullptr;
			delete students[i];
		}
		students.clear();
	}
	size_t size(){
		return students.size();
	}

private:
	string sectionName;
	TimeSlot classTime;
	vector<StudentRecord*> students;

};

class LabWorker{
public:
	LabWorker(const string & theirName) : name(theirName){}
	void addGrade(const string & student, const int newGrade, const int index){
		//size_t studentIndex = &theirSection->studentIndex(student);
		theirSection->changeGrade(student , newGrade, index);
	}
	void displayGrades(){
		cout << name << " has Section: ";
		theirSection->display();
	}
	void addSection(Section& sec){
		theirSection = &sec;
	}

private:
	string name;
	Section *theirSection;
};


int main(){
// lab workers
   LabWorker moe( "Moe" );
   LabWorker jane( "Jane" );
   
   // sections and setup and testing
   Section secA2( "A2", "Tuesday", 16 );
   //secA2.loadStudentsFromFile( "A2.txt" );
   secA2.addStudent("John");
   secA2.addStudent("George");
   secA2.addStudent("Paul");
   secA2.addStudent("Ringo");

   cout << "\ntest A2\n";    // here the modeler-programmer checks that load worked
   secA2.display();          // YOU'll DO THIS LATER AS: cout << secA2 << endl;
   moe.addSection( secA2 );
   moe.displayGrades();       // here the modeler-programmer checks that adding the Section worked
  
   Section secB3( "B3", "Thursday", 11 );
   //secB3.loadStudentsFromFile( "B3.txt" );
   secB3.addStudent("Thorin");
   secB3.addStudent("Dwalin");
   secB3.addStudent("Balin");
   secB3.addStudent("Kili");
   secB3.addStudent("Fili");
   secB3.addStudent("Dori");
   secB3.addStudent("Nori");
   secB3.addStudent("Ori");
   secB3.addStudent("Oin");
   secB3.addStudent("Gloin");
   secB3.addStudent("Bifur");
   secB3.addStudent("Bofur");
   secB3.addStudent("Bombur");

   cout << "\ntest B3\n";    // here the modeler-programmer checks that load worked
   secB3.display();          // YOU'll DO THIS LATER AS: cout << secB3 << endl;
   jane.addSection( secB3 );
   jane.displayGrades();      // here the modeler-programmer checks that adding Instructor worked


   // setup is complete, now a real world scenario can be written in the code
   // [NOTE: the modeler-programmer is only modeling joe's actions for the rest of the program]

   // week one activities  
   cout << "\nModeling week: 1\n";
   moe.addGrade( "John", 7, 1 );  
   moe.addGrade( "Paul", 9, 1 );  
   moe.addGrade( "George", 7, 1 );  
   moe.addGrade( "Ringo", 7, 1 );  
   cout << "End of week one\n";
   moe.displayGrades();

   // week two activities
   cout << "\nModeling week: 2\n";
   moe.addGrade( "John", 5, 2 );  
   moe.addGrade( "Paul", 10, 2 );  
   moe.addGrade( "Ringo", 0, 2 );  
   cout << "End of week two\n";
   moe.displayGrades();

   //test that reset works  // NOTE: can we check that the heap data was dealt with?
   cout << "\ntesting reset()\n";
   secA2.reset();
   secA2.display();
   moe.displayGrades();


	return 0;
}