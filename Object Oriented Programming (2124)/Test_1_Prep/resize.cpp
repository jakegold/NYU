#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

int main(){
	vector<int> v1;
	v1.push_back(12);
	v1.push_back(12);
	v1.push_back(12);
	v1.push_back(12);
	v1.push_back(12);
	cout << "Loop:";
	for (int i = 0; i < v1.size(); ++i){
		cout << v1[i] << '	';
	}
	cout << endl;
	cout << "size: " << v1.size() << endl;
	cout << "resizing" << endl;
	v1.resize(2);
	cout << "Loop:";
	for (int i = 0; i < v1.size(); ++i){
		cout << v1[i] << '	';
	}
	cout << endl;
	cout << "size: " << v1.size() << endl;
	cout << "push_back: ";
	v1.push_back(13);
	cout << "Loop:";
	for (int i = 0; i < v1.size(); ++i){
		cout << v1[i];
	}
	cout << endl;
	cout << "size: " << v1.size() << endl;
	cout << "filling it up: " << endl;
	cout << "Loop:";
	for (int i = 0; i < v1.size(); ++i){
		v1[i] = 42;
	}
	cout << "Loop:";
	for (int i = 0; i < v1.size(); ++i){
		cout << v1[i] << '	';
	}
	cout << endl;
	cout << "size: " << v1.size() << endl;
}
