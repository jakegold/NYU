#include <iostream>
#include <fstream>

using namespace std;

int main(){
	ofstream hw00("encrypted.txt");
	hw00 << 5 <<  endl;
	hw00 << "Asi ymj rtrjwfymjx tzylwfgj." << endl;
	hw00 << "Aqq rnrxd bjwj ymj gtwtlwtajx" << endl;
	hw00 << "Dni ldwj fsi ldrgqj ns ymj bfgj." << endl;
	hw00 << "Tbfx gwnqqnl fsi ymj xnymjd ytajx" << endl;
	hw00.close();
	return 0;
}