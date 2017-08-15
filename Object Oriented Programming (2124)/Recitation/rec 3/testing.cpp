#include <iostream>
#include <fstream>

using namespace std;

int main(){
	ofstream rec3prep("someH_C.txt");
	rec3prep << "Ethane C2H6" << endl;
	rec3prep << "ethylene C2H4" << endl;
	rec3prep << "Propane C3H8" << endl;
	rec3prep << "Propyne C3H3" << endl;
	rec3prep << "Butane C4H10" << endl;
	rec3prep << "n-Butane C4H10" << endl;
	rec3prep << "iso-Butane C4H10" << endl;
	rec3prep << "Pentane C5H12" << endl;
	rec3prep << "Hexane C6H14" << endl;
	rec3prep << "Heptane C7H16" << endl;
	rec3prep << "Octane C8H18" << endl;
	rec3prep << "Nonane C9H20" << endl;
	rec3prep << "Decane C10H22" << endl;
	rec3prep.close();
	return 0;
}
