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

    double getRealPart()
    {
        return realPart;
    }

    double getImaginaryPart()
    {
        return imaginaryPart;
    }

    ComplexNumber Sum(ComplexNumber otherComplexNumber)
    {
        return (ComplexNumber(realPart + otherComplexNumber.realPart, imaginaryPart + otherComplexNumber.imaginaryPart));
    }

    ComplexNumber Different(ComplexNumber otherComplexNumber)
    {
        return (ComplexNumber(realPart - otherComplexNumber.realPart, imaginaryPart - otherComplexNumber.imaginaryPart));
    }

    ComplexNumber Product(ComplexNumber otherComplexNumber)
    {
        return (ComplexNumber(realPart * otherComplexNumber.realPart - imaginaryPart * otherComplexNumber.imaginaryPart, realPart * otherComplexNumber.imaginaryPart + imaginaryPart * otherComplexNumber.realPart));
    }

    ComplexNumber Division(ComplexNumber otherComplexNumber)
    {
        double _realPart = (realPart * otherComplexNumber.realPart + imaginaryPart *  otherComplexNumber.imaginaryPart) / (pow(otherComplexNumber.realPart,2) + pow(otherComplexNumber.imaginaryPart,2));
        double _imaginaryPart = (imaginaryPart * otherComplexNumber.realPart - realPart * otherComplexNumber.imaginaryPart) / (pow(otherComplexNumber.realPart,2) + pow(otherComplexNumber.imaginaryPart,2));
        return ComplexNumber(_realPart, _imaginaryPart);
    }

    double getAbsoluteValue(){
        return sqrt(realPart*realPart + imaginaryPart*imaginaryPart);
    }
};
