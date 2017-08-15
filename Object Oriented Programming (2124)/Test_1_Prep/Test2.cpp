#include "iostream"
#include "string"

using namespace std;

class Base{
protected:
	int getValue() const {return value;}
public:
// 	virtual void foo(string s) {cout << "Base::foo(string)\n" ;} 
	virtual void display() const {cout << value << endl;}
	virtual ~Base() {cout << "~Base()";}
private:
	int value = 4;
};

class Derived : public Base{
public:
	void foo(int n) {cout << "Derived::foo(int)\n";}
	void display() const {cout << "Value: " << getValue() << endl;}
	~Derived() {cout << "~Derived()";}
};

// class Foo{
// public:
// 	explicit Foo(string s, int n = 0) {str = s; num = n;}
// 	void display() {cout << str << ':' << num << endl;}
// private:
// 	string str;
// 	int num;
// };

template <typename T>
void switcheroo(T& a, T& b){
	T temp = a;
	a = b;
	b = temp;
}


int main(){
	// // Derived der;
	// // der.foo("Felix");
	// Foo thingOne("abc", 17);
	// string s = "def";
	// // thingOne = s;
	// thingOne.display();

	// int b = 1;
	// int c = 2;
	// ++b = ++c;
	// cout << b << '	' << c << endl;

	// b = c++;
	// cout << b << '	' << c << endl;
	// Derived der;
	// der.display();
	// // cout << der.getValue() << endl;
	// Base base;
	// base.display();

	// int x = 17;
	// int* const p = &x;
	// *p = 10;
	// cout << *p << endl;

	// int y = 17;
	// const int* t = &y;
	// cout << *t << endl;
	// y = 8;
	// cout << *t << endl;
	// Derived* bp = new Derived;
	// delete bp;

	int jakei = 20;
	int yonii = 5;
	cout << "Jake: " << jakei << " Yoni: " << yonii << endl;
	switcheroo(jakei, yonii);
	cout << "Jake: " << jakei << " Yoni: " << yonii << endl;
	string jakes = "Jake";
	string yonis = "Yoni";
	cout << "Jake: " << jakes << " Yoni: " << yonis << endl;
	switcheroo(jakes, yonis);
	cout << "Jake: " << jakes << " Yoni: " << yonis << endl;






}