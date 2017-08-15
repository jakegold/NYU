#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <vector>
#include <string>
#include <iostream>

using namespace std;


template <class Comparable, class RandItr>
void mergeSort(vector<Comparable> & tmpArray, RandItr left, RandItr  right) {
	if (left < right)
	{
	
		RandItr center = left + (right - left) / 2;
		mergeSort(tmpArray, left, center);
		mergeSort(tmpArray, center + 1, right);
		sort(left, center);
		sort(center + 1, right);
		merge(left, center, center + 1, right, tmpArray.begin());
	}

}
template <class RandItr>
void mergeSort(RandItr start, RandItr end)
{
	int sz = end - start; // or use auto sz = end-start;
	typedef typename iterator_traits< RandItr >::value_type Object; 
	vector<Object> tmp(sz);
	mergeSort(tmp, start, end);
	for (int i = 0; i < sz; i++) {
		(*(start + i)) = tmp[i];
	}
}






SCENARIO("TESTING MERGESORT") {
	GIVEN("An unsorted vector of integers") {
		vector<int> randomVec = { 9,0,2,1,0,1,2,3,4,5,6,7,8,9 };
		WHEN("Mergsort is used to sort the vector from least to greatest") {
			size_t numElements = randomVec.size();
			mergeSort(randomVec.begin(), randomVec.end());
			THEN("The number of elements should remain the same") {
				REQUIRE(numElements == randomVec.size());
			}
			THEN("The vector is sorted") {
				for (int x = 1; x <= randomVec.size(); ++x) {
					REQUIRE(randomVec[x - 1] <= randomVec[x]);
				}
			}
		}
	}
}