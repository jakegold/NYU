/*
    Copy Control with Inheritance
    Sec 
*/

#include <iostream>
using namespace std;

class Base {
public:
    Base() {
        cerr << "Base()\n";
    }
    Base(const Base& rhs) {
        cerr << "Base(const Base&)\n";
    }
    virtual ~Base() {
        cerr << "~Base()\n";
    }
    Base& operator=(const Base& rhs) {
        cerr << "Base::operator=(const Base&)\n";
        return *this;
    }
};

class Derived : public Base {
public:
      Derived() {
        cerr << "Derived()\n";
      }
//      Derived(const Derived& rhs) {
//        cerr << "Derived(const Derived&)\n";
//      }
    Derived(const Derived& rhs) : Base(rhs){
        cerr << "Derived(const Derived&)\n";
    }
      Derived& operator=(const Derived& rhs) {
        cerr << "Derived::operator=(const Derived&)\n";
//          *this Base:: = rhs;      what we want to do
          this->Base::operator=(rhs); //this is so that we can call the base and the derived
        return *this;
      }
     ~Derived() {
        cerr << "~Derived()\n";
      }
};

int main() {
    cerr << "Derived der;\n"
         << "------------\n";
    Derived der;
    cout << "===\n";
    cerr << "Derived der2(der);\n"
         << "------------------\n";
    Derived der2(der);
    cout << "===\n";
    cerr << "Derived der3 = der;\n"
         << "-------------------\n";
    Derived der3 = der;
    cout << "===\n";
    cerr << "der = der2;\n"
         << "-----------\n";
    der = der2;
    cout << "===\n";
    cerr << "Derived* p = new Derived();\n"
         << "delete p;\n"
         << "---------------------------\n";
    Derived* p = new Derived();
    delete p;
    cout << "===\n";
    cerr << "Derived* bp = new Derived();\n"
    << "delete bp;\n"
    << "---------------------------\n";
    Base* bp = new Derived();
    delete bp;
    cout << "===\n";
}
