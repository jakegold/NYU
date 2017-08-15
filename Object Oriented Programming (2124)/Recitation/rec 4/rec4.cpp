#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

/* // Task One
class Sandwich{
public:
	void display() const{
		cout << "bread: " << bread << "cheese: " << cheese << "mayo: " << mayo;
		cout << "tomato: " << tomato << "mustard: " << mustard << endl;		
	}
private:
	int bread, cheese, tomato;
	double mayo, mustard;	
};

int main(){
	Sandwich a;
	a.display();
	return 0;
}
*/

/* // Task Two
class Sandwich{
public:
	void display() const{
		cout << "Bread: " << bread << " Cheese: " << cheese << " Mayo: " << mayo;
		cout << " Tomato: " << tomato << " Mustard: " << mustard << endl;		
	}
private:
	int bread, cheese, tomato;
	double mayo, mustard;	
};

int main(){
	Sandwich a;
	a.display();
	return 0;
}
*/

/* // Task Three
class Sandwich{
public:
	void display() const{
		cout << "Bread: " << bread << " Cheese: " << cheese << " Mayo: " << mayo;
		cout << " Tomato: " << tomato << " Mustard: " << mustard << endl;		
	}
private:
	int bread = 2, cheese = 1, tomato = 2;
	double mayo = 1.0, mustard = .05;	
};

int main(){
	Sandwich a;
	a.display();
	return 0;
}
*/

/* // Task Four
class Sandwich{
public:
	Sandwich(double myMayo) 
	: mayo(myMayo){}

	void display() const{
		cout << "Bread: " << bread << " Cheese: " << cheese << " Mayo: " << mayo;
		cout << " Tomato: " << tomato << " Mustard: " << mustard << endl;		
	}
private:
	int bread, cheese, tomato;
	double mayo, mustard;	
};

int main(){
	Sandwich a(.01);
	a.display();
	return 0;
}
*/

/* // Task Five
class Sandwich{
public:
	Sandwich(int myTomato = 2, int myCheese = 1, double myMustard = .05, double myMayo = 1.0, int myBread = 2) 
	: tomato(myTomato), cheese(myCheese), mustard(myMustard), mayo(myMayo), bread(myBread){}

	void display() const{
		cout << "Bread: " << bread << " Cheese: " << cheese << " Mayo: " << mayo;
		cout << " Tomato: " << tomato << " Mustard: " << mustard << endl;		
	}
private:
	int bread, cheese, tomato;
	double mayo, mustard;	
};

int main(){
	Sandwich a(1, 3, .12);
	a.display();
	return 0;
}
*/

/* // Task Six
class Sandwich{
public:
	Sandwich(int myTomato = 2, int myCheese = 1, double myMustard = .05, double myMayo = 1.0, int myBread = 2) 
	: tomato(myTomato), cheese(myCheese), mustard(myMustard), mayo(myMayo), bread(myBread){}

	void display() const{
		cout << "Bread: " << bread << " Cheese: " << cheese << " Mayo: " << mayo;
		cout << " Tomato: " << tomato << " Mustard: " << mustard << endl;		
	}

	int getBread() const{
		return bread;
	}

	int getCheese() const{
		return cheese;
	}

	int getTomato() const{
		return tomato;
	}

	double getMayo() const{
		return mayo;
	}

	double getMustard() const{
		return mustard;
	}
private:
	int bread, cheese, tomato;
	double mayo, mustard;	
};

int main(){
	Sandwich a(1, 3, .12, .04);
	int theBread, theCheese, theTomato;
	double theMayo, theMustard;
	theBread = a.getBread();
	theCheese = a.getCheese();
	theTomato = a.getTomato();
	theMayo = a.getMayo();
	theMustard = a.getMustard();
	cout << "Bread: " << theBread << " Cheese: " << theCheese << " Mayo: " << theMayo;
	cout << " Tomato: " << theTomato << " Mustard: " << theMustard << endl;
	//a.display();
	return 0;
}
*/

/* // Task Seven
class Sandwich{
public:
	Sandwich(int myTomato = 2, int myCheese = 1, double myMustard = .05, double myMayo = 1.0, int myBread = 2) 
	: tomato(myTomato), cheese(myCheese), mustard(myMustard), mayo(myMayo), bread(myBread){}

	void display() const{
		cout << "Bread: " << bread << " Cheese: " << cheese << " Mayo: " << mayo;
		cout << " Tomato: " << tomato << " Mustard: " << mustard << endl;		
	}

	int getBread() const{
		return bread;
	}

	int getCheese() const{
		return cheese;
	}

	int getTomato() const{
		return tomato;
	}

	double getMayo() const{
		return mayo;
	}

	double getMustard() const{
		return mustard;
	}
	void setBread(int newBread){
		bread = newBread;
	}

	void setCheese(int newCheese){
		cheese = newCheese;
	}

	void setTomato(int newTomato){
		tomato = newTomato;
	}

	void setMayo(double newMayo){
		mayo = newMayo;
	}

	void setMustard(double newMustard){
		mustard = newMustard;
	}
private:
	int bread, cheese, tomato;
	double mayo, mustard;	
};

int main(){
	Sandwich a(1, 3, .12, .04);
	int theBread, theCheese, theTomato;
	double theMayo, theMustard;
	a.display();
	a.setCheese(4);
	a.setMustard(.35);
	a.display();
	return 0;
}
*/

/*// Task Eight
class Sandwich{
public:
	Sandwich(int myTomato = 2, int myCheese = 1, double myMustard = .05, double myMayo = 1.0, const int myBread = 2) 
	: tomato(myTomato), cheese(myCheese), mustard(myMustard), mayo(myMayo), bread(myBread){}

	void display() const{
		cout << "Bread: " << bread << " Cheese: " << cheese << " Mayo: " << mayo;
		cout << " Tomato: " << tomato << " Mustard: " << mustard << endl;		
	}

	int getBread() const{
		return bread;
	}

	int getCheese() const{
		return cheese;
	}

	int getTomato() const{
		return tomato;
	}

	double getMayo() const{
		return mayo;
	}

	double getMustard() const{
		return mustard;
	}

	void setCheese(int newCheese){
		cheese = newCheese;
	}

	void setTomato(int newTomato){
		tomato = newTomato;
	}

	void setMayo(double newMayo){
		mayo = newMayo;
	}

	void setMustard(double newMustard){
		mustard = newMustard;
	}
private:
	int bread, cheese, tomato;
	double mayo, mustard;	
};

int main(){
	Sandwich a(1, 3, .12, .04, 5);
	int theBread, theCheese, theTomato;
	double theMayo, theMustard;
	a.display();
	a.display();
	return 0;
}
*/

/* // Task Ten
class Sandwich{
public:
	Sandwich(int myTomato = 2, int myCheese = 1, double myMustard = .05, double myMayo = 1.0, const int myBread = 2) 
	: tomato(myTomato), cheese(myCheese), mustard(myMustard), mayo(myMayo), bread(myBread){}

	void display() const{
		cout << "Bread: " << bread << " Cheese: " << cheese << " Mayo: " << mayo;
		cout << " Tomato: " << tomato << " Mustard: " << mustard << endl;		
	}

	int getBread() const{
		return bread;
	}

	int getCheese() const{
		return cheese;
	}

	int getTomato() const{
		return tomato;
	}

	double getMayo() const{
		return mayo;
	}

	double getMustard() const{
		return mustard;
	}

	void setCheese(int newCheese){
		cheese = newCheese;
	}

	void setTomato(int newTomato){
		tomato = newTomato;
	}

	void setMayo(double newMayo){
		mayo = newMayo;
	}

	void setMustard(double newMustard){
		mustard = newMustard;
	}
private:
	int bread, cheese, tomato;
	double mayo, mustard;	
};

class SandwichTruck{
public:
	void insertSandwich(const Sandwich & newSandwich) {
		sandwichs.push_back(newSandwich);
	}

	void checkBeforeLeaving() const {
		for(size_t i = 0; i < sandwichs.size(); ++i){
			cout << "sandwich at index " << i << ':' << endl;
			sandwichs[i].display();
		}
	}
private:
	vector<Sandwich> sandwichs;
};

int main(){
	Sandwich sandwichy(1, 3, .12, .04);
	SandwichTruck trucky;
	trucky.insertSandwich(sandwichy);
	trucky.checkBeforeLeaving();
	return 0;
}
*/

// Task Eleven
class Sandwich{
public:
	Sandwich(int myTomato = 2, int myCheese = 1, double myMustard = .05, double myMayo = 1.0, const int myBread = 2) 
	: tomato(myTomato), cheese(myCheese), mustard(myMustard), mayo(myMayo), bread(myBread){}

	void display() const{
		cout << "Bread: " << bread << " Cheese: " << cheese << " Mayo: " << mayo;
		cout << " Tomato: " << tomato << " Mustard: " << mustard << endl;		
	}

	int getBread() const{
		return bread;
	}

	int getCheese() const{
		return cheese;
	}

	int getTomato() const{
		return tomato;
	}

	double getMayo() const{
		return mayo;
	}

	double getMustard() const{
		return mustard;
	}

	void setCheese(int newCheese){
		cheese = newCheese;
	}

	void setTomato(int newTomato){
		tomato = newTomato;
	}

	void setMayo(double newMayo){
		mayo = newMayo;
	}

	void setMustard(double newMustard){
		mustard = newMustard;
	}
private:
	int bread, cheese, tomato;
	double mayo, mustard;	
};

class SandwichTruck{
public:
	void insertSandwich(const Sandwich & newSandwich) {
		sandwichs.push_back(newSandwich);
	}

	void checkBeforeLeaving() const {
		for(size_t i = 0; i < sandwichs.size(); ++i){
			cout << "sandwich at index " << i << ':' << endl;
			sandwichs[i].display();
		}
	}
private:
	vector<Sandwich> sandwichs;
};

int main(){
	Sandwich one;
	Sandwich two;
	two.setMustard(0);
	Sandwich three(2, 2);
	Sandwich four;
	SandwichTruck trucky;
	trucky.insertSandwich(one);
	trucky.insertSandwich(two);
	trucky.insertSandwich(three);
	trucky.insertSandwich(four);
	trucky.checkBeforeLeaving();
	cout << "mustard of sandwich two: " << two.getMustard() << endl;
	return 0;
}
