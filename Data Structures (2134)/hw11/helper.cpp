#include <iostream>
#include <vector>
#include <queue>

using namespace std;

template <class Comparable>
class BinaryHeap{
 public:
 	// BinaryHeap( ){
 	// 	theSize = 0;
 	// }
 	// BinaryHeap( const vector<Comparable> & v );

 	bool isEmpty( ) const{
 		return (theSize > 0);
 	}

 	const Comparable & findMin( ) const;

 	void insert( const Comparable & x ){

		array[ theSize ] = x; // initialize sentinel 
		if( theSize + 1 == array.size( ) ) 
			array.resize( array.size( ) * 2 + 1 );
		// Percolate
		++theSize;
		int hole = 0;
		for( ; x < array[ hole * 2 ]; hole *= 2 ) 
			array[ hole ] = std::move( array[ hole * 2 ] );
		array[ hole ] = std::move( array[theSize] ); 
 	}

 	// void insert( Comparable && x );
 	void deleteMin( );

 	void print(){
 		for (int i = 0; i < theSize; ++i){
 			cout << array[i] << ", ";
 		}
 		cout << endl;
 		cout << "then the last thing..." << endl;
 	}

 private:
 	int theSize; // Number of elements in heap
 	vector<Comparable> array; // The heap array
 	// void buildHeap( );
 	// void percolateDown( int hole );
};

int main(){
	BinaryHeap<int> a;
	a.insert(6);
	a.insert(1);
	a.insert(2);
	a.insert(3);
	a.insert(9);

	a.print();

	return 42;
}
