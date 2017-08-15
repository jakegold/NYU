#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

struct Node{
	Node(int data = 0, Node* next = nullptr);
	int data;
	Node* next;
};

void listInsertHead(Node*& headPtr, int data);

Node* listFindTail(Node* headPtr);

void listInsertTail(Node*& headPtr, int data);

void listRemoveTail(Node* headPtr);

class Polynomial{
	friend ostream& operator<<(ostream& os, const Polynomial & poly);
	friend bool operator==(const Polynomial& lhs, const Polynomial& rhs);
public:
	Polynomial(const vector<int>& polys);

	// THIS IS WHAT NEEDS WORK
	Polynomial(Polynomial& anotherPoly){
		degree = anotherPoly.degree;
		Node* p = anotherPoly.term;
		for(size_t i = 0; i < degree -1; ++i){
			listInsertHead(term, p->data);
			p = p->next;
		}
	}
	~Polynomial(){
		while(term->next != nullptr){ //IM NOT TOTALLY SURE ABOUT THIS FUNCTION
			cout << "hello there!" << endl;
			listRemoveTail(term);
		}
	}
	Polynomial& operator=(const Polynomial& anotherPoly){
		if(this != &anotherPoly){
			while(term != nullptr){
				listRemoveTail(term);
			}
			degree = anotherPoly.degree;
			Node* p = anotherPoly.term;
			for(size_t i = 0; i < degree -1; ++i){
				listInsertHead(term, p->data);
				p = p->next;
			}
		}
		return *this;
	}
	// // UP UNTIL HERE

	Polynomial& operator+=(const Polynomial rhs);

	int evaluate(int multiplier);
private:
	Node* term;
	int degree;
};

// Print out the Polynomial
ostream& operator<<(ostream& os, const Polynomial & poly);

Polynomial& operator+(Polynomial& lhs, Polynomial rhs);

bool operator==(const Polynomial& lhs, const Polynomial& rhs);

bool operator!=(const Polynomial& lhs, const Polynomial& rhs);

void doNothing(Polynomial temp);


#endif

