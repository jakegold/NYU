#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;


// All of the Instruments
class Instrument{
public:
	virtual void makeSound() const {
		cout << "To make a sound...";
	}
	virtual void normalPlay() const = 0;
};

// Brass Family
class Brass : public Instrument{
public:
	Brass(unsigned mouthPiece) : mouthPiece(mouthPiece){}
	virtual void makeSound() const {
		Instrument::makeSound();
		cout << "blow on a mouthpiece of size " << mouthPiece << endl;
	}
private:
	const unsigned mouthPiece;
};

class Trumpet : public Brass{
public:
	Trumpet(unsigned mouthPiece) : Brass(mouthPiece){}
	void normalPlay() const {
		cout << "Toot";
	}
};

class Trombone : public Brass{
public:
	Trombone(unsigned mouthPiece) : Brass(mouthPiece){}
	void normalPlay() const {
		cout << "Blat";
	}
};

// String Family
class String : public Instrument{
public:
	String(unsigned pitch) : pitch(pitch){}
	virtual void makeSound() const {
		Instrument::makeSound();
		cout << "bow a string with pitch " << pitch << endl;
	}
private:
	const unsigned pitch;
};

class Violin : public String{
public:
	Violin(unsigned pitch) : String(pitch){}
	void normalPlay() const {
		cout << "Screech";
	}
};

class Cello : public String{
public:
	Cello(unsigned pitch) : String(pitch){}
	void normalPlay() const {
		cout << "Squawk";
	}
};

// Percussion Family
class Percussion : public Instrument{
public:
	virtual void makeSound() const {
		Instrument::makeSound();
		cout << "hit me!" << endl;
	}
};

class Drum : public Percussion{
	void normalPlay() const {
		cout << "Boom";
	}
};

class Cymbal : public Percussion{
	void normalPlay() const {
		cout << "Crash";
	}
};

// Musician
class Musician {
public:
	Musician() : instr( NULL ) {}
	void acceptInstr( Instrument & i ) { instr = &i; }
	Instrument* giveBackInstr( ) { 
		Instrument* tmp(instr); 
		instr = NULL;
		return tmp;
	}
	void testPlay() const {
		if( instr )
			instr->makeSound(); 
		else
			cerr << "have no instr\n";
	}
	void normalPlay() const{
		if( instr )
			instr->normalPlay(); 
	}
private:
	Instrument* instr;
};

// MILL
class MILL{
public:
	void receiveInstr(Instrument & device){
		device.makeSound();
		for(size_t i = 0; i < stock.size(); ++i){
			if(!stock[i]){
				stock[i] = &device;
				return;
			}
		}
		stock.push_back(&device);
	}
	void dailyTestPlay() const {
		for(size_t i = 0; i < stock.size(); ++i){
			if(stock[i]){
				stock[i]->makeSound();
			}
		}
	}

	Instrument* loanOut(){
		for(size_t i = 0; i < stock.size(); ++i){
			if(stock[i]){
				Instrument* temp = stock[i];
				stock[i] = NULL;
				return temp;
			}
		}
		return NULL;
	}
private:
	vector<Instrument*> stock;
};

// Part TWO
// Orchestra
class Orch{
public:
	void addPlayer(Musician & person){
		if(people.size() < 25){
			people.push_back(&person);
		}
	}
	void play() const {
		for(size_t i = 0; i < people.size(); ++i){
			people[i]->normalPlay();
		}
		cout << endl;
	}

private:
	vector<Musician*> people;
};



// PART ONE
int main()
{
	/*
 	cout << "Define some instruments ----------------------------------------\n";
  	Drum drum;
  	Cello cello(673);
  	Cymbal cymbal;
  	Trombone tbone( 4 );
  	Trumpet trpt( 12 ) ;
  	Violin violin( 567 ) ;
  
  	// // use the debugger to look at the mill
  	cout << "Define the MILL ------------------------------------------------\n";
  	MILL mill;
  
  	cout << "Put the instruments into the MILL ------------------------------\n";
  	mill.receiveInstr( trpt );
  	mill.receiveInstr( violin );
  	mill.receiveInstr( tbone );
  	mill.receiveInstr( drum );
  	mill.receiveInstr( cello );
  	mill.receiveInstr( cymbal );
  
  	cout << "Daily test -----------------------------------------------------\n";
  	cout << endl;
  	cout << "dailyTestPlay()" << endl;
  	mill.dailyTestPlay();
  	cout << endl;
  
  	cout << "Define some Musicians-------------------------------------------\n";
  	Musician j;
  	Musician jj;
  	Musician q;
  	
  	cout << "TESTING: q.acceptInstr( *mill.loanOut() );-----------------------\n";
  	q.testPlay();	
  	cout << endl;
  	q.acceptInstr( *mill.loanOut() );
  	cout << endl;
  	q.testPlay();
  	cout << endl;
  	cout << "dailyTestPlay()" << endl;
  	mill.dailyTestPlay();
  
  	cout << endl << endl;
  
  	q.testPlay();	
  	cout << endl;
  	mill.receiveInstr( *q.giveBackInstr() );
  	j.acceptInstr( *mill.loanOut() );
  	q.acceptInstr( *mill.loanOut() );
  	cout << endl;
  	q.testPlay();
  	cout << endl;
  	j.testPlay();
  	cout << endl;
  	cout << "dailyTestPlay()" << endl;
  	mill.dailyTestPlay();
  
  	cout << "TESTING: mill.receiveInstr( *q.giveBackInstr() ); -------------\n";
  
  	// // fifth
  	mill.receiveInstr( *q.giveBackInstr() );
  	cout << "TESTING: mill.receiveInstr( *j.giveBackInstr() ); -------------\n";
  	mill.receiveInstr( *j.giveBackInstr() );

  
  	cout << endl;
  	cout << "dailyTestPlay()" << endl;
  	mill.dailyTestPlay();
  	cout << endl;
  	*/
  
  	// cout << endl;
  	// cout << "End of PART ONE of the rec!!!!" << endl;
  	// cout << endl;
  	// cout << "PART TWO!!!" << endl;
  	// cout << endl;

  // The initialization phase


	Drum drum;
	Cello cello(673);
	Cymbal cymbal;
	Trombone tbone( 4 );
	Trumpet trpt( 12 ) ;
	Violin violin( 567 ) ;

	MILL mill;
	mill.receiveInstr( trpt );
	mill.receiveInstr( violin );
	mill.receiveInstr( tbone );
	mill.receiveInstr( drum );
	mill.receiveInstr( cello );
	mill.receiveInstr( cymbal );

	Musician bob;
	Musician sue;
	Musician mary;
	Musician ralph;
	Musician jody;
	Musician morgan;

	Orch orch;



	// THE SCENARIO

	//Bob joins the orchestra without an instrument.
	orch.addPlayer(bob);

	//The orchestra performs
	cout << "orch performs\n";
	orch.play();

	//Sue gets an instrument from the MIL2 and joins the orchestra.
	sue.acceptInstr( *mill.loanOut() );
	orch.addPlayer(sue);

	//Ralph gets an instrument from the MIL2.
	ralph.acceptInstr( *mill.loanOut() );

	//Mary gets an instrument from the MIL2 and joins the orchestra.
	mary.acceptInstr( *mill.loanOut() );
	orch.addPlayer(mary);

	//Ralph returns his instrument to the MIL2.
	mill.receiveInstr( *ralph.giveBackInstr() );

	//Jody gets an instrument from the MIL2 and joins the orchestra.
	jody.acceptInstr( *mill.loanOut() );
	orch.addPlayer(jody);

	// morgan gets an instrument from the MIL2
	morgan.acceptInstr( *mill.loanOut() );

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	//Ralph joins the orchestra.
	orch.addPlayer(ralph);

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();
	
	// bob gets an instrument from the MIL2
	bob.acceptInstr( *mill.loanOut() );

	// ralph gets an instrument from the MIL2
	ralph.acceptInstr( *mill.loanOut() );

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	//Morgan joins the orchestra.
	orch.addPlayer(morgan);

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();


	return 0;
}
