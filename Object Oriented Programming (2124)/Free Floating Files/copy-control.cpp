/*
  Copy Control
  Sec 
 */

#include <iostream>
using namespace std;

class Foo {
public:
    Foo(int x) { p = new int(x); }
    // Copy Constructor
    //    Foo(Foo anotherFoo) {
    Foo(const Foo& anotherFoo) {
        // int* intPtr = anotherFoo.p;
        // int value = *intPtr;
        // p = new int(value);

        p = new int(*anotherFoo.p);
        //        p = new int(anotherFoo->p); // Won't compile

    }

    void display() const { cout << *p << endl; }
    void setValue(int val) { *p = val; }
    //    void cleanup() { delete p; }
    ~Foo() { delete p; }  // destructor

    // two = one;
    // two.operator=(one);
    ??? operator=(const Foo& rhs) {
        if (&rhs != this) { // not doing self-assignment
            // 1. Free up the old resources
            delete p;

            // 2. Allocating and copying
            p = new int(*rhs.p);

        }
        return ___;
    }        


private:
    int* p;
};

void doNothing(Foo someFoo) {
    someFoo.setValue(42);
}

void simpleFunc() {
    Foo aFoo(17);
    aFoo.display();
    doNothing(aFoo);
    aFoo.display();
    //    aFoo.cleanup();
}

int main() {
    simpleFunc();
    
    Foo one(6);
    Foo two(28);
    two = one;
    //    operator=(two, one);
    two.operator=(one);
}
