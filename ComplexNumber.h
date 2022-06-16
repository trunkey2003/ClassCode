#include <iostream>
#include <math.h>

using namespace std;

class ComplexNumber
{
private:
    double realPart;
    double imaginaryPart;
public:
    ComplexNumber()
    {
    }

    ComplexNumber(double realPart, double imaginaryPart)
    {
        this->realPart = realPart;
        this->imaginaryPart = imaginaryPart;
    }

    ComplexNumber operator+(ComplexNumber otherComplexNumber)
    {
        return (ComplexNumber(realPart + otherComplexNumber.realPart, imaginaryPart + otherComplexNumber.imaginaryPart));
    }

    ComplexNumber operator-(ComplexNumber otherComplexNumber)
    {
        return (ComplexNumber(realPart - otherComplexNumber.realPart, imaginaryPart - otherComplexNumber.imaginaryPart));
    }

    ComplexNumber operator*(ComplexNumber otherComplexNumber)
    {
        return (ComplexNumber(realPart * otherComplexNumber.realPart - imaginaryPart * otherComplexNumber.imaginaryPart, realPart * otherComplexNumber.imaginaryPart + imaginaryPart * otherComplexNumber.realPart));
    }

    ComplexNumber operator/(ComplexNumber otherComplexNumber)
    {
        double _realPart = (realPart * otherComplexNumber.realPart + imaginaryPart * otherComplexNumber.imaginaryPart) / (pow(otherComplexNumber.realPart, 2) + pow(otherComplexNumber.imaginaryPart, 2));
        double _imaginaryPart = (imaginaryPart * otherComplexNumber.realPart - realPart * otherComplexNumber.imaginaryPart) / (pow(otherComplexNumber.realPart, 2) + pow(otherComplexNumber.imaginaryPart, 2));
        return ComplexNumber(_realPart, _imaginaryPart);
    }

    bool operator==(ComplexNumber b){
        return (realPart == b.realPart && imaginaryPart == b.imaginaryPart);
    }

    bool operator!=(ComplexNumber b){
        return !(realPart == b.realPart && imaginaryPart == b.imaginaryPart);
    }

    friend ostream& operator<<(ostream &os, const ComplexNumber & x)
    {
        string mark = (x.imaginaryPart >= 0)? " + " : " - ";
        double realPart = x.realPart;
        double imaginaryPart = (x.imaginaryPart >= 0)? x.imaginaryPart : -x.imaginaryPart;
        os << realPart << mark << imaginaryPart  << "i";
        return os;
    }

    friend istream& operator>>(istream &is, ComplexNumber & x){
        is >> x.realPart >> x.imaginaryPart;
        return is;
    }

    double absoluteValue()
    {
        return sqrt(realPart * realPart + imaginaryPart * imaginaryPart);
    }
};
