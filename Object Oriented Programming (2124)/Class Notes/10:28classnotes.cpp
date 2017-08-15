#include <iostream>
#include <string>

using namespace std;

// THIS IS THE SAME NOTES AS YESTERDAY!!!

class Foo{
public:
	Foo(int x){p = new int(x);}
	Foo(Foo & yetAnotherFoo){ //new constructor...called a copy constructor	
		// yetAnotherFoo is something that i am playing with 
		int* anIntPtr = yetAnotherFoo.p;
		int val = *yetAnotherFoo.p;
		p = new int(val); //note you only use -> when to the left of the arrow is a pointers
		//p = new int(*yetAnotherFoo.p); //this is the same thing in one line
		// bassically whats happening is im taking in something and intialzingg myself to it

		// but do we really want to do this by value??!!! because this would cause an infinte cycle
		// of calling this constructor...thats why its by reference

		// not that this only had to be made because we have the destructor!!!!!!!!!!!
		// if we need a destructor than you will need a copy constructor!!!!!!!

		// (also by making only a copy constructor you will screw yourself)

		// also now that we have these two we will need to overide the assignment opperator
		// since whenever you do one of these you will need to do the other two they are called:
		// the big three, or copy control
	}  
	void display() const {cout << *p << endl;}
	void setValue(int val){*p = val}
	~Foo() {delete p;} //this is a destructor!!!!
	Foo& operator=(const Foo & myFoo){
		if(this != &myFoo){ //i am not self assigning something
		// we can run this line because 'this' holds an adress
			delete p; //this is the same code as from my destructor....freeing up space
			p = new int(*myFoo.p); //This is the same code from the copy constructor...allocates and copys
			// so what is going to happen in this code is we delete where the foo is pointing
			// and then what we do is assign to the pointer the value
			// from what is being passed into the method
			// and all of this is happening as long as it is not self assignment
		}
		return *this; //we want to return outselfs when we do this!! so it will be this..
		// but we said that this is an adress so we dont want that...we want whats actually at that adress
		// the dereferenced version of this...
		// and that is also why the return type is a Foo& !!!!!
	}
private:
	int* p;
};

void doNothing(Foo anotherFoo){
	// this is just making a copy of foo...but what does that copy look like?
}

void simpleFunc(){
	Foo aFoo(17);
	// normally you would have to put a delete here because when the funtion ends it goes out of scope!!
	// and if it gets out of scope then afoo is deleted but its a pointer!!!! so there is a memory leak

	// but we made a ~Foo() method which is just going to delete it automatically!!
	// so now there is no memory leak because it will be deleted at the end of this function

	doNothing(aFoo);
	// what does this mean???
	// for a primative its going to point to the same value on the heap (which in this case is 17)
	// so great...except the ~Foo is going to be called at the end of doNothing()!!!!!!!
	// so the 17 on the heap will be deleted and this function that i am in right now will not know it
	// so then what is aFoo pointing at??? it could be pretty much anything on the heap

	// and then at the end of this fuction the destructor is going to be called again and delete
	// something at the same adress!!! this is most proabably going to crash your program


	// so how do we fix this??? what we want to do is say that when we make a copy of a aFoo what we want
	// to do is have it make a copy also of what it is pointing to! 
	// so now it will be pointing to a whole new thing on the heap but with the same values
	// now in order to do this we need a new constructor!!! (see top of class for a new constrctor)
}

int main(){
	simpleFunc();

	// overloading assignemnt:
	Foo fooOne(6);
	Foo fooTwo(28);
	fooTwo = fooOne; //this will make fooTwo point to the same thing as fooOne and make a memeory leak
	// because the 28 is jsut chilling then....
	//operator=(fooTwo, fooOne);    //this cant be done just because irs a rule of the lang
	// the function call will look like this:
	fooTwo.operator=(fooOne); //this method is in the foo class!!!!
	return 0;
}