#include <iostream>
#include <vector>

using namespace std;

void bar(int x){
	const int* p = &x;
	cout << *p << ' ';
	x = 42;
}

class Base{
public:
	virtual void display() {cout << "Base\n";}
};

class Derived : public Base{
public:
	virtual void foo() {display();}
	void display() {cout << "Derived\n";}
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
	vector<int*> vip;
	int i = 0;
	while(i<5){
		int* x = new int(17);
		vip.push_back(x);
		++i;
	}
	for(size_t i =0;i<vip.size();++i){
		*vip[i]+=i;
	}
	for(size_t i=0;i<vip.size();++i){
		delete vip[i];
		vip[i] = nullptr;
	}
}