#include <iostream>
#include <string>
#include <vector>

using namespace std;

// new material starting right now! test tomorrow!!

// we always kinda want to do this... cout << (something that is an object) << endl;
// but we were never able to...we did this: object.display()

class Person{
	friend ostream & operator <<(ostream & os, const Person & thisGuy); 
	// friend allows this function to use the private variables of Person
	friend bool operator ==(const Person & person1, const Person & person2);
	friend bool operator <(const Person & person1, const Person & person2);
public:
	Person(const string & name, const int number) : name(name), age(number){}


	// conversion operator...i think allows me to say if(person) {code..}
	// note there is no return type because its part of the name!
	operator bool() const{
		return age > 0;
	}
private:
	string name;
	int age;
};

// operator<<(cout, fred);
//we are printing to an ostream...(what ever that means...its like iostream i think or ofstream)
ostream & operator <<(ostream & os, const Person & thisGuy){ //not using so much memory because its by reference!
	os << thisGuy.name << ", " << thisGuy.age; // dont need an endl... we can put it elsewhere and its chill
	//note that this is a class....we cant just use thisGuy.name....we need a getter
	// so we need a thing in the class that allows this function to say thisGuy.name
	// that is above the public part of Person....key word friend
	return os;
}

// types of operators: (talking about overloading things because we just overloaded the output operator)
// output(cout, cin..), arithmetic(+,-...), logical(&&,||..), comparison(==,<...), assignment(), combination()


bool operator ==(const Person & person1, const Person & person2){
	return person1.name == person2.name && person1.age == person2.age; //not how i would have done that but ok...
}

bool operator <(const Person & person1, const Person & person2){
	return person1.age < person2.age; //not how i would have done that but ok...
}

bool operator <=(const Person & person1, const Person & person2){
	return person1 == person2 || person1 < person2; //and now i dont need to make this a friend
}

int main(){

	Person fred("Fred", 70);
	cout << fred << endl; //this is the goal!!
	//operator<<(cout, fred);

	Person george("George", 63);

	if (fred == george){ //actually is not going to compile because you need to make an == method for your class...
	// operator==(fred,george)
		//insert some code here...
	}
	if (fred < george){
// operator<(fred,george)
		//insert code here... and we can just keep doing this
	}

	if (fred <= george){
// operator<=(fred,george)
		//insert code here... and we can just keep doing this
	}


	return 0;
}