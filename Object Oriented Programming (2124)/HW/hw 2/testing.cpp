#include <iostream>
#include <fstream>

using namespace std;

int main(){
	ofstream hw01prep("someAttackersAndWeapons.txt");
	hw01prep << "Warrior Cisi Axe 12" << endl;
	hw01prep << "Warrior Misi Battle-Axe 32" << endl;
	hw01prep << "Battle Cisi Misi" << endl;
	hw01prep << "Warrior Risi Knife 93" << endl;
	hw01prep << "Warrior Erf Laser-Gun 54"  << endl; 
	hw01prep << "Battle Risi Erf" << endl;
	hw01prep << "Battle Cisi Erf" << endl;
	hw01prep << "Status" << endl;
	hw01prep.close();
	return 0;
}