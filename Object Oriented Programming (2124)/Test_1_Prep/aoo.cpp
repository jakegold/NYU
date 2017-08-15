/*
   Arithmetic Operator Overloading
   Sec 
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Complex {
    //    friend Complex operator+(const Complex& lhs, const Complex& rhs);
    friend ostream& operator<<(ostream& os, const Complex& rhs) {
        //     os << rhs.real << '+' << rhs.imaginary << 'i';
        os << rhs.real
            //<< (rhs.imaginary < 0 ? "" : "+") << rhs.imaginary << 'i';
           << showpos << rhs.imaginary << noshowpos << 'i';
        return os;
    }
public:
    // Complex() : real(0), imaginary(0) {}
    // Complex(double real) : real(real), imaginary(0) {}
    // Complex(double real, double imag) : real(real), imaginary(imag) {}
    /*explicit*/ Complex(double real = 0, double imag = 0) : real(real), imaginary(imag) {}

    //    c2 + c3;
    //    c2.operator+(c3);
    // Complex operator+(const Complex& rhs) const {
    //     // Complex result;
    //     // result.real = rhs.real + real;
    //     // result.imaginary = rhs.imaginary + imaginary;
    //     // Complex result(rhs.real + real, rhs.imaginary + imaginary);
    //     // return result;
    //     return Complex(rhs.real + real, rhs.imaginary + imaginary);
    // }

    //c1 += c2;
    //c1.operator+=(c2);
    Complex& operator+=(const Complex& rhs) {
        real += rhs.real;
        imaginary += rhs.imaginary;
        return *this;
        // *this = *this + rhs;
        // return *this;
    }

    // ++c1;
    // c1.operator++();
    Complex& operator++() {
        ++real;
        return *this;
    }

    // c1.operator++(0);
    Complex operator++(int dummy) {
        Complex previous(*this);
        ++real;
        return previous;
    }

private:
    double real, imaginary;
};

Complex operator+(const Complex& lhs, const Complex& rhs) {
    // Complex result;
    // result.real = rhs.real + real;
    // result.imaginary = rhs.imaginary + imaginary;
    // Complex result(rhs.real + real, rhs.imaginary + imaginary);
    // return result;
    //    return Complex(rhs.real + lhs.real, rhs.imaginary + lhs.imaginary);
    Complex result(lhs);
    result += rhs;
    return result;
}


int main() {
    Complex c1;         // 0+0i
    Complex c2(17);     // 17+0i
    Complex c3(3, -5);  // 3-5i
    cout << "c1: " << c1 << endl
         << "c2: " << c2 << endl
         << "c3: " << c3 << endl;
    c1 = c2 + c3;
    // c2 + c3;
    // c2.operator+(c3);
    cout << "c1: " << c1 << endl;
    cout << c1 + 5 << endl;
    // c1.operator+(5);
    // c1.operator+(Complex(5));
    // operator+(c1, 5);

    //    cout << c1 + Complex(5) << endl;
    cout << "THIS IS WHERE MY QUESTION IS!!!" << endl;
    cout << 5 + c1 << endl;
    cout << "end of that...(I was checking to see if this would still work if it was explicit" << endl;
    // 5.operator+(c1);
    //    operator+(c1, 5);
    

    c1 += c2;
    //    c1.operator+=(c2);

    
    cout << "c1: " << c1 << endl;
    cout << "++c1: " << ++c1 << endl;
    //    c1.operator++();
    cout << "c1: " << c1 << endl;

    cout << "c1++: " << c1++ << endl;
    //    c1.operator++(0);
    cout << "c1: " << c1 << endl;

    cout << "++ ++c1: " << ++ ++c1 << endl;
    //    c1.operator+().operator++();
    cout << "c1: " << c1 << endl;
    
    cout << "c1++ ++: " << c1++ ++ << endl;
    //    c1.operator+().operator++();
    cout << "c1: " << c1 << endl;


}
