#include <iostream>
#include <vector>
#include <stack>

using namespace std;

enum TokenType { EOL, VALUE, OPAREN, CPAREN, EXP, MULT, DIV, PLUS, MINUS };
// PREC_TABLE matches order of Token enumeration
struct Precedence
{
int inputSymbol;
int topOfStack;
};
// and
vector<Precedence> PREC_TABLE =
{
{ 0, -1 }, { 0, 0 }, // EOL, VALUE
{ 100, 0 }, { 0, 99 }, // OPAREN, CPAREN
{ 6, 5 }, // EXP
{ 3, 4 }, { 3, 4 }, // MULT, DIV
{ 1, 2 }, { 1, 2 } // PLUS, MINUS
};
int main ( ) {
stack<TokenType> opStack;
opStack.push(EOL); // EOL == end of line
opStack.push(PLUS);
opStack.push(MULT);
opStack.push(EXP);
opStack.push(EXP);		// the stack: eol(-1), plus(2), mult(4), exp(5), exp(5)
TokenType topOp;
TokenType lastType = DIV;
while( PREC_TABLE[ lastType ].inputSymbol <= PREC_TABLE[ topOp = opStack.top( ) ].topOfStack )      //while(3 <= top of stack)
{
opStack.pop();
cout << topOp << endl;					// 5, 5, 4
}
if( lastType != EOL )
opStack.push( lastType );
cout << "done with this crap:" << endl;
while(opStack.size() != 0){
	cout << opStack.top() << endl;
	opStack.pop();
}
// show what are the contents of opStack at this point in the code.
return 0;
}


// stack: EOL, plus, Div