#include <iostream>
#include <vector>

using namespace std;

class PrintedMaterial {
public:
	PrintedMaterial(unsigned pages) : numberOfPages(pages){}
	virtual void displayNumPages() const =0; 
protected:
private:
	unsigned numberOfPages;
};

void PrintedMaterial::displayNumPages() const {
	cout << numberOfPages << endl; 
}

class Magazine : public PrintedMaterial {
public:
	Magazine(unsigned pages) : PrintedMaterial(pages){}
	void displayNumPages() const {PrintedMaterial::displayNumPages();}
protected:
private:
};

class Book : public PrintedMaterial {
public:
	Book(unsigned pages) : PrintedMaterial(pages){}
	void displayNumPages() const {PrintedMaterial::displayNumPages();}
protected:
private:
};

class TextBook : public Book {
public:
	TextBook(unsigned realPages, unsigned indexPages) : Book(realPages), numOfIndexPages(indexPages){}
	void displayNumPages() const{
		cout << "Number of pages in Index: " << numOfIndexPages << " Number of pages in actual TextBook: "; 
		PrintedMaterial::displayNumPages();
	}
protected:
private:
	unsigned numOfIndexPages;
};

class Novel : public Book {
public:
	Novel(unsigned pages) : Book(pages){}
	void displayNumPages() const {PrintedMaterial::displayNumPages();}
protected:
private:
};

void displayNumberOfPages(PrintedMaterial & pointer){
	pointer.displayNumPages();
}
// tester/modeler code
int main()
{
	TextBook t(123,101);
	Novel n(456);
	Magazine m(789);

	vector<PrintedMaterial*> vectorOfThings;
	vectorOfThings.push_back(&t);
	vectorOfThings.push_back(&n);
	vectorOfThings.push_back(&m);

	for(size_t i = 0; i < vectorOfThings.size(); ++i){
		vectorOfThings[i]->displayNumPages();
	}



}


