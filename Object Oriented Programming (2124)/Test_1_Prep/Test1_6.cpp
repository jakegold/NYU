#include "iostream"

using namespace std;

class Base{
public:
	// virtual void display() {cout << "Base\n";} // this was for q_6
	virtual void display() {cout << "Base: " << n << endl;} // for q_9
protected:
	int n = 5; //q_9
};

class Derived : public Base{
public:
	// virtual void foo() {display();} // this was for q_6
	// void display() {cout << "Derived\n";} // this was for q_6
	virtual void display() {cout << "Derived: " << n << endl;}

};

class Thing{
public:
	Thing(int val) : n(val){}
	void display() {cout << "Thing\n";}
private:
	int n;
};

class ThingHolder{
public:
	void display() {cout << "ThingHolder\n";}
private:
	Thing something;
};

int main(){
	// Derived der; // this was for q_6
	// Base* bp = &der; // this was for q_6
	// bp->foo(); // this was for q_6
	// ThingHolder th; // for q_9
	// th.display(); // for q_9
	Derived der;
	der.display();
}