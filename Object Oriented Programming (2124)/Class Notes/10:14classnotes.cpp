#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
topics from yesterday: (all of which is NOT on the mid-term)
hiding, overriding (override), overload and inheritance, constructors with polymorphism
but everything up until those things will be on the exam
*/


//shapes...theres all kinds of shapes: what (if im making classes to inherite) should be inherrited
// area, position, draw, num of sides, move...
class Shape{
public: 
	Shape(int x, int y) : x(x), y(y) {}
	void move(int x, int y) {this->x = x, this->y = y}
	//virtual draw() {/*code*/} 
	//note that this doesnt really mean anything but you need it for the other methods of other classes
	// so what you do is make an absrtact method which looks like the following: 
	//(its also known as a pure virtual method)
	virtual draw() = 0;
	//now every class of a shape has to have a draw method
	//note now that this class has a method that is abstract, its known as an abstract class

	//note can pull stuff like this: (see in triagnle draw)
	//void commonDrawCode() {/*code*/}
	//but there is a better way to do this! (see in cricle draw and below the priavte of shape)
private: 
	int x, y;
};

//a common draw function
void Shape::draw(){
	//some common code
}

class Triangle : public Shape{
public:
	Triangle(int x, int y) :Shape(x,y) {}
	virtual void draw(){/*code....commonDrawCode()....*/ }
private:
};

class Cicle : public Shape{
public:
	Circle(int x, int y) : Shape(x,y){}
	virtual void draw(){/*code*/ Shape::draw()/*...more code*/}
private:
};



int main(){
	Shape shape(17, 42);
	shape.draw()
	//but what the hell do these two lines mean?? 
	//how can you draw something like that?!?! theres no meaning...

	Triangle tri(3,4);
	tri.draw();
	tri.move(0,0);

	Circle circ(10,10);
	circ.draw();

	return 0;
}