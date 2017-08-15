#include <iostream>
#include <fstream>

using namespace std;

int main(){
	ofstream hw01prep("someAttackers.txt");
	hw01prep << "Warrior Cisi 12" << endl;
	hw01prep << "Warrior Misi 32" << endl;
	hw01prep << "Battle Cisi Misi" << endl;
	hw01prep << "Warrior Risi 93" << endl;
	hw01prep << "Warrior Erf 54"  << endl; 
	hw01prep << "Status" << endl;
	hw01prep.close();
	return 0;
}