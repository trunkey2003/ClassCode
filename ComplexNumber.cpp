#include <iostream>
#include <math.h>
#include "ComplexNumber.h"

using namespace std;

ComplexNumber Input(){
	cout << "Input complex number: " << endl;
	double realPart, imaginaryPart;
	cout << "Real part: ";
	cin >> realPart;
	cout << "Imaginary part: ";
	cin >> imaginaryPart;
	cout << endl;
	return ComplexNumber(realPart, imaginaryPart);
}

string Sign(int a){
	return (a >= 0)? "+" : " ";
}

void Output(ComplexNumber a, ComplexNumber b){
	cout << "Sum a + b: " << a.Sum(b).getRealPart() << 
	Sign(a.Sum(b).getImaginaryPart()) << a.Sum(b).getImaginaryPart() << "i" << endl;
	cout << "Different a + b: " << a.Different(b).getRealPart() << 
	Sign(a.Different(b).getImaginaryPart()) << a.Different(b).getImaginaryPart() << "i" << endl;
	cout << "Product a + b: " << a.Product(b).getRealPart() << 
	Sign(a.Product(b).getImaginaryPart()) << a.Product(b).getImaginaryPart() << "i" << endl;
	cout << "Division a + b: " << a.Division(b).getRealPart() << 
	Sign(a.Division(b).getImaginaryPart()) << a.Division(b).getImaginaryPart() << "i" << endl;
	cout << "Absolute a : " << a.getAbsoluteValue() << endl;
	cout << "Absolute b : " << b.getAbsoluteValue() << endl;
}

int main(){
	ComplexNumber a = Input();
	ComplexNumber b = Input();
	Output(a, b);
}
