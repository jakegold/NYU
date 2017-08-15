/* 
Jake Goldstein 
CS_1124 10/02/15
Rec05
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// task 16
struct Complex {
   double real;
   double img;
};

// task 17
/*
class PlainOldClass {
public:
   PlainOldClass() : x(-72) {}
   int getX() const {
   	return x;
   }
   void setX( int val ) {
   	x = val;
   }
private:
   int x;
};
*/

// task 18
class PlainOldClass {  
public:
   PlainOldClass() : x(-72) {}
   int getX() const { return x; }
   void setX( int x )  { this->x = x; } 
private:
   int x;
};

// task 28
class Colour {  
public:       
    Colour( const string& name, unsigned r, unsigned g, unsigned b )       
        : name(name), r(r), g(g), b(b) {}       
    void display() const { 
        cout << name << " (RBG: " << r << "," << g<< "," << b << ")"; 
    }   
private:       
    string   name;    // what we call this colour       
    unsigned r, g, b; // red/green/blue values for displaying  
};    

// task 29
class SpeakerSystem {
   public:
   void vibrateSpeakerCones( unsigned signal ) const {

      cout << "Playing: " << signal << "Hz sound..." << endl;
      cout << "Buzz, buzzy, buzzer, bzap!!!\n";
   }
};

class Amplifier {
public:
	Amplifier():attachedSpeakers(NULL){}
   void attachSpeakers(SpeakerSystem& spkrs )
   {
      if( attachedSpeakers )
         cout << "already have speakers attached!\n";
      else
         attachedSpeakers = &spkrs;
   }
   void detachSpeakers() 
   { attachedSpeakers = NULL; }
     // should there be an "error" message if not attached?
   void playMusic( ) const {
      if( attachedSpeakers )
         attachedSpeakers -> vibrateSpeakerCones( 440 ); 
      else
         cout << "No speakers attached\n"; 
   }
private:
   SpeakerSystem* attachedSpeakers;
};

// task 30
class Person {  
public:       
    Person( const string& name ) : name(name) {}
    void movesInWith( Person& newRoomate ) {
        roomie = &newRoomate;        // now I have a new roomie            
        newRoomate.roomie = this;    // and now they do too       
    }       
    string getName() const { return name; }
    // Don't need to use getName() below, just there for you to use in debugging.
    string getRoomiesName() const { return roomie->getName(); }  
private:
    Person* roomie;       
    string name;  
};    

int main(){
	// task two
	cout << "task two" << endl;
	int x;
	cout << "value for x: " << x << endl; // task three
	x = 10;
	cout << "x = " << x << endl; // task four
	cout << endl;

	// task six
	cout << "task six" << endl;
	cout << "where is x? " << &x << endl;
	//cout << 0xb << "is the same as " << hex << 0xb << endl;
	cout << endl;

	// task 7
	cout << "task 7" << endl;
	cout << "the value " << x << " is stored in memory at " << &x << endl;
	cout << endl;

	// task 8
	cout << "task 8" << endl;
	int* p;
	p = &x;
	cout << "p = " << p << endl;
	cout << endl;

	// task nine
	// p = 0x0012fed4;
	// cout << 0x0012fed4 << endl;

	// task 10
	cout << "task 10" << endl;
	cout << "p points to where " << *p << " is stored" << endl;
	cout << "p* contains " << *p << endl;
	cout << endl;

	// task 11
	cout << "task 11" << endl;
	*p = -2763;
	cout << "p points to where " << *p << " is stored" << endl;
	cout << "*p now contains " << *p << endl;
	cout << "x now contains " << x << endl;
	cout << endl;

	// task 12
	cout << "task 12" << endl;
	int y(13);
	cout << "y contains " << y << endl;
	p = &y;
	cout << "p now points to where " << *p << " is stored" << endl;
	cout << "*p now contains " << *p << endl;
	*p = 980;
	cout << "p points to where " << *p << " is stored" << endl;
	cout << "*p now contains " << *p << endl;
	cout << "y now contains " << y << endl;
	cout << endl;

	// task 13
	cout << "task 13" << endl;
	int* q;      
	q = p;      
	cout << "q points to where " << *q << " is stored" << endl;      
	cout << "*q contains " << *q << endl;
	cout << endl;

	// task 14
	cout << "task 14" << endl;
	double d(33.44);      
	double* pD(&d);
	cout << "pD: " << *pD << endl;     
	*pD = *p;
	cout << "*pD: " << *pD << endl;  
	*pD = 73.2343;      
	cout << "*pD: " << *pD << endl;
	*p  = *pD;
	cout << "*p: " << *p << endl;      
	*q  = *p;   
	cout << "*q: " << *q << endl;   
	//pD  = p;
	//p   = pD;
	cout << endl;

	// task 15
	cout << "task 15" << endl;
	int joe( 24 );  
	const int sal( 19 );    
	int*  pI;  
	pI = &joe;  
	*pI = 234;  
	//pI = &sal;
	*pI = 7623; 	   

	const int* pcI;
	pcI = &joe;  
	//*pcI = 234;  
	pcI = &sal;  
	//pcI = 7623;    

	//int* const cpI;
	int* const cpI(&joe);
	//int* const cpI(&sal);
	//cpI = &joe;  
	*cpI = 234;  
	//cpI = &sal;  
	*cpI = 7623; 	   

	//const int* const cpcI;
	const int* const cpcI(&joe);
	//const int* const cpcI(&sal);
	//cpcI = &joe;  
	//*cpcI = 234;  
	//cpcI = &sal;  
	//*cpcI = 7623; 
	cout << endl;

	//task 16
	cout << "task 16" << endl;
	Complex c = {11.23,45.67};      
	Complex* pC(&c);
	// cout << "real: " << *pC.real << "imaginary: " << *pC.img << endl;
	//cout << "real: " << (*pC).real << " imaginary: " << (*pC).img << endl;
	cout << "real: " << pC->real << " imaginary: " << pC->img << endl;
	cout << endl;

	// task 17
	cout << "task 17" << endl;
	PlainOldClass poc;
	PlainOldClass* ppoc( &poc );
	cout << ppoc->getX() << endl;
	ppoc->setX( 2837 );
	cout << ppoc->getX() << endl;
	cout << endl;

	// task 19
	cout << "task 19" << endl;
	int* pDyn = new int(3); // p points to an int initialized to 3 on the heap     
	*pDyn = 17;
	cout << "The " << *pDyn
    << " is stored at address " << pDyn
    << " which is in the heap\n";
    cout << endl;

    // task 20
    cout << "task 20" << endl;
    cout << pDyn << endl;  
	delete pDyn;
	pDyn = NULL; // task 21
	cout << pDyn << endl;
	cout << "The 17 might STILL be stored at address " << pDyn<< " even though we deleted pDyn\n";  
	//cout << "But can we dereference pDyn?  We can try.  This might crash... " << *pDyn << ".  Still here?\n";
	double* pDouble( NULL ); // task 21
	cout << endl;

	// task 22
	//cout << "Can we dereference NULL?  " << *pDyn << endl;      
	//cout << "Can we dereference NULL?  " << *pDouble << endl;
	
	// task 23

	// task 24
	double* pTest = new double( 12 );      
	delete pTest;      
	pTest = NULL;      
	delete pTest; // safe

	// task 25
	short* pShrt = new short( 5 );      
	delete pShrt;      
	//delete pShrt; //dangerous

	// task 26
	long jumper( 12238743 );      
	//delete jumper;
	long* ptrTolong( &jumper );     
	//delete ptrTolong; //because not 'new'
	Complex cmplx;      
	//delete cmplx;

	// task 27
	cout << "task 27" << endl;
	vector<Complex*> complV; // can hold pointers to Complex objects
	Complex* tmpPCmplx;      // space for a Complex pointer
	for ( size_t ndx = 0 ; ndx < 3 ; ++ndx ) {
   		tmpPCmplx = new Complex; // create a new Complex object on the heap
   		tmpPCmplx->real = ndx;   // set real and img to be the
   		tmpPCmplx->img  = ndx;   // value of the current ndx
   		complV.push_back( tmpPCmplx ); // store the ADDRESS of the object in a vector or pointer to Complex
	}   	   
	// display the objects using the pointers stored in the vector
	for ( size_t ndx = 0 ; ndx < 3 ; ++ndx ) {         
    	cout << complV[ ndx ]->real << endl;         
    	cout << complV[ ndx ]->img  << endl;      
	}      
	// release the heap space pointed at by the pointers in the vector      
	for ( size_t ndx = 0 ; ndx < 3 ; ++ndx ) {         
    	delete complV[ ndx ];      
	}      
	// clear the vector      
	complV.clear();  
	cout << endl; 
	/*
	// task 28
	cout << "task 28" << endl;
	vector< Colour* > colours;         
	string inputName;       
	unsigned inputR, inputG, inputB;
	// control d indicates end of file from keyboard
	while ( cin >> inputName >> inputR >> inputG >> inputB ) {            
    	colours.push_back( new Colour(inputName, inputR, inputG, inputB) );       
	}  
	// display all the Colours in the vector:       
	for ( size_t ndx = 0; ndx < colours.size(); ++ndx ) {            
   		colours[ndx]->display(); 
   		delete colours[ndx]; 
    	cout << endl;       
	}
	cout << endl;
	*/
	// task 29
	SpeakerSystem speakers;
	unsigned cisi = 12;
	speakers.vibrateSpeakerCones(cisi);
	Amplifier amp;
	amp.attachSpeakers(speakers);
	amp.playMusic();
	cout << endl;

	// task 30
	cout << "task 30" << endl;
	// write code to model two people in this world       
	Person joeBob("Joe Bob"), billyJane("Billy Jane");         
	// now model these two becoming roommates       
	joeBob.movesInWith( billyJane );         
	// did this work out?       
	cout << joeBob.getName() << " lives with " << joeBob.getRoomiesName() << endl;
	cout << billyJane.getName() << " lives with " << billyJane.getRoomiesName() << endl;

}





