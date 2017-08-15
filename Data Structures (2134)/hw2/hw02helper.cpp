#include <math.h>
#include <iostream>

using namespace std;
class IntArray{
    public:
        IntArray(int n = 0): size(n), array(new int[n]){}

        // Copy Constructor
        IntArray(const IntArray& rhs);

        // Move Constructor
        IntArray(IntArray&& rhs);

        // Destructor
        ~IntArray(){
            delete [] array;
        }

        // Copy assignment
        IntArray& operator=(const IntArray& rhs){
            if (this != &rhs){
                delete [] array;
                size = rhs.size;
                array = new int[size];
                for (int i = 0; i < size; ++i){
                    array[i] = rhs.array[i];
                }
            }
            return *this;
        }

        // Move assignment
        IntArray& operator=(IntArray&& rhs){
            int* temp = new int[rhs.size];
            for (int i = 0; i < size; ++i){
                temp[i] = rhs.array[i];
            }
            array = rhs.array;
            rhs.array = temp;
            return *this;
        }

        void put(int i, int value){
            if(0 <= i && i < size){
                *(array + i) = value;
            }
        }

        int get(int i){
            if(0 <= i && i < size){
                return *(array + i);
            }
            return 0;
        }

        int* getArray(){
            return array;
        }

    private:
        int * array;
        int size; 
};

IntArray::IntArray(const IntArray& rhs): size(rhs.size), array(new int[rhs.size]){
    cout << "this is coming up" << endl;
    for (int i = 0; i < size; ++i){
        array[i] = rhs.array[i];
    }
} 

IntArray::IntArray(IntArray&& rhs): size(rhs.size), array(new int[rhs.size]){ 
    cout << "this should be coming up" << endl;
    array = rhs.array;
    // for (int i = 0; i < size; ++i){
    //     array[i] = rhs.array[i];
    // }
    rhs.array = nullptr;
} 



int main(){
    cout << "Testing the IntArray Class" << endl;
    cout << "creating an instance of an array" << endl;
    int size = 12;
    IntArray arr(size);
    int TheAnswer = 42;
    int NotTheAnswer = 83;
    cout << "values are being inserted" << endl;
    arr.put(0, TheAnswer);
    arr.put(1, TheAnswer);
    arr.put(11, TheAnswer);
    arr.put(10, NotTheAnswer);
    // cout << "copy Constructor" << endl;
    // IntArray copyArray(arr);
    // cout << "Changing the value of index 0 in one array should NOT impact the other" << endl;
    // int randomValue = 32;
    // int ind1 = 0;
    // copyArray.put(ind1, randomValue);
    // cout << "Changing the value of any random index in one array should NOT impact the other" << endl;
    // int otherRandomValue = rand() % size;
    // int ind2 = 5;
    // copyArray.put(ind2, otherRandomValue);
    // cout << "The Copy Assignment Constructor is invoked" << endl;
    // IntArray copyArray(15);
    // int val1 = 12;
    // int val2 = 14;
    // int val3 = 28;
    // copyArray.put(0, val1);
    // copyArray.put(1, val2);
    // copyArray.put(2, val3);
    // copyArray = arr;





    cout << "The Move Constructor is invoked" << endl;
    IntArray moveArray(move(arr)); // this is running the copy constructor not the move constructor....
    cout << "the old array should point to nullptr" << endl;
    if(arr.getArray() == nullptr){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    cout << "The new array should not be pointing to a nullptr" << endl;
    if(moveArray.getArray() != nullptr){
        cout << "test 2 true" << endl;
    }
    else{
        cout << "test 2 false " << endl;
    }
    
    // cout << "The Move Assignment Operator is invoked" << endl;
    // IntArray oneArray(15);
    // int* arr1Loc = oneArray.getArray();
    // int* arrLoc = arr.getArray();
    // oneArray = move(arr);
    // cout << "The new array should not be pointing to old, but to arr's" << endl;
    // if (oneArray.getArray() != arr1Loc)
    // {
    //     cout << "good say more" << endl;
    // }
    // else{
    //     cout << "failure" << endl;
    // }
    // if (oneArray.getArray() == arrLoc)
    // {
    //     cout << "Just a few more" << endl;
    // }
    // else{
    //     cout << "lots more to go" << endl;
    // }

    // cout << "The array of the original should be nullptr" << endl;
    // if(arr.getArray() == nullptr){
    //     cout << "done" << endl;
    // }
    // else{
    //     cout << "not done" << endl;
    // }


    return 42;
}




// // // Tests everything but the destructor
// // SCENARIO("Testing the IntArray Class"){
// //     GIVEN("An instance of IntArray"){
// //         int size = 12;
// //         IntArray arr(size);
// //         WHEN("Values are inserted"){
// //             int TheAnswer = 42;
// //             int NotTheAnswer = 83;
// //             arr.put(0, TheAnswer);
// //             arr.put(1, TheAnswer);
// //             arr.put(11, TheAnswer);
// //             arr.put(10, NotTheAnswer);
// //             THEN("The values should be retrievable from the array"){
// //                 REQUIRE(arr.get(0) == TheAnswer);
// //                 REQUIRE(arr.get(1) == TheAnswer);
// //                 REQUIRE(arr.get(11) == TheAnswer);
// //                 REQUIRE(arr.get(10) == NotTheAnswer);
// //             }
// //             THEN("A value that is out of bounds is attempted to be accessed should return zero"){
// //                 int OutOfBounds = 100;
// //                 REQUIRE(arr.get(OutOfBounds) == 0);
// //             }
// //         }
//         // WHEN("The Copy Constructor is invoked"){
//         //     IntArray copyArray(arr);
//         //     THEN("Changing the value of index 0 in one array should NOT impact the other"){
//         //         int randomValue = 32;
//         //         int ind1 = 0;
//         //         copyArray.put(ind1, randomValue);
//         //         REQUIRE(copyArray.get(ind1) == randomValue);
//         //         REQUIRE(arr.get(ind1) != randomValue);
//         //     }
//         //     THEN("Changing the value of any random index in one array should NOT impact the other"){
//         //         int otherRandomValue = rand() % size;
//         //         int ind2 = 5;
//         //         copyArray.put(ind2, otherRandomValue);
//         //         REQUIRE(copyArray.get(ind2) == otherRandomValue);
//         //         REQUIRE(arr.get(ind2) != otherRandomValue);           
//         //     }
//         // }
//         // WHEN("The Copy Assignment Constructor is invoked"){
//         //     IntArray copyArray(15);
//         //     int val1 = 12;
//         //     int val2 = 14;
//         //     int val3 = 28;
//         //     copyArray.put(0, val1);
//         //     copyArray.put(1, val2);
//         //     copyArray.put(2, val3);
//         //     copyArray = arr;
//         //     THEN("The values of copyArray should be the values of arr"){
//         //         REQUIRE(copyArray.get(0) == arr.get(0));
//         //         REQUIRE(copyArray.get(1) == arr.get(1));
//         //         REQUIRE(copyArray.get(2) == arr.get(2));
//         //     }
//         //     THEN("The values though should be at different locations in memory"){
//         //         REQUIRE(copyArray.getArray() != arr.getArray()); 
//         //     }
//         // }
//         WHEN("The Move Constructor is invoked"){ // this is the one that is not working!!!
//             IntArray moveArray(move(arr));

//             THEN("the old array should point to nullptr"){
//                 bool isGood = false;
//                 if(arr.getArray() == nullptr){
//                     isGood = true;
//                 }
//                 REQUIRE(isGood);
//             }
//             THEN("The new array should not be pointing to a nullptr"){
//                 bool isGood = false;
//                 if(moveArray.getArray() != nullptr){
//                     isGood = true; 
//                 }
//                 REQUIRE(isGood);           
//             }
//         }
//         WHEN("The Move Assignment Operator is invoked"){
//             IntArray oneArray(15);
//             int* arr1Loc = oneArray.getArray();
//             int* arrLoc = arr.getArray();
//             oneArray = move(arr);
//             THEN("The new array should not be pointing to old, but to arr's"){
//                 REQUIRE(oneArray.getArray() != arr1Loc);
//                 REQUIRE(oneArray.getArray() == arrLoc);           
//             }

//             THEN("The array of the original should be nullptr"){
//                 bool isGood = false;
//                 if(arr.getArray() == nullptr){
//                     isGood = true; 
//                 }
//                 REQUIRE(isGood);           
//             }
//         }
//     }
// }
