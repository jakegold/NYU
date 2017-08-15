#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Cat {
   string color;// = "black"; //this is only able to be done on c++ 11 compiler(which mine is)
   string name;// = "raizy";
   double weight;// = 123
};

int main(){
	Cat myCat;
	//cout << myCat.name << '\t' << myCat.color << '\t' << myCat.weight << endl;
	myCat.color = "grey";
	myCat.weight = 3.14;
	myCat.name = "catty";
	Cat raizy;
	raizy = myCat;
	raizy.name = "raizy";
	//cout << raizy.name << '\t' << myCat.color << '\t' << myCat.weight << endl;
	if (raizy.color == myCat.color  &&  (raizy.name == myCat.name)  && raizy.weight == myCat.weight) {
    	cout << "yay they are the same" << endl;
	}
	else{
		cout << "this is still fun!" << endl;
	}
	string s;
	s = "abcd";
	cout << s << endl;
	s.push_back('z'); //note that push_back() for strings must be a char
	cout << s << endl;
	s += 'y';
	cout << s << "the" << ' ' << "cat" << endl;

	string misi("cisi");
	cout << misi << endl;

	return 0;
}