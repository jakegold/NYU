// Jake Goldstein Programming Question 1
#define CATCH_CONFIG_MAIN
#include <istream>
#include "Tokenizer.cpp"
#include "catch.hpp"

using namespace std;

// Code from Weiss
// Symbol is the class that will be placed on the Stack.
struct Symbol
{
    char token;
    int  theLine;

};


class Balance
{
public:
    Balance( istream & is ):tok( is ),errors( 0 ){}
    int checkBalance(); // returns the number of mismatched parenthesis
private:
    Tokenizer tok;
    int errors;
    void checkMatch( const Symbol & oParen, const Symbol & cParen );   
};

int Balance::checkBalance(){
    stack<Symbol> myChars;
    Symbol paren;
    while(true){
        paren.token = tok.getNextOpenClose();
        paren.theLine = tok.getLineNumber();
        // Token will be '\0' at the end of the file
        if (paren.token == '\0'){
            break;
        }
        // If the token is an opening one put it on the stack
        else if (paren.token == '(' || paren.token == '[' || paren.token == '{'){
            myChars.push(paren);
        }
        // If it is a closing one
        else if(paren.token == ')'|| paren.token == ']' || paren.token == '}'){
            // If the size is 0 error
            if (myChars.size() == 0){
                ++errors;
                cerr << "Error: On line " << paren.theLine << " there is a ";
                cerr << paren.token << " , but no opening one of those." << endl;
            }
            // If not check to see if it matches and pop the top one off
            else{
                Symbol topOfStack = myChars.top();
                checkMatch(topOfStack, paren);
                myChars.pop();
            }
        }
    }
    // If at the end of the file the stack still has elements add that many errors
    while (myChars.size() > 0){
        ++errors;
        cerr << "Error: On line " << myChars.top().theLine;
        cerr << " there is no closing parenthesis or brace for ";
        cerr << myChars.top().token << endl;
        myChars.pop();
    }
    return errors;
}

void Balance::checkMatch(const Symbol & oParen, const Symbol & cParen ){
    // Note that this if statment is on three lines
    // If the tokens are corresponding opening and closing
    if((oParen.token == '(' && cParen.token == ')') 
        || (oParen.token == '[' && cParen.token == ']') 
        || (oParen.token == '{' && cParen.token == '}')){
        return;
    }
    // If they tokens are different
    else{
        ++errors;
        cerr << "Error: On line " << cParen.theLine;
        cerr << " there is no closing " << oParen.token << '.' << endl;  
    }
}

SCENARIO("Checking your Balancer"){
    GIVEN("a test file test.cc with 2 known issues taken in as a ifstream"){
        ifstream ifs("test_cases/test.cc");
        if (!ifs) cerr << "Failure to open file" << endl;
        cerr << "test.cc" << endl;
        WHEN("Given a balancer"){
            Balance b(ifs); 
            THEN("CheckBalance should return 1"){
                REQUIRE(b.checkBalance() == 1);
            }
        }
        ifs.close();
    } 
    GIVEN("a test file test2.cc with 3 known issues taken in as a ifstream"){
        ifstream ifs("test_cases/test2.cc");
        if(!ifs) cerr << "Failure to open file" << endl;
        cerr << "test2.cc" << endl;
        WHEN("Given a balancer"){
            Balance b(ifs);
            THEN("Check balance should return 2"){
                REQUIRE(b.checkBalance() == 2); 
            }
        }
    }
    GIVEN("a test file test3.cc with 0 known issues taken in as a ifstream"){
        ifstream ifs("test_cases/test3.cc");
        if(!ifs) cerr << "Failure to open file" << endl;
        cerr << "test3.cc" << endl;
        WHEN("Given a balancer"){
            Balance b(ifs);
            THEN("Check balance should return 0"){
                REQUIRE(b.checkBalance() == 0); 
            }
        }
    }
}


