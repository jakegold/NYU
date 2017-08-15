#include <iostream>
#include <vector>
#include <list>

using namespace std;


// string&& func(){
// 	string name;
// 	name = "raizy";
// 	// move(name);
// 	cout << "move(name)" << move(name) << endl;
// 	cout << "name" << name << endl;
// 	return move(name);
// }


class Raizy{
public:
	bool operator()(const int a, const int b){
		return a>b;
	}
};

class Cohen{
public:
	bool operator()(const string& a, const string& b){
		return a.length()>b.length();
	}
};

template <class object, class Jake>
bool funcMe(const object& first, const object& second, Jake jake){
	// cout << first << endl;
	return jake(first, second);
}

int main(){

	int a = 10;
	int b = 25;
	bool output = funcMe(a, b, Raizy());
	cout << output << endl;
	string j = "jake is a ";
	string l = "loser";
	cout << funcMe(j, l, Cohen()) << endl;
	// bool otherOutput = funcMe(j, l, Cohen());
	// cout << otherOutput << endl;

	// int a = 10;
	// cout << "a/2 " << a/2 << endl;
	// int b = 11;
	// cout << "b/2 " << b/2 << endl;

	// cout << func() << endl;
	// vector<int*> vints;
	// for (int i = 0; i < 26; ++i){
	// 	int* temp = new int(i);
	// 	vints.push_back(temp);
	// }
	// for (vector<int*>::iterator i = vints.begin(); i != vints.end(); ++i)
	// {
	// 	cout << *(*i) << endl;
	// }
	// for (int i = 0; i < vints.size(); i++)
	// {
	// 	delete vints[i];
	// }
	









	// vector<int> c { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	// vector<int>::iterator itr1 = c.begin()+2;
	// vector<int>::iterator itr2 = c.begin()+4;
	// vector<int>::iterator itr3 = c.begin()+8;
	// cout << "first part" << endl;
	// cout << *(c.begin( ) + ( c.end( ) - c.begin( ) )/2 ) << endl;
	// c.erase(itr2);
	// cout << *itr1 << endl;
	// cout << "erased item...: ";
	// cout << *itr2 << endl;
	// cout << *itr3 << endl;
	// cout << *(c.begin( ) + ( c.end( ) - c.begin( ) )/2 ) << endl;
	// cout << "some different question:" << endl;
	// cout << "#############################" << endl;

	// vector<int> a {1,2,3,4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 }; // vector, a, has n items
	// vector<int>::iterator itrStart;
	// vector<int>::iterator itrMid;
	// vector<int>::iterator itrEnd;
	// itrStart = a.begin();
	// itrEnd = a.end();
	// int mid = (a.end() - a.begin())/2;
	// cout << "middle: " << mid << endl;
	// itrMid = a.begin() + mid;
	// for (vector<int>::iterator i = itrStart; i != itrMid; ++i){
	// 	cout << *i << endl;
	// }
	// cout << "The second half..." << endl;
	// cout << "#####################" << endl;
	// for (vector<int>::iterator i = itrMid; i != itrEnd; ++i){
	// 	cout << *i << endl;
	// // }
	// vector<int> a {1, 2, 3, 4, 5};
	// vector<int>::iterator itra = a.begin();
	// cout << *(itra + 3) << endl;

	// // list<int> b {1, 2, 3, 4, 5};
	// // list<int>::iterator itrb = b.begin();
	// // cout << *(itrb + 3);

	// list<int> c {1, 2, 3, 4, 5};
	// list<int>::iterator itrc = c.end();
	// itrc--;
	// cout << *(itrc) << endl;

	// vector<int> d {1, 2, 3, 4, 5};
	// vector<char>::iterator itrd = d.begin();
	// cout << *(itrd + 3);
	return 0;
}