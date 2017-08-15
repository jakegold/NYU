// Jake Goldstein HW 11 Q1
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

// Question 1
template<class Comparable>
void print_kth_largest(const vector<Comparable> & a, int k){
    // Create a priotiry queue of the whole vector
    priority_queue<Comparable> tempPQ;
    for (int i = 0; i < a.size(); ++i){
        tempPQ.push(a[i]);
    }
    // Add the top K elements into a queue
    queue<Comparable> printMe;
    for (int i = 0; i < k; ++i){
        printMe.push(tempPQ.top());
        tempPQ.pop();
    }
    // Print the queue
    while(!printMe.empty()){
        cout << printMe.front() << ", ";
        printMe.pop();
    }
    cout << endl;
}



// int main(){
//     cout << "testing on ints" << endl;
//     vector<int> nums;
//     nums.push_back(1234);
//     nums.push_back(12);
//     for (int i = 0; i < 24; ++i){
//         nums.push_back(i);
//     }
//     nums.push_back(100);
//     nums.push_back(34);
//     print_kth_largest(nums, 6);

//     cout << "testing on chars" << endl;
//     vector<char> letters;
//     letters.push_back('q');
//     letters.push_back('w');
//     letters.push_back('e');
//     letters.push_back('r');
//     letters.push_back('t');
//     letters.push_back('y');
//     letters.push_back('u');
//     letters.push_back('i');
//     letters.push_back('o');
//     letters.push_back('p');
//     print_kth_largest(letters, 3);


    
// }
//Done for the unit test
// toVec reads a stringstream and parses into a vector of tp
template<class tp>
vector<tp> toVec(stringstream& strm){ 
    tp i;
    vector<tp> vec;
    while(strm >> i){
        vec.push_back(i); 
        if(strm.peek() == ' ' || strm.peek() == '\n' || strm.peek() == ','){
            strm.ignore();
        }
    }
    return vec;
}

SCENARIO("Testing kth_largest"){
    stringstream buffer;
    struct cout_redirect { 
            cout_redirect( streambuf * new_buffer ) : old( cout.rdbuf( new_buffer ) ) {}
            ~cout_redirect( ) {
                cout.rdbuf( old );
            }
            private:
            streambuf * old;
    };
    GIVEN("A vector of integers"){
        vector<int> testVec = {5,1,2,4,3};
        WHEN("print_kth_largest is called"){
            cout_redirect redirect(buffer.rdbuf());
            print_kth_largest(testVec, 2);
            vector<int> resVec = toVec<int>(buffer);
            THEN("5 and 4 should be printed"){
                REQUIRE(resVec.size() == 2);
                REQUIRE(resVec[0] == 5);
                REQUIRE(resVec[1] == 4);
            }
        }
    }
}