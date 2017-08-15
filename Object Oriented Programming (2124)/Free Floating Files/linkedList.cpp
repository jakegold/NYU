#include <iostream>

using namespace std;


struct Node{
	Node(int data = 0, Node* next = nullptr): data(data), next(next){}
	int data;
	Node* next;
};

void listDisplay(Node* headPtr){
	Node* p = headPtr;
	while(p != nullptr){
		cout << p->data << '	';
		p = p->next;
	}
	cout << endl;
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

void listInsertHead(Node*& headPtr, int data){
	headPtr = new Node(data, headPtr);
}

void listInsert(Node* before, int data){
	before->next = new Node(data, before->next);
}

void listInsertTail(Node*& headPtr, int data){
	if(headPtr == nullptr){
		headPtr = new Node(data);
		return;
	}
	Node* last = listFindTail(headPtr);
	last->next = new Node(data);
}

void listRemoveHead(Node*& headPtr){
	if(headPtr == nullptr) return;
	Node* second = headPtr->next;
	delete headPtr;
	headPtr = second;
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

// Do not pass this a nullptr
void listRemove(Node* prior){
	Node* connection = prior->next->next;
	delete prior->next;
	prior->next = connection;
}

int listSize(Node* headPtr){
	int counter = 0;
	Node* p =headPtr;
	while(p != nullptr){
		++counter;
		p = p->next;
	}
	return counter;
}

Node* listCopy(Node* headptr){
	// if(headptr == nullptr){
	// 	return nullptr;
	// }
	// Node* result = new Node(headptr->data);
	// Node* last = result;
	// Node* p = headptr->next;
	// while(p != nullptr){
	// 	last->next = new Node(p->data);
	// 	last = last->next;
	// 	p = p->next;
	// }
	// return result;

	if(headptr == nullptr){
		return nullptr;
	}
	Node* rest = listCopy(headptr->next);
	return new Node(headptr->data, rest);
}

void listDisplayReverse(Node* headptr){
	if(headptr == nullptr){
		return nullptr;
	}
	listDisplayReverse(headptr->next);
	cout << headptr->data;
}


int main(){
	return 17;
}