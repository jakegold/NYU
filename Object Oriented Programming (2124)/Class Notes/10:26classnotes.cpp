#include <iostream>
#include <string>

using namespace std;

// should go over default constructors with inheritance

// note in headers we dont use using namespace std!!
// you never include a .cpp file!!!!
/* also in a cpp file you wouldnt need to include string if its already in your .h file as long
as your including using namespace std in your .cpp because its an extntion to it and your allowed to 
have namespace in .cpp 
*/ 
// can have this include string so many times because the people who made the string class are bosses



// at the top of out header files we need to add a "ifndef"...this allows us to do something really cool
// but i am not sure what the mole it does
// when you say it you need a symbol to add next to the ifndef...this should be some crazy thing that 
// no one else will add to their own file...this is where you get to be creative with crazy names
// or you can just put the name of the file or something

// we also are definine a new type of namespace that everything is put into(everything meaning the 
// cpp files and the header files)...this also does something that im not really so sure of what it is
// ---i think what it is that it would allow for a user to have more ease
// if for example they had a class or soemthing by the same name as princess then this helps them...(?)

// also note that we do not complie header files only .cpp files

// NEW TOPIC CALLED COPY CONTROL STARTING NOW
// bassically whats happenig is if we have a class which deals with the heap you may not always
// be deleteing things

class Foo{
public:
	Foo(int x){p = new int(x);}
	void display() const {cout << *p << endl;}
	void setValue(int val){*p = val}
	~Foo() {delete p;} //this is a destructor!!!!
private:
	int* p;
};

void simpleFunc(){
	Foo aFoo(17);
	// now because we have that last method in foo we dont have to worry about
	// deleteing things because it does it for us automattically
}

int main(){
	return 0;
}