#include "iostream"

using namespace std;

class Derived;

class Base{
public:
	virtual void method(Base& arg){cout << "Base::method(Base)";}

	virtual void method(Derived& arg){cout << "Base::method(Derived)";}
};

class Derived : public Base{
public:
	virtual void method(Base& arg){cout << "Derived::method(Base)";}

	virtual void method(Derived& arg){cout << "Derived::method(Derived)";}
};

void someFunc(Base& arg){
	arg.method(arg);
}

int main(){
	Derived d;
	someFunc(d);
}
