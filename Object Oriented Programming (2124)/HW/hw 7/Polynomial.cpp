#include "Polynomial.h"
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

Node::Node(int data = 0, Node* next = nullptr): data(data), next(next){}

void listInsertHead(Node*& headPtr, int data){
	headPtr = new Node(data, headPtr);
}

Node* listFindTail(Node* headPtr){
	if(headPtr == nullptr){
		return nullptr;
	}
	Node* p = headPtr;
	while(p->next != nullptr){
		p = p->next;
	}
	return p;
}

void listInsertTail(Node*& headPtr, int data){
	if(headPtr == nullptr){
		headPtr = new Node(data);
		return;
	}
	Node* last = listFindTail(headPtr);
	last->next = new Node(data);
}

void listRemoveTail(Node* headPtr){
	if (headPtr == nullptr) return;
	if (headPtr->next == nullptr){
		delete headPtr;
		headPtr = nullptr;
	}
	else{
		Node* p = headPtr;
		while(p->next->next != nullptr){
			p = p->next;
		}
		delete p-> next;
		p->next = nullptr;
	}
}

Polynomial::Polynomial(const vector<int>& polys){
	if(polys.size() == 1 && polys[0] == 0){
		degree = 0;
	}
	else{
		degree = polys.size()-1;
	}
	for(size_t i = 0; i < polys.size(); ++i){
		listInsertHead(term, polys[i]);
	}
}

Polynomial& Polynomial::operator+=(const Polynomial rhs){
	Node* first = term;
	Node* right = rhs.term;
	if(degree >= rhs.degree){ //lhs has more terms
		while(right != nullptr){
			term->data+=right->data;	
			term = term->next;
			right = right->next;
		}
		term = first;
	}
	else{//(degree < rhs.degree){ // rhs has more terms
		degree = rhs.degree;
		while(term != nullptr){
			term->data+=right->data;	
			term = term->next;
			right = right->next;
		}
		term = first;
		while(right != nullptr){
			listInsertTail(term, right->data);
			right = right->next;
		}
	}
	return *this;
}

int Polynomial::evaluate(int multiplier){
	Node* p = term;
	int result = p->data;
	p = p->next;
	int counter = 1;
	while(p != nullptr){
		result+= p->data * pow(multiplier, counter);
		p = p->next;
		++counter;
	}
	return result;
}

	// Print out the Polynomial
ostream& operator<<(ostream& os, const Polynomial & poly){
	// If the polynomial passed is null
	if(poly.term == nullptr){
		// Print message
		os << "No Polynomial";
		return os;
	}
	// Print message
	os << "Degree: " << poly.degree << ':' << endl;
	// Declare variable
	Node* p = poly.term;
	// If the data is negative, print out the data with a negtaive sign
	if(p->data < 0){
		os << showpos << p->data << noshowpos << ' ';
	}
	// If the data is positive print the data without a sign
	else if(p->data > 0){
		os << p->data << ' ';
	}
	// Go to the next Node
	p = p->next;
	// Declare a counter
	int counter = 1;
	// While the Node is not a nullpointer
	while(p != nullptr){
		// If in the first term
		if(counter == 1){
			if(p->data == 0){
				p = p->next;
				++counter;
			}
			else if(p->data == -1){
				os << '-';
			}
			else if(p->data == 1){
				os << "x ";
				p = p->next;
				++counter;
			}
			else {
				// THIS IS THE PART THAT IS PUTTING OUT +5x or something like that
				os << showpos << p->data << noshowpos;
				os << "x ";
				p = p->next;
				++counter;
			}
		}
		else{
			if(p->data == 0){
				p = p->next;
				++counter;
			}
			else if(p->data == -1){
				os << '-';
			}
			else if(p->data == 1){
				os << "x^" << counter << ' ';
				p = p->next;
				++counter;
			}
			else{
				// THIS IS THE PART THAT IS PUTTING OUT +5x or something like that
				os << showpos << p->data << noshowpos;
				os << "x^" << counter << ' ';
				p = p->next;
				++counter;
			}
		}
	}	
	return os;
}

Polynomial& operator+(Polynomial& lhs, Polynomial rhs){
	lhs+=rhs;
	return lhs;
}

bool operator==(const Polynomial& lhs, const Polynomial& rhs){
	if(lhs.degree != rhs.degree){
		return false;
	}
	Node* left = lhs.term;
	Node* right = rhs.term;
	while(left != nullptr){
		if(left->data != right->data){
			return false;
		}
		left = left->next;
		right = right->next;
	}
	return true;
}

bool operator!=(const Polynomial& lhs, const Polynomial& rhs){
	bool result = !(lhs==rhs);
	return result;
}

void doNothing(Polynomial temp) {}