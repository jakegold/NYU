#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>

using namespace std;

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