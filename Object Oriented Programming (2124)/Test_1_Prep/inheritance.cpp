/*
  Demonstrates that the compiler makes the choice for overloading
 */

#include <iostream>
using namespace std;

class Parent {
public:
    virtual void display() const { cout << "Parent\n"; }
};
class Child : public Parent {
public:
    virtual void display() const { cout << "Child\n"; }
};
class Grandchild : public Child {
public:
    virtual void display() const { cout << "Grandchild\n"; }
};

void func(Parent& base) { cout << "func(Parent)\n"; }
void func(Child& der) {cout << "func(Child)\n"; }
  
void otherFunc(Parent& base) {
  func(base);
  base.display();
}

int main() {
  Child child;
  func(child);

  Grandchild gc;
  func(gc);

  Parent par;

  otherFunc(child);
  otherFunc(gc);
  otherFunc(par);
}


/*
output
func(Child)
func(Child)
func(Parent)
Child
func(Parent)
Grandchild
func(Parent)
Parent
*/