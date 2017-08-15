/* 
Jake Goldstein 
CS_1124 DATE



HW07
*/
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

struct Node{
	Node(int data = 0, Node* next = nullptr): data(data), next(next){}
	int data;
	Node* next;
};

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

class Polynomial{
	friend ostream& operator<<(ostream& os, const Polynomial & poly);
	friend bool operator==(const Polynomial& lhs, const Polynomial& rhs);
public:
	Polynomial(const vector<int>& polys){
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

	Polynomial& operator+=(const Polynomial rhs){
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
	int evaluate(int multiplier){
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
private:
	Node* term;
	int degree;
};

// Print out the Polynomial
ostream& operator<<(ostream& os, const Polynomial & poly){
	// If the polynomial passed is null
	if(poly.term == nullptr){
		// Print message
		os << "No Polynomial";
		return os;
	}
	os << "Degree: " << poly.degree << ':' << endl;
	vector<int> holder;
	Node* p = poly.term;
	while (p){
		holder.push_back(p->data);
		p = p->next;
	}
	int exponent = holder.size()-1;
	for(int i = holder.size() -1 ; i > -1; --i){
		if(holder[i] == 0);
		else if(holder[i] == 1) os << "x^" << exponent << ' ';
		else if(holder[i] == -1) os << "-x^" << exponent << ' ';
		else os << holder[i] << "x^" << exponent << ' ';
		--exponent;
	}
	os << endl;


	// if(p->data < 0){
	// 	os << showpos << p->data << noshowpos << ' ';
	// }
	// // If the data is positive print the data without a sign
	// else if(p->data > 0){
	// 	os << p->data << ' ';
	// }
	// // Go to the next Node
	// p = p->next;
	// // Declare a counter
	// int counter = 1;
	// // While the Node is not a nullpointer
	// while(p != nullptr){
	// 	// If in the first term
	// 	if(counter == 1){
	// 		if(p->data == 0){
	// 			p = p->next;
	// 			++counter;
	// 		}
	// 		else if(p->data == -1){
	// 			os << '-';
	// 		}
	// 		else if(p->data == 1){
	// 			os << "x ";
	// 			p = p->next;
	// 			++counter;
	// 		}
	// 		else {
	// 			// THIS IS THE PART THAT IS PUTTING OUT +5x or something like that
	// 			os << showpos << p->data << noshowpos;
	// 			os << "x ";
	// 			p = p->next;
	// 			++counter;
	// 		}
	// 	}
	// 	else{
	// 		if(p->data == 0){
	// 			p = p->next;
	// 			++counter;
	// 		}
	// 		else if(p->data == -1){
	// 			os << '-';
	// 		}
	// 		else if(p->data == 1){
	// 			os << "x^" << counter << ' ';
	// 			p = p->next;
	// 			++counter;
	// 		}
	// 		else{
	// 			// THIS IS THE PART THAT IS PUTTING OUT +5x or something like that
	// 			os << showpos << p->data << noshowpos;
	// 			os << "x^" << counter << ' ';
	// 			p = p->next;
	// 			++counter;
	// 		}
	// 	}
	// }	
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

int main(){
	vector<int> v1;
	v1.push_back(17);
	v1.push_back(5);
	Polynomial p1(v1);
	vector<int> v2;

	v2.push_back(1);
	v2.push_back(2);
    Polynomial p2(v2);
    vector<int> v3;
    v3.push_back(5);
    v3.push_back(-4);
    v3.push_back(0);
    v3.push_back(3);
    v3.push_back(1);
    Polynomial p3(v3);
    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;
    cout << "p3: " << p3 << endl;
    // cout << "calling do nothing: " << endl;
    // doNothing(p1);
    // Polynomial p4 =  p3+p2;
    // cout << "addidtion: for p4: " << p4 << endl;
    // cout << boolalpha;
    // cout << "(p1 == p2) is " << (p1 == p2) << endl;
    // cout << "(p1 != p2) is " << (p1 != p2) << endl;
    // cout << "testing p1 at 2: " << p1.evaluate(2) << endl;
	return 0;
}