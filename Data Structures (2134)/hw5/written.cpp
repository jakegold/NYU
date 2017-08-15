#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void myRecFunc(int n){
	cout << n << ": ";
	if (n < 1) return;
	myRecFunc(n/2);
	myRecFunc(n/2);
	for (int i = 1; i < n; ++i)
		cout << "*";
	cout << endl;
}

void otherRecFunc(int n){
	cout << n << ": ";
	if (n < 1) return;
	otherRecFunc(n/2);
}

void firstRec(){
	cout << "with n = 0 " << endl;
	myRecFunc(0);
	cout << endl;
	cout << "###############" << endl;
	cout << "with n = 1 " << endl;
	myRecFunc(1);
	cout << endl;
	cout << "###############" << endl;
	cout << "with n = 2 " << endl;
	myRecFunc(2);
	cout << endl;
	cout << "###############" << endl;
	cout << "with n = 3 " << endl;
	myRecFunc(3);
	cout << endl;
	cout << "###############" << endl;
	cout << "with n = 4 " << endl;
	myRecFunc(4);
}

void secondRec(){
	cout << "with n = 0 " << endl;
	otherRecFunc(0);
	cout << endl;
	cout << "###############" << endl;
	cout << "with n = 1 " << endl;
	otherRecFunc(1);
	cout << endl;
	cout << "###############" << endl;
	cout << "with n = 2 " << endl;
	otherRecFunc(2);
	cout << endl;
	cout << "###############" << endl;
	cout << "with n = 3 " << endl;
	otherRecFunc(3);
	cout << endl;
	cout << "###############" << endl;
	cout << "with n = 4 " << endl;
	otherRecFunc(4);
}

int fib( int n ){
	cout << "one call of function " << endl;
	if( n <= 1 )
		return 1;
	else
		return fib( n - 1 ) + fib( n - 2 );
}

template<class Comparable>
void insertionSort( vector<Comparable> & a ){
	int j;
	for( int p = 1; p < a.size( ); p++ ){
		Comparable tmp = a[ p ];
		for( j = p; j > 0 && tmp < a[ j - 1 ]; j-- )
			a[ j ] = a[ j - 1 ];
		a[ j ] = tmp;
		// printVec(a); // prints the contents of the vector in order
		for (int i = 0; i < a.size(); ++i){
			cout << a[i] << ", ";
		}
		cout << endl;
	}
}

void quickSort( vector<int> & a, int low, int high ){
	for (int i = low; i < high + 1; ++i){
		cout << a[i] << ", ";
	}
	cout << endl;
	if (low < high){
		int mid = ( low + high )/2; // select pivot to be element in middle position
		// cout << "mid: " << mid << endl;
		int pivot = a[ mid ];
		// cout << "pivot: " << pivot << endl;
		swap( a[high], a[mid] ); // put pivot in a[high]

		// for (int i = 0; i < a.size(); ++i){
		// 	cout << a[i] << ", ";
		// }
		// cout << endl;

		// Begin partitioning
		int i, j;
		for( i = low, j = high - 1; ; ){
			// cout << "i: " << i << ", and j: " << j << endl;
			while ( a[i ] < pivot ) ++i;
			while( j > i && pivot < a[j ] ) --j;
			if( i < j )
				swap( a[ i++ ], a[ j-- ] );
			else
				break;
		}
		swap( a[ i ], a[ high ] ); // Restore pivot
		// printVec(a); // prints the contents of the vector in order
		// for (int i = 0; i < a.size(); ++i){
		// 	cout << a[i] << ", ";
		// }

		// cout << endl;
		quickSort( a, low, i - 1 ); // Sort small elements
		quickSort( a, i + 1, high ); // Sort large elements
	}
}

// template<class Object, class RandItr>
// void mergeSort(RandItr tempFirst, RandItr myStart, RandItr myEnd){
// 	auto mid = (myStart + myEnd)/2;
// 	auto temp = tempFirst;
// 	vector<Object> firstHalf = mergeSort(temp, myStart, mid);
// 	temp = tempFirst;
// 	vector<Object> secondHalf = mergeSort(temp + mid, mid + 1, myEnd);
// 	temp = tempFirst;
// 	merge(firstHalf.begin(), firstHalf.end(), secondHalf.begin(), secondHalf.end(), temp);
// }

// template <class RandItr>
// void mergeSort( RandItr start, RandItr end ){
// 	int sz = end - start; // or use auto sz = end-start;
// 	typedef typename iterator_traits< RandItr >::value_type Object; //Xcode
// 	// typedef iterator_traits< RandItr >::value_type Object; //Other compilers
// 	// Don’t worry about this line of code
// 	vector<Object> tmp( sz );
// 	mergeSort(tmp.begin(), start, end);
// }







template <class comp>
void myMerge(vector<comp>& a, vector<comp>& temp, int leftPos, int rightPos, int rightEnd);

template <class comp>
void mergeSort(vector<comp>& a, vector<comp>& temp, int left, int right);
// Mergesort algorithm (driver).
template<class comp>
void mergeSort( vector<comp> & a );

int main(){

	vector<int> a;
	a.push_back(28) ;
	a.push_back(10) ;
	a.push_back(2) ;
	a.push_back(27) ;
	a.push_back(5) ;
	a.push_back(1) ;
	cout << "unsorted:" << endl;
	for (int i = 0; i < a.size(); ++i)
	{
		cout << a[i] << ", ";
	}
	cout << endl;
	cout << "########################" << endl;
	quickSort(a, 0, a.size()-1);
	cout << "ordered" << endl;
	for (int i = 0; i < a.size(); ++i)
	{
		cout << a[i] << ", ";
	}
	// cout << endl;
	// firstRec();
	// secondRec();
	// cout << fib(1) << endl;
	// cout << fib(2) << endl;
	// cout << fib(3) << endl;
	// cout << fib(4) << endl;
	// cout << fib(5) << endl;
	// vector<int> vec;
	// vec.push_back(9);
	// vec.push_back(8);
	// vec.push_back(-11);
	// vec.push_back(2);
	// vec.push_back(0);
	// vec.push_back(3);
	// cout << "unsorted:" << endl;
	// for (int i = 0; i < vec.size(); ++i){
	// 	cout << vec[i] << ", ";
	// }
	// cout << endl;
	// cout << "sorted:" << endl;
	// vector<int> temp;
	// mergeSort(vec.begin(), vec.end());
	// for (int i = 0; i < vec.size(); ++i){
	// 	cout << vec[i] << ", ";
	// }
	// cout << endl;
	// return 42;
}

template <class comp>
void myMerge(vector<comp>& a, vector<comp>& temp, int leftPos, int rightPos, int rightEnd){
	int leftEnd = rightPos - 1;
	int tempPos = leftPos;
	int num = rightEnd - leftPos +1;
	while(leftPos <= leftEnd && rightPos <= rightEnd){
		if(a[leftPos] <= a[rightPos])
			temp[tempPos++] = move(a[leftPos++]);
		else
			temp[tempPos++] = move(a[rightPos++]);
	}
	while(leftPos <= leftEnd)
		temp[tempPos++] = move(a[leftPos++]);
	while(rightPos <= rightEnd)
		temp[tempPos++] = move(a[rightPos++]);
	for(int i = 0; i < num; i++, --rightEnd){
		a[rightEnd] = move(temp[rightEnd]);
	}
}

template <class comp>
void mergeSort(vector<comp>& a, vector<comp>& temp, int left, int right){
	for (int i = left; i < right + 1; ++i){
		cout << a[i] << ", ";
	}
	cout << endl;
	if(left<right){
		int center = (left+right)/2;
		mergeSort(a, temp, left, center);
		mergeSort(a, temp, center +1, right);
		myMerge(a, temp, left, center +1, right);
	}
}

// Mergesort algorithm (driver).
template<class comp>
void mergeSort( vector<comp> & a ) { 
	 vector<comp> tmpArray( a.size( ) ); 
	 mergeSort( a, tmpArray, 0, a.size( ) - 1 ); 
} 