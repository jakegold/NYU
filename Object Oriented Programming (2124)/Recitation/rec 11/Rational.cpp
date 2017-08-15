#include "Rational.h"
#include <iostream>

using namespace std;

namespace CS1124{

	Rational::Rational():nume(0), denom(1){}

	Rational::Rational(int number):nume(number), denom(1){}

	Rational::Rational(int nume, int denom):nume(nume), denom(denom){}

	Rational& Rational::operator+=(const Rational& two){
			nume = nume*two.denom + denom*two.nume;
			denom = denom*two.denom;
			int temp = gcd(nume, denom);
			if(temp < 0){
				temp *=-1;
			}
			nume /=temp;
			denom /=temp;
			return *this;
	}

	Rational& Rational::operator++(){
		*this+=1;
		return *this;
	}

	Rational Rational::operator++(int){
		Rational temp = *this;
		*this+=1;
		return temp;
	}	

	ostream& operator<<(ostream& os, const Rational& rat){
		int temp = gcd(rat.nume,rat.denom);
		if(temp < 0){
			temp = temp*-1;
		}
		if(rat.denom == 0){
			os << "infinty";
			return os;
		}
		else if(rat.nume == 0){
			os << 0;
			return os;
		}
		else if(rat.nume == rat.denom){
			os << 1;
			return os;
		}
		if(rat.nume > 0 && rat.denom > 0){
			if(rat.denom == 1 ){
				os << rat.nume;
			}
			else{
				os << rat.nume/temp << '/' << rat.denom/temp;
			}
			return os;
		}
		else if(rat.nume < 0 && rat.denom < 0){
			if(rat.denom == -1){
				os << (rat.nume)*-1;
			}
			else{
				os << (rat.nume)*-1/temp << '/' << (rat.denom)*-1/temp;
			}
			return os;
		}
		else{
			if(rat.denom == 1){
				os << rat.nume;
			}
			else if(rat.denom == -1){
				os << (rat.nume)*-1;
			}
			else if(rat.denom > 0){
				os << rat.nume/temp << '/' << rat.denom/temp;
			}
			else{
				os << (rat.nume)*-1/temp << '/' << (rat.denom)*-1/temp;
			}
			return os;
		}
		return os;
	}

	istream& operator>>(istream& is, Rational& rat){
		char c;
		int nume, denom;
		is >> nume >> c >> denom;
		if(denom == 0){
			exit(1);
		}
		rat.nume = nume;
		rat.denom = denom;
		return is;
	}

	int gcd(int x, int y) {
		while (y != 0) {
			int temp = x % y;
			x = y;
			y = temp;
		}
		return x;
	}

	Rational operator+(const Rational& one, const Rational& two){
		Rational answer = one;
		answer+=two;
		return answer;
	}

	bool operator==(const Rational& one, const Rational& two){
		if(one.nume == two.nume && one.denom == two.denom){ return true; } 
		else {return false;}
	}

	bool operator!=(const Rational& one, const Rational& two){
		bool temp = (one == two);
		return !temp;
	}

	Rational& operator--(Rational& one){
		one +=-1;
		return one;
	}

	Rational operator--(Rational& one, int){
		Rational temp = one;
		one +=-1;
		return temp;
	}
}