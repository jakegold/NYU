#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

namespace CS1124{
	class Rational{
	friend std::ostream& operator<<(std::ostream& os, const Rational& rat);
	friend std::istream& operator>>(std::istream& os, Rational& rat);
	friend bool operator==(const Rational& one, const Rational& two);
	public:
		Rational();
		Rational(int number);
		Rational(int nume, int denom);
		Rational& operator+=(const Rational& two);
		Rational& operator++();
		Rational operator++(int);

	private:
		int nume;
		int denom;
	};



	std::ostream& operator<<(std::ostream& os, const Rational& rat);

	std::istream& operator>>(std::istream& os, Rational& rat);

	int gcd(int x, int y);

	Rational operator+(const Rational& one, const Rational& two);

	bool operator==(const Rational& one, const Rational& two);

	bool operator!=(const Rational& one, const Rational& two);

	Rational& operator--(Rational& one);

	Rational operator--(Rational& one, int);
}

#endif