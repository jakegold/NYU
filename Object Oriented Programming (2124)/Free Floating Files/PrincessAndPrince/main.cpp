#include "Princess.h"
#include "FrogPrince.h"


#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
using namespace Fantasy;


int main(){
	FrogPrince kermmy("Kermit");
	Princess raizy("Raizy");
	kermmy.display();
	raizy.display();
	return 0;
}