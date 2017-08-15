/*
  Vector Class
  Demonstrates:
     Good example of copy control
     Dynamic arrays and pointer arithmetic
     Square bracket operator
     Implementation of an important data structure
  Sec 
 */
#include <iostream>
using namespace std;

class Vector {
public:
//    constructor
    Vector() : theSize(0), theCapacity(0), data(nullptr) {
        cerr << "vector()" << endl;
    }
    
//    constructor that makes a vector of certain size
    explicit Vector(size_t mySize)
    : theCapacity(mySize), theSize(mySize), data(new int[mySize]){
        cerr << " making an array of size " << mySize << endl;
    }

    // Copy control
    
//   Destructor
    ~Vector(){
        cerr << "destructor" << endl;
        delete [] data;
    }
    
//    copy constructor
    Vector(const Vector& rhs)
    : theSize(rhs.theSize), theCapacity(rhs.theCapacity), data(new int[rhs.theCapacity])
    {
        cerr << "copy constructor" << endl;
        for (size_t i = 0; i < theSize; ++i){
            data[i] = rhs.data[i];
        }
    }
    
//    overwritting the = operator
    Vector& operator=(const Vector& rhs){
        if(this != &rhs){
            delete [] data;
            theCapacity = rhs.theCapacity;
            theSize = rhs.theSize;
            data = new int[rhs.theCapacity];
            for (size_t i = 0; i < theSize; ++i){
                data[i] = rhs.data[i];
            }
        }
        return *this;
    }

//    push back
    void push_back(int val){
        if(theSize == theCapacity){
//          increase the capacity
            int newCapacity = 2*theCapacity + 1;
            int* newData = new int[newCapacity];
            for(size_t i = 0; i < theSize; ++i){
                newData[i] = data[i];
            }
            delete [] data;
            data = newData;
            theCapacity = newCapacity;
        }
        data[theSize] = val;
        ++theSize;
        
    }
    
//    get the capacity
    size_t capacity() const{
        return theCapacity;
    }
    
//    get the size
    size_t size() const{
        return theSize;
    }
//    clear
    void clear() { theSize = 0; }
    
//    pop back
    void pop_back() {
//        if (theSize > 0) --theSize;
        --theSize;
    }

//  Square brackets?
    int operator[](size_t index) const {return data[index]; }
    int& operator[] (size_t index) {return data[index]; }
    
private:
    size_t theSize;
    size_t theCapacity;
    int* data;
};

void simpleFunc(){
    cerr << "simplefunc()" << endl;
    Vector aVector;
    cerr << "done with simplefunc()" << endl;
}


int main() {

    Vector v;  // Not templated.  Our Vector class can only hold ints.
     v.push_back(17);
     v.push_back(42);
     v.push_back(6);
     v.push_back(28);

    // Vector v2(v);
    // Vector v3;
    // v3 = v;

    // for (size_t i = 0; i < v.size(); ++i)
    //     cout << v[i] << endl;
    // v[0] = 100;

}

