#include <iostream>
#include <string>

using namespace std;

int main(){
	for (int counter = 0; counter < 10; ++counter){
		//you can put the ++ on either side
		cout << counter << endl; // endl is the same as \n
	} 
	// note: counter is only true for the loop...i cant use counter now it would compile
	int othercounter = 0;
	while (othercounter < 10){
		cout << othercounter << endl;
		++othercounter;
	}
	/*this is the same as the for loop but now i can use counter outside of the loop
	for the for loop you wouldnt be able to call it
	*/
	//note: globle variables suck and heres why...
	cout << othercounter << endl;
	//cout << counter << endl; 
	// but this line would not run
	return 0;
}