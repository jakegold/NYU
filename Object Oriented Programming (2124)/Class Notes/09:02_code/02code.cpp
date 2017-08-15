// simplest program in cpp

int main(){

}
// but you do want it to return something

int main(){
	std::cout << "whatup\n"; // cout is the output operator 
	return 0;
}

//this is w/o using standard namespace.....

#include <iostream>

using namespace std; //so now i can just skip the std:: part

int main(){
	cout << "whatup\n";
	return 0;
}

// so note that you have to declare things

#include <iostream>
using namespace std;

int main(){
	int x = 17;
}

// or we can add the string library
#include <iostream>
#include <string>

using namespace std;

int main(){
	string c = "im a cisi";

}

// loops and conditions
#include <iostream>
#include <string>

using namespace std;

int main(){
	int x = 17;
	string c = "im a cisi";
	if (x == 42){ // note: you can use only one = in cpp but in java that would fail
		cout << "the answer!\n";
	}
	else if (x == 17 && s = "fred"){ //&& is and, || is or, ! is not
		cout << "some other thing\n";
	}
	else {
		cout << "not the answer\n";
	}
}

#include <iostream>
#include <string>

using namespace std;

int main(){
	for (int coutner = 0; counter < 10; ++counter){//you can put the ++ on either side
		cout << counter << endl; // i beilieve that endl is the same as \n
	} 
	// note: counter is only true for the loop...i cant use counter now it would compile
	//note: globle variables suck
	int othercounter = 0;
	while (othercounter < 10){
		cout << othercounter << endl;
		++othercounter;
	}
	/*this is the same as the for loop but now i can use counter outside of the loop
	for the for loop you wouldnt be able to call it
	*/
	return 0;
}

//we said that you can read from the code to the terminal...but not the opposite 

#include <iostream>
#include <string>

using namespace std;

int main(){
	int x;
	string s;
	// note that s and x are bad names...
	cin >> x; //this will fail if you dont type what type its expecting
	cin >> s;
	//strings only work on words..how do you get a line?
	getline(cin, s); //it takes two things and asks how are u giving me this info and what variable
	return 0;
}

// files 
#include <iostream>
#include <string>

using namespace std;

int main(){
	string s;
	char c;
	ifstream ifs("nameOfFile"); //this will open if the file is there
	if (!ifs) {
		cerr << "failed to open nameOfFile" << endl; //do this to let u know if ur file exits or if your being a fool
		exit(1);//exits program or file not sure (and needs a small pos. number)
	}
	ifs >> s; //s is holding the next token from the stream every time
	cout << s << endl;

	while (ifs >> s){//so this is holding it for EVERY token
		cout << s << endl; // this should put out the whole file
		for (int i = 0; i < s.size(); ++i){
			cout << s[i] << ' ';// so this loop would print out every charachyer in a string wiht a space..just showing we can accses these charachters
		}
	}

	while (getline(ifs,s)){//so now its not just a token..its a whole line
		cout << s << endl;
	}

	while (ifs >> c){//now its not a line or a string...its by chars..but in one word! it doesnt get white spaces..such as spaces
		cout << c << endl;
	}
/*note not all of these are going to run because its going to stop after the first loop
in order to run another one of these you would need to re-open the file or comment out something
*/
}

