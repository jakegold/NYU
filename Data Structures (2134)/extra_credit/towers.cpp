// Jake Goldstein Extra Credit
// Towers of Hanoi problem
// NOTE: This is only the towers of hanoi, there is no undo or redo
#include <iostream>
#include <stack>

using namespace std;

class Disc{
public:
	Disc(int size = 0) : size(size){}
	int getSize() const {
		return size;
	}
	// Returns true if the passed disc is SMALLER, flase if it is LARGER
	bool bigger(const Disc& otherDisc) const{
		return (size > otherDisc.size);
	}

private:
	int size;
};

struct Towers{
	stack<Disc> left;
	stack<Disc> mid;
	stack<Disc> right;
};

void beginPuzzle();

void print(const stack<Disc>& tower);

void completePuzze(stack<Disc>& leftTower, const int numDiscs);

void moveADisc(stack<Disc>& leftTower, stack<Disc>& midTower, stack<Disc>& rightTower);

int getCommand();

void moveMe(stack<Disc>& fromTower, stack<Disc>& toTower);


int main(){
	beginPuzzle();
	return 42;
}

void beginPuzzle(){
	// Choose how many discs to play with
	int numDiscs;
	stack<Disc> towerOfHanoi;
	cout << "Welcome to Towers of Hanoi. Please enter a number of";
	cout << " how many discs you would like to use" << endl;
	cin >> numDiscs;
	// Create that many discs
	for (int i = numDiscs; i > 0; --i){
		Disc temp(i);
		towerOfHanoi.push(temp);
	}
	cout << "Ok. There are " << numDiscs << " discs, and all";
	cout << " of the discs are on the left side." << endl;
	cout << "You need to get them all to the right side." << endl;
	cout << endl;
	completePuzze(towerOfHanoi, numDiscs);
}

void print(const stack<Disc>& tower){
	// Create a temp Stack of discs
	stack<Disc> temp = tower;
	// Pop and print all elements of the temp
	while(temp.size() > 0){
		cout << temp.top().getSize() << ", ";
		temp.pop();
	}
	cout << endl;
	cout << endl;
}

void completePuzze(stack<Disc>& leftTower, const int numDiscs){
	// Create the middle and right towers
	stack<Disc> rightTower;
	stack<Disc> midTower;
	// While the game is not won
	while(rightTower.size() != numDiscs){
		// Print out what is on each tower
		cout << "Left Tower:" << endl;
		print(leftTower);
		cout << "Middle Tower" << endl;
		print(midTower);
		cout << "Right Tower" << endl;
		print(rightTower);
		// Move a disc
		moveADisc(leftTower, midTower, rightTower);
	}
	// If the game is over, print message
	cout << "Congrats! You win!" << endl;
}

void moveADisc(stack<Disc>& leftTower, stack<Disc>& midTower, stack<Disc>& rightTower){
	// Get a command from the user
	int from = getCommand();
	if (from < 4 && from > 0){
		// Get the tower to move the Disc to
		int to;
		cout << " to tower (insert second tower number).";
		cin >> to;
		// From Left to Mid
		if (from == 1 && to == 2){
			moveMe(leftTower, midTower);
		}
		// Left to Right
		else if (from == 1 && to == 3){
			moveMe(leftTower, rightTower);
		}
		// Mid to Right
		else if (from == 2 && to == 3){
			moveMe(midTower, rightTower);
		}
		// Mid to Left
		else if (from == 2 && to == 1){
			moveMe(midTower, leftTower);
		}
		// Right to Left
		else if (from == 3 && to == 1){
			moveMe(rightTower, leftTower);
		}
		// Right to Mid
		else if (from == 3 && to == 2){
			moveMe(rightTower, midTower);
		}
		// If they are the same, print message
		else{
			cout << "Please select two different towers." << endl;
		}
	}
	// Any other number, print message
	else{
		cout << "Sorry. I didn't get that. Please try again." << endl;
		cout << endl;
	}
}

int getCommand(){
	// Ask for a tower to move a disc from
	int command;
	cout << "To move a disc, please enter from which";
	cout << " tower you would like to move your disc." << endl;
	cout << " Towers are labeled 1-3 from left to right." << endl;
	cin >> command;
	return command;
}

void moveMe(stack<Disc>& fromTower, stack<Disc>& toTower){
	// If trying to move a disc from a tower without any discs
	// Print message
	if (fromTower.size() == 0){
		cout << "Warning! This move is not allowed." << endl;
		cout << endl;
		return;
	}
	Disc formerSide = fromTower.top();
	// If moving to a tower with 0 discs
	if (toTower.size() == 0){
		// Add to that tower and delete from the old tower
		toTower.push(formerSide);
		fromTower.pop();
		return;
	}
	Disc newSide = toTower.top();
	// If the new tower has a smaller disc, print message
	if(formerSide.bigger(newSide)){
		cout << "Warning! This move is not allowed." << endl;
		cout << endl;
	}
	// Else add to the tower and delete from old one
	else{
		toTower.push(formerSide);
		fromTower.pop();
	}
	return;
}