#include <iostream>

using namespace std;


class IntArray{
	public:
		IntArray(int n = 0): size(n), array(new int[n]){}
		void put (int i, int value);
		int get( int i);
	private:
		int * array;
		int size;
};

void IntArray::put(int i, int value){
    if(0 <= i && i < size){
        *(array + i) = value;
    }
}

int IntArray::get(int i){
    if(0 <= i && i < size){
        return *(array + i);
    }
    return 0;
}

void someFun( ){
	IntArray myA1(1);
	IntArray myA2(myA1);
	IntArray myA3(1);
	myA1.put(0, 12);
	cout << myA1.get(0) << endl; // should get 12
	myA2.put(0, 10);
	cout << myA1.get(0) << endl; // should get 10
	myA3.put(0, 5);
	myA1 = myA3;
	cout << myA1.get(0) << endl; // no idea
}
int main(int argc, const char * argv[]){
	someFun( );
	return 42;
}