// Jake Goldstein HW 01

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

class timer {
public:
    timer() : start(clock()) {}
    double elapsed() { return ( clock() - start ) / CLOCKS_PER_SEC; }
    void reset() { start = clock(); }
private:
    double start;
};


// Use the following code from Weiss’ book ”Data Structures and Algorithm Analysis in C++” (4th edition) http://users.cis.fiu.edu/~weiss/dsaa_c++4/code/MaxSumTest.cpp

// Cubic maximum contiguous subsequence sum algorithm.
int maxSubSum1(const vector<int>& a);

// Quadratic maximum contiguous subsequence sum algorithm.
int maxSubSum2(const vector<int>& a);

// Linear-time maximum contiguous subsequence sum algorithm.
int maxSubSum4(const vector<int>& a);

/* 
** Fills a vector of ints with n random numbers between -1000 and 1000.
** After the vector is filled it multiplies n by 2 
*/
void fillVector(vector<int>& myVec, int& n);

// The following functions are straight from the HW, question 2
void twoB(const vector<int>& n);

void twoC(const vector<int>& n);

void twoD(const vector<int>& n);

void twoE(const vector<int>& n);

// Runs all of the maxSubSums and prints their times
void questionOne(const vector<int>& myVec);

// Runs the rest of the functions and prints their times
void questionTwo(const vector<int>& myVec);


int main(){
    // Make sure that enough sig figs are shown
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(6);

    // Declare an int to fill my vectors with
    int n = 128;

    // Declare and fill all the vectors
    vector<int> seven;
    fillVector(seven, n);

    vector<int> eight;
    fillVector(eight, n);

    vector<int> nine;
    fillVector(nine, n);

    vector<int> ten;
    fillVector(ten, n);

    vector<int> eleven;
    fillVector(eleven, n);

    vector<int> twelve;
    fillVector(twelve, n);


    cout << "Question 1: " << endl;
    cout << endl;
    questionOne(seven);
    questionOne(eight);
    questionOne(nine);
    questionOne(ten);
    questionOne(eleven);
    questionOne(twelve);

    cout << "Question 2: " << endl;
    cout << endl;
    questionTwo(eight);
    questionTwo(nine);
    questionTwo(ten);
    questionTwo(eleven);
    questionTwo(twelve);
    

    return 0;
}

int maxSubSum1(const vector<int>& a){
    int maxSum = 0;

    for( int i = 0; i < a.size( ); ++i )
        for( int j = i; j < a.size( ); ++j )
        {
            int thisSum = 0;

            for( int k = i; k <= j; ++k )
                thisSum += a[ k ];

            if( thisSum > maxSum )
                maxSum   = thisSum;
        }

    return maxSum;
}

int maxSubSum2(const vector<int>& a){
    int maxSum = 0;

    for( int i = 0; i < a.size( ); ++i )
    {
        int thisSum = 0;
        for( int j = i; j < a.size( ); ++j )
        {
            thisSum += a[ j ];

            if( thisSum > maxSum )
                maxSum = thisSum;
        }
    }

    return maxSum;
}

int maxSubSum4(const vector<int>& a){
    int maxSum = 0, thisSum = 0;

    for( int j = 0; j < a.size( ); ++j )
    {
        thisSum += a[ j ];

        if( thisSum > maxSum )
            maxSum = thisSum;
        else if( thisSum < 0 )
            thisSum = 0;
    }

    return maxSum;
}

void fillVector(vector<int> & myVec, int& n){
    for (int i = 0; i < n; ++i){
        int x = (rand() % 2001) - 1000;
        myVec.push_back(x);
    }
    n *=2;
}

void twoB(const vector<int>& myVec){
    int n = myVec.size();
    int sum = 0;
    for (int i = 0; i < n; i++){
        ++sum;
    }
}

void twoC(const vector<int>& myVec){
    int n = myVec.size();
    int sum = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; ++j){
            ++sum;
        }
    }
}


void twoD(const vector<int>& myVec){
    int n = myVec.size();
    int sum = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; ++j){
            ++sum;
        }
    }
}

void twoE(const vector<int>& myVec){
    int n = myVec.size();
    int sum = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; ++j){
            for(int k = 0; k < n; ++k){
                ++sum;
            }
        }
    }
}

void questionOne(const vector<int>& myVec){
    cout << "######";
    double first, second, fourth;
    timer t;
    maxSubSum1(myVec);
    first = t.elapsed();

    t.reset();
    maxSubSum2(myVec);
    second = t.elapsed();
    cout << "######";

    t.reset();
    maxSubSum4(myVec);
    fourth = t.elapsed();
    cout << "######" << endl;

    cout << "Vector of size " << myVec.size() << ":" << endl;
    cout << "First: " << first << endl;
    cout << "Second: " << second << endl;
    cout << "Fourth: " << fourth << endl;
}

void questionTwo(const vector<int>& myVec){
    cout << "####";
    double b, c, d, e;
    timer t;
    twoB(myVec);
    b = t.elapsed();

    t.reset();
    twoC(myVec);
    c = t.elapsed();
    cout << "####";

    t.reset();
    twoD(myVec);
    d = t.elapsed();
    cout << "####";

    t.reset();
    twoE(myVec);
    e = t.elapsed();
    cout << "####" << endl;

    cout << "Vector of size " << myVec.size() << ":" << endl;
    cout << "B: " << b << endl;
    cout << "C: " << c << endl;
    cout << "D: " << d << endl;
    cout << "E: " << e << endl;
}