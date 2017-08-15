// Jake Goldstein HW 04A Programming questions 1-3
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>

using namespace std;

template <typename Object>
class Vector
{
public:
    explicit Vector(int initSize = 0)
        : theSize{ initSize }, theCapacity{ initSize + SPARE_CAPACITY }
    {
        objects = new Object[theCapacity];
    }

    Vector(const Vector & rhs)
        : theSize{ rhs.theSize }, theCapacity{ rhs.theCapacity }, objects{ nullptr }
    {
        objects = new Object[theCapacity];
        for (int k = 0; k < theSize; ++k)
            objects[k] = rhs.objects[k];
    }

    Vector & operator= (const Vector & rhs)
    {
        Vector copy = rhs;
        std::swap(*this, copy);
        return *this;
    }

    ~Vector()
    {
        delete[] objects;
    }

    Vector(Vector && rhs)
        : theSize{ rhs.theSize }, theCapacity{ rhs.theCapacity }, objects{ rhs.objects }
    {
        rhs.objects = nullptr;
        rhs.theSize = 0;
        rhs.theCapacity = 0;
    }

    Vector & operator= (Vector && rhs)
    {
        std::swap(theSize, rhs.theSize);
        std::swap(theCapacity, rhs.theCapacity);
        std::swap(objects, rhs.objects);

        return *this;
    }

    bool empty() const
    {
        return size() == 0;
    }
    int size() const
    {
        return theSize;
    }
    int capacity() const
    {
        return theCapacity;
    }

    Object & operator[](int index)
    {
        return objects[index];
    }

    const Object & operator[](int index) const
    {
        return objects[index];
    }

    void resize(int newSize)
    {
        if (newSize > theCapacity)
            reserve(newSize * 2);
        theSize = newSize;
    }

    void reserve(int newCapacity)
    {
        if (newCapacity < theSize)
            return;

        Object *newArray = new Object[newCapacity];
        for (int k = 0; k < theSize; ++k)
            newArray[k] = std::move(objects[k]);

        theCapacity = newCapacity;
        std::swap(objects, newArray);
        delete[] newArray;
    }

    // Stacky stuff
    void push_back(const Object & x)
    {
        if (theSize == theCapacity)
            reserve(2 * theCapacity + 1);
        objects[theSize++] = x;
    }
    // Stacky stuff
    void push_back(Object && x)
    {
        if (theSize == theCapacity)
            reserve(2 * theCapacity + 1);
        objects[theSize++] = std::move(x);
    }


    // Iterator stuff: not bounds checked
    typedef Object * iterator;
    typedef const Object * const_iterator;

    iterator begin()
    {
        return &objects[0];
    }
    const_iterator begin() const
    {
        return &objects[0];
    }
    iterator end()
    {
        return &objects[size()];
    }
    const_iterator end() const
    {
        return &objects[size()];
    }

    static const int SPARE_CAPACITY = 2;

    // Q1
    // My erase method
    iterator erase(iterator vItr){
        // Create a temp vector one size smaller
        Vector<Object> temp(theCapacity-1);
        // Of the vector being called on, find the first and last elements for a loop
        Vector<Object>::iterator first = this->begin();
        Vector<Object>::iterator last = this->end();
        // Loop thorugh the temp vector, and the vector being called on
        for (int i = 0; i < temp.size(); ++i, first++){
            // If the item in not the item being erased
            if(first != vItr){
                // Move over the item
                temp[i] = move(*first);
            }
            // If it is the item being erased
            else{
                // Move back on spot on the temp
                i--;
            }
        }
        // Swap the two objects [] on the heaps
        swap(objects, temp.objects);
        theSize--;
        theCapacity--;
        return vItr;
    }

private:
    int theSize;
    int theCapacity;
    Object * objects;
};

// Q2
// My sumDigits recursive function
int sumDigits(int myNum){
    // Check for negativeness, if true, make positive
    if (myNum < 0){
        myNum = myNum *-1;
    }
    int result = 0;
    // If myNum is only a single digit
    if (myNum < 10){
        result = myNum;
    }
    // Add up the last digit and the rest of the digits besides the last one
    else{
        result = result + myNum%10 + sumDigits(myNum/10);
    }
    return result;
}

// Q3
// Insert Recursive Function
int mySum(vector<int>::iterator left, vector<int>::iterator right){
    int result = 0;
    // Base case
    if(left == right){
        result = *left;
    }
    else{
        int mid = (right - left)/2;
        // Recursive call on the left side
        int leftside = mySum(left, left+mid);
        // Recursive call on the right side
        int rightside = mySum(left+mid+1, right);
        result = leftside + rightside;
    }
    return result;
}

//Insert driver function here
int sumVector(const vector<int> & a){
    int result = 0;
    // If there are more than one elements in the vector
    if (a.size() != 1){
        vector<int> temp = a;
        vector<int>::iterator first = temp.begin();
        vector<int>::iterator last = temp.end();
        // Call the recursive funciton on relavent indices
        result = mySum(first, last-1);
    }
    // If there is only one element
    else{
        result = a[0];
    }
    return result;

}


SCENARIO("Testing Question 1") {
    GIVEN("A vector of 1 element") {
        Vector<int> vOne; 
        vOne.push_back(1); 
        Vector<int>::iterator vOneIterator1 = vOne.end();
        WHEN("The element is erased") {
            Vector<int>::iterator catchItr = vOne.erase(vOne.begin()); 
            THEN("The size should be zero") {
                REQUIRE(vOne.size() == 0);
            }
            THEN("end() should not return the same iterator") {
                REQUIRE(vOne.end() != vOneIterator1);
            }
        }
    }
    GIVEN("A vector of some elements") {
        Vector<int> vSome; 
        vSome.push_back(1); 
        vSome.push_back(2); 
        vSome.push_back(3); 
        int beforeSize = vSome.size(); 
        Vector<int>::iterator beforeErase = vSome.end(); 
        WHEN("The second element is erased") {
            Vector<int>::iterator catchItr = vSome.erase(vSome.begin() + 1); 
            THEN("Make sure the size is decreased by 1") {
                REQUIRE(vSome.size() == beforeSize - 1); 
            }
            THEN("Make sure the order of element is correct") {
                REQUIRE(vSome[0] == 1);
                REQUIRE(vSome[1] == 3); 
                
            }
            THEN("Make sure the last element has been erased") {
                REQUIRE(beforeErase != vSome.end()); 
            }
        }
    }
}

SCENARIO("Testing Question 2") {
    GIVEN("A one digit positive integer ") {
        WHEN("sumDigits is called") {
            int sum = sumDigits(5);
            THEN("theSum should be ") {
                REQUIRE(sum == 5);
            }
        }
    }
    GIVEN("A one digit negative integer") {
        WHEN("sumDigits is called") {
            int sum = sumDigits(-5);
            THEN("theSum should be ") {
                REQUIRE(sum == 5);
            }
        }
    }
    GIVEN("A positive integer ") {
        WHEN("sumDigits is called") {
            int sum = sumDigits(363);
            THEN("theSum should be ") {
                REQUIRE(sum == 12);
            }
        }
    }
    GIVEN("A negative integer") {
        WHEN("sumDigits is called") {
            int sum = sumDigits(-363);
            THEN("theSum should be ") {
                REQUIRE(sum == 12);
            }
        }
    }
}

SCENARIO("Testing sumVector") {
    GIVEN("A vector with just one element") {
        vector<int> singleElement = { 1 }; //Note that this is the STL vector, so we can initialize like this
        WHEN("The sumVector function is called") {
            int sum = sumVector(singleElement);
            THEN("The correct sume is returned") {
                REQUIRE(sum == 1); //testing base case
            }
        }
    }
    GIVEN("A vector with odd number of integers ") {
        vector<int> vOdd = { 1,2,3 };
        WHEN("sumVector function is called ") {
            int recSum = sumVector(vOdd);

            vector<int>::iterator itrStart = vOdd.begin();
            vector<int>::iterator itrEnd = vOdd.end();

            int sizeVector = vOdd.size(); 

            THEN("vector stays same after the function call") {
                REQUIRE(itrStart == vOdd.begin());
                REQUIRE(itrEnd == vOdd.end());
            }
            THEN("The size of the vector doesn't change") {
                REQUIRE(sizeVector == vOdd.size());
            }
            THEN("It sums up properly") {
                REQUIRE(recSum ==6);
            }
        }
        GIVEN("A vector with even number of integers ") {
            vector<int> vEven = { 1,2,3,10 };
            
            vector<int>::iterator itrStart = vEven.begin();
            vector<int>::iterator itrEnd = vEven.end();

            int sizeVector = vEven.size();

            WHEN("sumVector function is called ") {

                int recSum = sumVector(vEven);
        
                THEN("vector stays same after the function call") {
                    REQUIRE(itrStart == vEven.begin());
                    REQUIRE(itrEnd == vEven.end());
                }
                THEN("The size of the vector doesn't change") {
                    REQUIRE(sizeVector == vEven.size());
                }
                THEN("It sums up properly") {
                    REQUIRE(recSum == 16);
                }
            }
        }
    }
}
