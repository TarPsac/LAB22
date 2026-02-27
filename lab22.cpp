#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber{				
	public:
		double real;
		double imag;
        
		ComplexNumber(double x = 0, double y = 0); 
		
		friend ComplexNumber operator+(const ComplexNumber &a, const ComplexNumber &b);
		friend ComplexNumber operator-(const ComplexNumber &a, const ComplexNumber &b);
		friend ComplexNumber operator*(const ComplexNumber &a, const ComplexNumber &b);
		friend ComplexNumber operator/(const ComplexNumber &a, const ComplexNumber &b);
		friend bool operator==(const ComplexNumber &a, const ComplexNumber &b);
        friend ostream & operator<<(ostream &os, const ComplexNumber &c);

		double abs() const {
			return sqrt(real * real + imag * imag);
		}
		double angle() const {
            return atan2(imag, real) * 180.0 / (atan(1.0) * 4.0); 
        }
};

ComplexNumber::ComplexNumber(double x, double y){
	real = x; 
    imag = y;
}

ComplexNumber operator+(const ComplexNumber &a, const ComplexNumber &b){
	return ComplexNumber(a.real + b.real, a.imag + b.imag);
}

ComplexNumber operator-(const ComplexNumber &a, const ComplexNumber &b){
	return ComplexNumber(a.real - b.real, a.imag - b.imag);
}

ComplexNumber operator*(const ComplexNumber &a, const ComplexNumber &b){
	return ComplexNumber(a.real * b.real - a.imag * b.imag, 
                         a.real * b.imag + a.imag * b.real);
}

ComplexNumber operator/(const ComplexNumber &a, const ComplexNumber &b){
    double denominator = b.real * b.real + b.imag * b.imag;
	return ComplexNumber((a.real * b.real + a.imag * b.imag) / denominator, 
                         (a.imag * b.real - a.real * b.imag) / denominator);
}

bool operator==(const ComplexNumber &a, const ComplexNumber &b){
	if(a.real == b.real && a.imag == b.imag){
		return true;
	}else{
		return false;
	}
}

ostream & operator<<(ostream &os, const ComplexNumber &c){
        if(c.real == 0 && c.imag == 0) {
            os << "0";
        } else if (c.real == 0) {
            os << c.imag << "i";
        } else if (c.imag == 0) {
            os << c.real;
        } else {
            os << c.real;
            if (c.imag > 0) {
                os << "+";
            }
            os << c.imag << "i";
        }
        return os;
}
