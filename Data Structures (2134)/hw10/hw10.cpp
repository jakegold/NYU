#include <iostream>
#include <vector>

using namespace std;

// Implement find, insert, rehash
// Rehash when: load factor >= .5

template<class HashedObj>
class HashTable{
public:
	explicit HashTable( int size = 101 ):currentSize(0){ array.resize(size); }

	// ...and how do i call this????			 is it just hf(x);
	std::hash<HashedObj> hf; // create a hash function object

	bool contains( const HashedObj & x ) const{

	}

	void makeEmpty(){ 					//ARE THE ITEMS IN THE ARRAY SUPPOSED TO BE ON THE HEAP??
		for (int i = 0; i < array.size(); ++i){
			array[i].EntryType = EMPTY;
		}
		currentSize = 0;
	}

	bool insert( const HashedObj & x ){ // returns true if the item is inserted. Do no insert doubles
		if (!contains(x)){
			HashEntry temp(x, ACTIVE);

			
			auto hashed = hf(x);
			if (array[hashed].info = EMPTY || DELETED){
				
			}
			// how the mole do you insert?
			return true;
		}
		return false;
	}

	bool remove( const HashedObj & x){

	}

	enum EntryType { ACTIVE, EMPTY, DELETED };
private:
	struct HashEntry{
		HashedObj element;
		EntryType info;
		HashEntry( const HashedObj & e = HashedObj(), EntryType i = EMPTY )
			: element( e), info(i) {}
	};
	vector<HashEntry> array;
	int currentSize;

	// Implement this:
	void rehash(){
		HashTable biggerHashTable(array.size() * 2 + 1);
		for (int i = 0; i < array.size(); ++i){
			if (array[i].info != EMPTY){
				biggerHashTable.insert(array[i]);
			}
		}
		currentSize = biggerHashTable.currentSize;
		array = biggerHashTable.array;
	}
};



int main(){
	return 42;
}