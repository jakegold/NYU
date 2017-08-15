#include <iostream>
#include <cstdlib>

using namespace std;


struct Node {
    Node(int data = 0, Node* link = nullptr) : data(data), link(link) {}
    int data;
    Node* link;
};

void listInsertHead(int entry, Node*& headPtr) {
    headPtr = new Node(entry, headPtr);
}

void listDisplay(Node* headPtr){
    Node* p = headPtr;
    while(p != nullptr){
        cout << p->data << '	';
        p = p->link;
    }
    cout << endl;
}

void spliceList(Node*& headptr, Node*& addOn){
	Node* remember = headptr->link;
	headptr->link = addOn;
	Node* p = headptr;
	while(p->link != nullptr){
		 p = p->link;
	}
	p->link = remember;
}

Node* listNodeAddress(Node* headptr, int answer){
	Node* p = headptr;
	while(p != nullptr){
		if(p->data == answer){
			return p;
		}
		else if(p->link != nullptr){
			p = p->link;	
		}
		else{
			return nullptr;
		}
	}
	return nullptr;
}

Node* isSublist(Node* headptr, Node* searchFor){
	Node* p = headptr;
	Node* check = searchFor;
	while(p != nullptr){
		if(p->data != check->data){
			p = p->link;
		}
		else{
			Node* result = p;
			Node* holder = p->link;
			while(check != nullptr){
				if(p->data == check->data){
					if(check->link != nullptr){
						if(p->link == nullptr){
							check = searchFor;
							p = holder;
							break;
						}
						else{
							p = p->link;
							check = check->link;
						}
					}
					else{
						return result;
					}
				}
				else{
					check = searchFor;
					p = holder;
					break;
				}
			}
		}
	}
	cout << "Failed to match" << endl;
	return nullptr;
}

int main(){
    // Node* L1 = nullptr;
    // listInsertHead(11, L1);
    // listInsertHead(10, L1);
    // listInsertHead(6, L1);
    // listInsertHead(5, L1);
    // cout << "Display L1" << endl;
    // listDisplay(L1);
    // Node* L2 = nullptr;
    // listInsertHead(9, L2);
    // listInsertHead(8, L2);
    // listInsertHead(7, L2);
    // cout << "Display L2" << endl;
    // listDisplay(L2);
    // cout << "Getting address:" << endl;
    // Node* address = listNodeAddress(L1, 6);
    // cout << "Address found:" << endl;
    // cout << "Putting lists together:" << endl;
    // spliceList(address, L2);
    // cout << "Lists are in order, Display L1:" << endl;
    // listDisplay(L1);
    // cout << "Display L2" << endl;
    // listDisplay(L2);
    Node* L3 = nullptr;
    listInsertHead(6, L3);
    listInsertHead(5, L3);
	listInsertHead(4, L3);
	listInsertHead(2, L3);
	listInsertHead(3, L3);
	listInsertHead(2, L3);
	listInsertHead(3, L3);
	listInsertHead(2, L3);
	listInsertHead(1, L3);
    cout << "Display L3" << endl;
    listDisplay(L3);
    // cout << "Match 1?" << endl;
    // Node* L4 = nullptr;
    // listInsertHead(1, L4);
    // Node* L5 = isSublist(L3, L4);
    // cout << "Display L4" << endl;
    Node* L5 = nullptr;
    Node* L6 = nullptr;
    cout << "matching 1:" << endl;
    listInsertHead(1, L6);
	L5 = isSublist(L3, L6);
	listDisplay(L5);

	L6 = nullptr;
	listInsertHead(9, L6);
	listInsertHead(3, L6);
	cout << "matching 3,9:"  << endl;
	L5 = isSublist(L3, L6);
	listDisplay(L5);

	L6 = nullptr;
	listInsertHead(3, L6);
	listInsertHead(2, L6);
	cout << "matching 2,3:" << endl;
	L5 = isSublist(L3, L6);
	listDisplay(L5);

	L6 = nullptr;
	listInsertHead(6, L6);
	listInsertHead(5, L6);
	listInsertHead(4, L6);
	listInsertHead(2, L6);
	cout << "matching 2,4,5,6:" << endl;
	L5 = isSublist(L3, L6);
	listDisplay(L5);

	L6 = nullptr;
	listInsertHead(4, L6);
	listInsertHead(2, L6);
	listInsertHead(3, L6);
	listInsertHead(2, L6);
	cout << "matching 2,3,2,4:" << endl;
	L5 = isSublist(L3, L6);
	listDisplay(L5);

	L6 = nullptr;
	listInsertHead(7, L6);
	listInsertHead(6, L6);
	listInsertHead(5, L6);
	cout << "matching 5,6,7:" << endl;
	L5 = isSublist(L3, L6);
	listDisplay(L5);
}