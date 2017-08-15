/*
   Arithmetic Operator Overloading
   Sec 
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Complex {
  friend Complex& operator+=(Complex& lhs, const Complex& rhs);
    //    friend Complex operator+(const Complex& lhs, const Complex& rhs);
    friend ostream& operator<<(ostream& os, const Complex& rhs) {
        os << rhs.real << showpos << rhs.imaginary << noshowpos << 'i'; 

        // os << rhs.real;
        // if (rhs.imaginary < 0) os << rhs.imaginary << 'i';
        // else os << '+' << rhs.imaginary << 'i';

        return os;
    }
public:
    // Complex() : real(0), imaginary(0) {}
    // Complex(double real) : real(real), imaginary(0) {}
    // Complex(double real, double imag) : real(real), imaginary(imag) {}
    Complex(double real = 0, double imag = 0) : real(real), imaginary(imag) {}

    // c1 += c2;
    //  c1.operator+=(c2);
//    Complex& operator+=(const Complex& rhs) {
//        real += rhs.real;
//        imaginary += rhs.imaginary;
//        return *this;
//    }
    Complex& operator++(){
        ++real;
        return *this;
    }
    

private:
    double real, imaginary;
};

// operator+(c2, c3);
Complex operator+(const Complex& lhs, const Complex& rhs) {
    // double real = lhs.real + rhs.real;
    // double imag = lhs.imaginary + rhs.imaginary;
    // Complex result(real, imag);
    Complex result = lhs;
    result += rhs;
    return result;
}

 Complex& operator+=(Complex& lhs, const Complex& rhs) {
     lhs.real += rhs.real;
     lhs.imaginary += rhs.imaginary;
     return lhs;
 }




int main() {
  cout << "this is the important part!!!" << endl;
  Complex a(5,5);
  Complex b(10,10);
  cout << "a " << a << endl;
  cout << "b " << b << endl;
  cout << "a+b " << a+b << endl;
  cout << "a " << a << endl;
  cout << "b " << b << endl;
  cout << "end of the important part!!!" << endl;
  Complex c1;         // 0+0i
  Complex c2(17);     // 17+0i
  Complex c3(3, -5);  // 3-5i
  cout << "c1: " << c1 << endl
       << "c2: " << c2 << endl
       << "c3: " << c3 << endl;

    
   c1 = c2 + c3;
   //c1 = operator+(c2, c3);
    cout << " c1 = c2 + c3" << endl;
    cout << "c1 = " << c1 << endl;
    
    
  c1 += c2;
  //  c1.operator+=(c2);
    
    cout << "(5+c1) and (c1+5)" << endl;
    cout << (5+c1) << endl;
    cout << (c1+5) << endl;

    c2 = ++c1;
//    c1.operator++();
}
