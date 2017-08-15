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

int main(){

	Person fred("Fred", 70);
	cout << fred << endl; 

	Person george("George", 63);

	if (fred == george){ 
		//insert some code here...
	}
	if (fred < george){
		//insert code here...
	}

	if (fred <= george){
		//insert code here... and we can just keep doing this
	}


	return 0;
}









// NEW CODE FOR THIS CLASS
// This is a forward decleration
class FrogPrince; //this will allow the princess to have him as a pointer....and this is all that can put here
				  //other wise it is a deffinition


class Princess{
public:
	Princess(const string & name); //now that we are moving thigns outside of the class might as well : name(name), spouse(nullptr) {}
	void display() const; /* {    //the rest of this method is below!!!!! otherwise it wouldnt ever work!!
		cout << "Princess: " << name;
		if (spouse != nullptr){
			cout << "; spouse: " << spouse->getName() << endl; //this will not compile right now...
										//that is because the compiler doesnt know that a getName() exists yet!
										//this is only going to work if the compiler has seen things yet that it hasnt
										// so how do we fix this?? maybe move the method!!!
		}
		else{
			cout << "; single" << endl;
		}
	}
	*/
private:
	string name;
	FrogPrince* spouse;  //normally this doesnt work because the compiler doesnt see that Frogprince is a thing yet!!!
	// thats why its declared above!
	// its new because this is a new class!!!!!
};


//and do the same thing for FrogPrince where its going to be super clean!!!
//This is really what a class should look like!
class FrogPrince{
public:
	FrogPrince(const string & name);
	void display() const;
	string getName() const;
private:
	string name;
	Princess* spouse;
};


int main(){
	//this is a second main so this file is not going to run but whatever not the point
}


Princess::Princess(const string & name) : name(name), spouse(nullptr){}

void Princess::display() const {
	cout << "Princess: " << name;
	if (spouse != nullptr){
		cout << "; spouse: " << spouse->getName() << endl; //this will not compile right now...
										//that is because the compiler doesnt know that a getName() exists yet!
										//this is only going to work if the compiler has seen things yet that it hasnt
										// so how do we fix this?? maybe move the method!!!
	}
	else{
		cout << "; single" << endl;
	}
}

FrogPrince::FrogPrince(const string & name) : name(name), spouse(nullptr) {}
void FrogPrince::display() const {cout << "FrogPrince: " << name << endl;}
string FrogPrince::getName() const { return name; }

// i wanna come back to this later and make this all into header files and indepent class files and make it cool...
// note in headers we dont use using namespace std!!
// you never include a .cpp file!!!!
/* also in a cpp file you wouldnt need to include string if its already in your .h file as long
as your including using namespace std in your .cpp because its an extntion to it and your allowed to 
have namespace in .cpp 
*/ 
// can have this include string so many times because the people who made the string class are bosses
