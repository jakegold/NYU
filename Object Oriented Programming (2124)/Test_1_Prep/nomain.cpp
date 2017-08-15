// MORE NEW CODE FOR THIS CLASS AT THE BOTTOM OF THE FILE


#include <iostream>
#include <string>
#include <vector>

using namespace std;

// when overloading opperators you can overide something if at least one of those is not a primiate
// ex(can't do 1+1=3 but can do cat+1=...)
// also can't change the number of parameters (called arity)...some operators are unary(one paramter !), binary(=),
// ternary (? : that is also known as the conditional opperator), and some operators have both


// types of operators: (talking about overloading things because we just overloaded the output operator)
// output(cout, cin..), arithmetic(+,-...), logical(&&,||..), comparison(==,<...), assignment(), combination()


// good to note:  (a+b)+c is what happens when a+b+c     and a=(b=c) is what happens when a=b=c


// not public methods are public...litterally anyone can get them...that can be bad!


// This code is from last class!!!

class Person{
	friend ostream & operator <<(ostream & os, const Person & thisGuy); 
	// friend allows this function to use the private variables of Person
	friend bool operator ==(const Person & person1, const Person & person2);
	friend bool operator <(const Person & person1, const Person & person2);
public:
	Person(const string & name, const int number) : name(name), age(number){}

	// conversion / coercion operator!
	// allows me to say:        if(fred) ====== if fred is a person with an age over 0, return true
	operator bool() const{
		return age > 0;
	}
private:
	string name;
	int age;
};


ostream & operator <<(ostream & os, const Person & thisGuy){ 
	os << thisGuy.name << ", " << thisGuy.age;
	//note that this is a class....we cant just use thisGuy.name....we need a getter
	// so we need a thing in the class that allows this function to say thisGuy.name
	// that is above the public part of Person....key word friend
	return os;
}


bool operator ==(const Person & person1, const Person & person2){
	return person1.name == person2.name && person1.age == person2.age; 
}

bool operator <(const Person & person1, const Person & person2){
	return person1.age < person2.age; 
}

bool operator <=(const Person & person1, const Person & person2){
	return person1 == person2 || person1 < person2; 
}
