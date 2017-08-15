// Jake Goldstein HW 05 Programming questions 3-5
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace std;

// Question 3
template <class itr>
void mergeSort(itr temp, itr first, itr end){
	cout << endl;
	if (first < end){
		auto midNum = ((end - first) / 2);
		itr mid = first + midNum;
		auto temp2 = temp + midNum;
		if(first != mid){
			mergeSort(temp, first, mid);
			mergeSort(temp2, mid, end);
		}
		merge(first, mid, mid, end, temp);
		for (auto i = first; i != end; ++i, ++temp){
			swap(*i, *temp);
		}
		cout << endl;
	}
}


template <class RandItr>
void mergeSort( RandItr start, RandItr end ){
	int sz = end - start; // or use auto sz = end-start;
	typedef typename iterator_traits< RandItr >::value_type Object; //Xcode
	// typedef iterator_traits< RandItr >::value_type Object; //Other compilers
	// Don’t worry about this line of code
	vector<Object> tmp( sz );
	mergeSort( tmp.begin(), start, end );
	for (auto i = start; i != end; ++i){
		cout << *i << ", ";
	}
	cout << endl;
}

class student{
private:
	string name;
	double gpa;
public:
	student (const string & name, double gpa): name(name), gpa(gpa){}
	string get_name() const { return name; }
	double get_gpa() const { return gpa; }
};

// Question 4
class meFirst{
public:
	meFirst(string me): me(me){};
	bool operator()(const student& first, const student& second) const{
		if (second.get_name() != me && first.get_name() != me){
			return first.get_name() < second.get_name();
		}
		else{
			return (first.get_name() == me);
		}	
	}
private:
	string me;
};



// Question 5
void sortMe(vector<bool>& myVec){
	int low = 0;
	int high = myVec.size() -1;
	int mid = (low+high)/2;
	bool piv = myVec[mid];
	swap(myVec[high], myVec[mid]);
	int i = low;
	int j = high - 1;
	for(;;){
		while(myVec[i] < piv) i++;
		while(j > i && piv < myVec[j]) --j;
		if (i < j){
			swap(myVec[i++], myVec[j--]);
		}
		else{
			break;
		}
	}
	swap(myVec[high], myVec[i]);
}

SCENARIO("TESTING MERGESORT"){
    GIVEN("An unsorted vector of integers"){
        vector<int> randomVec = {9,0,2,1,0,1,2,3,4,5,6,7,8,9};
        WHEN("Mergsort is used to sort the vector from least to greatest"){
            size_t numElements = randomVec.size();
            mergeSort(randomVec.begin(), randomVec.end());
            THEN("The number of elements should remain the same"){
                REQUIRE(numElements == randomVec.size()); 
            }
            THEN("The vector is sorted"){
                for(int x = 1; x < randomVec.size(); ++x){
                    REQUIRE(randomVec[x-1] <= randomVec[x]);
                }
            }
        }
    }
}

SCENARIO("TESTING MEFIRST"){
    GIVEN("A functor meFirst"){
        string priority = "Saitama";
        meFirst m(priority);
        WHEN("students are created"){
            student Saitama_Sensei(priority, 2.0);
            student Genos("Genos", 4.0);
            student Bang("Bang", 3.8);
            THEN("When the me matches, priority student goes first"){
                REQUIRE(m(Saitama_Sensei, Genos)); 
            }
            THEN("When two students who do not match, alphabetically first goes first"){
                REQUIRE(m(Genos,Bang) == false);
                REQUIRE(m(Bang, Genos) == true);
            }
        }
    }
}

SCENARIO("Order the Trues and Falses"){
    GIVEN("A vector of boolean values (true/false)"){
        vector<bool> vecBool = {false, true, false, true, true, true, false, false};
        WHEN("Sorted"){
        	sortMe(vecBool);
            THEN("All falses should come before true"){
                bool lastSeen = false; 
                for(int x = 0; x < vecBool.size(); ++x){
                    if(lastSeen == true){
                        REQUIRE(vecBool[x] == true); 
                    }
                    lastSeen = vecBool[x];
                } 
            }
        } 
    }
}
