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
    //    ~Base() {
    virtual ~Base() {
        cerr << "~Base()\n";
    }
    Base& operator=(const Base& rhs) {
        cerr << "Base::operator=(const Base&)\n";
        return *this;
    }
    void aMethod() {}
};

class Embedded {
public:
    Embedded() {
        cerr << "Embedded()\n";
    }
    Embedded(const Embedded& rhs) {
        cerr << "Embedded(const Embedded&)\n";
    }
    //    ~Embedded() {
    virtual ~Embedded() {
        cerr << "~Embedded()\n";
    }
    Embedded& operator=(const Embedded& rhs) {
        cerr << "Embedded::operator=(const Embedded&)\n";
        return *this;
    }
    void aMethod() {}
};

class Derived : public Base {
public:
    Derived() {
        cerr << "Derived()\n";
    }

    Derived(const string& s) {
        cerr << "Derived()\n";
        //        name = s;
    }

    Derived(const Derived& rhs) : Base(rhs), em(rhs.em) {
        cerr << "Derived(const Derived&)\n";
    }

    Derived& operator=(const Derived& rhs) {
        cerr << "Derived::operator=(const Derived&)\n";
        //        *this Base::= rhs;
        //        (*this).Base::operator=(rhs);
        //this->Base::operator=(rhs);
        Base::operator=(rhs);
        // aMethod();
        // this->aMethod();
        // Base::aMethod();
        // this->Base::aMethod();
        em = rhs.em;
        return *this;
    }

    ~Derived() {
        cerr << "~Derived()\n";
    }

    void aMethod() {}


private:
    Embedded em;
    string name;
};

void simpleFunc() {
    cerr << "simpleFunc()\n";
    Derived der;
}

int main() {
    simpleFunc();
    cout << "===\n";

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
    cerr << "Base* bp = new Derived();\n"
         << "delete bp;\n"
         << "---------------------------\n";
    Base* bp = new Derived();
    delete bp;
    cout << "===\n";
}
