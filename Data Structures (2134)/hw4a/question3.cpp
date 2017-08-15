#define CATCH_CONFIG_MAIN

#include <vector>
#include <iostream>
#include "catch.hpp"

using namespace std; 

// Insert Recursive Function
int mySum(vector<int>::iterator left, vector<int>::iterator right){
	int result = 0;
	if(left == right){
		result = *left;
	}
	else{
		int mid = (right - left)/2;
		int leftside = mySum(left, left+mid);
		int rightside = mySum(left+mid+1, right);
		result = leftside + rightside;
	}
	return result;
}

//Insert driver function here
int sumVector(const vector<int> & a){
	int result = 0;
	if (a.size() != 1){
		vector<int> temp = a;
		vector<int>::iterator first = temp.begin();
		vector<int>::iterator last = temp.end();
		result = mySum(first, last-1);
	}
	else{
		result = a[0];
	}
	return result;

}

// int main(){
// 	vector<int> vi;
// 	vi.push_back(3);
// 	vi.push_back(-2);
// 	vi.push_back(1);
// 	cout << sumVector(vi) << endl;
// 	return 42;
// }

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
