#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main(){
	// vector<int> A = {1,2,3,4,5};
	// vector<int>::iterator vItr1;
	// vector<int>::iterator vItr2;
	// list<int> C = {1,2,3,4,5};
	// list<int>::iterator lItr1;
	// list<int>::iterator lItr2;

	// Question 2A
	// vItr1 = A.begin( );
	// vItr2 = A.end( );
	// cout << vItr1 + (vItr1 + vItr2)/2;

	// Question 2B
	// lItr1 = C.begin();
	// lItr2 = find(C.begin(), C.end(), 3);
	// if ( lItr1 < lItr2 ){
	// 	cout << " 2 is not the first item ";
	// }

	// Question 3
	// vector<int> A = {1,2,3,4,5};
	// vector<int> B;
	// vector<int>::iterator vItr;
	// list<int> C = {1, 2,3,4,5};
	// list<int> D;
	// list<int>::iterator lItr;

	// // (a) 
	// B = A;
	// vItr = B.begin();
	// cout << "*vItr+1: " << *(vItr+1) << endl;
	// B.erase(B.begin()+1);
	// cout << "*vItr: " << *vItr << endl;
	// // (b) 
	// B = A;
	// vItr = B.begin()+2;
	// cout << "*vItr: " << *vItr << endl;
	// B.erase(B.begin()+1);
	// cout << "*vItr: " << *vItr << endl;
	// (c) 
	// D = C;
	// lItr = C.begin();
	// cout << "*lItr: " << *lItr << endl;
	// C.erase(++C.begin());
	// cout << "*lItr: " << *lItr << endl;
	// (d) 
	// D = C;
	// lItr = ++D.begin();
	// ++lItr;
	// cout << "*lItr: " << *lItr << endl;
	// D.erase(++D.begin());
	// cout << "*lItr: " << *lItr << endl;

	// Question 4
	// // a
	// list<int> l;
	// list<int>::iterator lIter;
	// l.push_back(200);
	// lIter = l.begin();
	// for (int i = 1; i < 100; ++i)
	// l.push_front(i);
	// for (int i = 1; i < 100; ++i)
	// l.push_back(-i);
	// cout << *lIter << endl;

	// // b
	// list<int> l;
	// list<int>::iterator lIter1;
	// list<int>::iterator lIter2;
	// list<int>::iterator mid;
	// for (int i = 0; i < 100; ++i)
	// 	l.push_back(i);
	// lIter1 = l.begin();
	// lIter2 = l.end();
	// mid = lIter1 + (lIter2 - lIter1)/2;
	// cout << *mid << endl;

	// // c
	// vector<int> v;
	// vector<int>::iterator vIter1;
	// vector<int>::iterator vIter2;
	// vector<int>::iterator mid;
	// for (int i = 0; i < 100; ++i)
	// 	v.push_back(i);
	// vIter1 = v.begin();
	// vIter2 = v.end();
	// mid = vIter1 + (vIter2 - vIter1)/2;
	// cout << *mid << endl;

	return 42;
}