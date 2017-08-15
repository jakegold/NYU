#include <iostream>
#include <climits>

using namespace std;

struct Node{
	Node(int data = 0, Node* next = nullptr): data(data), next(next){}
	int data;
	Node* next;
};

void listInsertHead(Node*& headPtr, int data){
	headPtr = new Node(data, headPtr);
}

void listDisplay(Node* headPtr){
	Node* p = headPtr;
	while(p != nullptr){
		cout << p->data << '	';
		p = p->next;
	}
	cout << endl;
}

void binary(int num){
	cout << "NUM: " << num << endl;
	if (num < 2) cout << num;
	else{
		binary(num/2);
		cout << num%2;
	}
}

Node* sums(Node* first, Node* second){
	if(first == nullptr) return nullptr;
	Node* result = sums(first->next, second->next);
	listInsertHead(result, first->data + second->data);
	return result;
}

struct TNode {
  TNode(int data = 0, TNode *left = nullptr, TNode *right = nullptr)
    : data(data), left(left), right(right) {}
  int data;
  TNode *left, *right;
};

int max(TNode* root) {
  if(root == nullptr) return INT_MIN;
  int right = max(root->right);
  int left = max(root->left);
  int result;
  if(left >= right) result = left;
  else result = right;
  if (root->data > result) return root->data;
  else return result;
}

int cSum(char word[]){
	if (word[0] == '\0') return 0;
	int result = 0;
	result += word[0];
	result += cSum(word+1);
	return result;
}

int cSearch(char word[], char target, int high, int low){
	if(low > high) return -1;
	int middle = low + (high - low) / 2;
	if(target == word[middle]) return middle;
	else if(int(target) > int(word[middle])) return cSearch(word, target, high, middle+1);
	else return cSearch(word, target, middle-1, low);
}


void f(int n) { 
   if (n > 1) { 
      cout << 'a'; 
      f(n/2); 
      cout << 'b'; 
      f(n/2); 
   } 
   cout << 'c'; 
}

int main(){
	// Test one
	cout << "test one" << endl;
	int test = 0;
	binary(test);
	cout << endl;

	// Test two
	cout << "test two" << endl;
	Node* L1 = nullptr;
    listInsertHead(L1, 6);
    listInsertHead(L1, 6);
	listInsertHead(L1, 6);
	listDisplay(L1);
	Node* L2 = nullptr;
    listInsertHead(L2, 9);
    listInsertHead(L2, 8);
    listInsertHead(L2, 7);
    listDisplay(L2);
    Node* L3 = sums(L1, L2);
    listDisplay(L3);

	// Test three
	cout << "test three" << endl;
	TNode a(34), b(2), c(38), d(8, &a, &b), e(16, &c), f(32, &d, &e);
  	cout << max(&f) << endl;

  	// Test four
  	cout << "test four" << endl;
  	char cstringone[15] = "AA";
  	// cout << cstringone << endl;
  	// cout << cstringone+1 << endl;
  	cout << cSum(cstringone) << endl;

  	// test five
  	cout << "test five" << endl;
  	char cstringtwo[17] = "abcdefghijklmnop";
  	cout << cstringtwo << endl;
  	cout << cSearch(cstringtwo, 'z', 17, 0) << endl;





}