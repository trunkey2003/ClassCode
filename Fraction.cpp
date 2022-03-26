#include <iostream>
#include <math.h>
#include <string>

using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;
    int gcd(int a, int b)
    {
        if (a % b != 0)
            return gcd(b, a % b);
        else
            return b;
    }

public:
    Fraction(){

    }

    Fraction(int n, int d)
    {
        numerator = n;
        if (d == 0)
        {
            cout << "Please put the validated denominator" << endl;
            exit(0);
        }
        else
            denominator = d;
    }

    int getNumerator(){
        return numerator;
    }

    int getDenominator(){
        return denominator;
    }

    Fraction reducedFraction(int n, int d)
    {
        int _gcd = gcd(n, d);
        n = n / _gcd;
        d = d / _gcd;
        return Fraction(n, d);
    }

    Fraction greatestFraction(Fraction a, Fraction b)
    {
        double aDouble = a.numerator / a.denominator;
        double bDouble = b.numerator / b.denominator;
        return (aDouble > bDouble)? a : b;
    }
    
    Fraction Sum(Fraction otherFraction)
    {
        int n = numerator*otherFraction.denominator+otherFraction.numerator*denominator;
        int d = denominator*otherFraction.denominator;
        return Fraction(n/gcd(n,d),d/gcd(n,d));
    }
    
    Fraction Difference(Fraction otherFraction)
    {
        int n = numerator*otherFraction.denominator-otherFraction.numerator*denominator;
        int d = denominator*otherFraction.denominator;
        return Fraction(n/gcd(n,d),d/gcd(n,d));
    }
    
    Fraction Product(Fraction otherFraction)
    {
        int n = numerator*otherFraction.numerator;
        int d = denominator*otherFraction.denominator;
        return Fraction(n/gcd(n,d),d/gcd(n,d));
    }
    
    Fraction Division(Fraction otherFraction)
    {
        int n = numerator*otherFraction.denominator;
        int d = denominator*otherFraction.numerator;
        return Fraction(n/gcd(n,d),d/gcd(n,d));
    }
    
    string displayFraction(){
        if (denominator < 0) {
            denominator = -denominator;
            return ("-" + (to_string(numerator) + "/" +  to_string(denominator)));
        }
    	return (to_string(numerator) + "/" +  to_string(denominator));
	}
};

void Output(Fraction f1, Fraction f2){
    cout << "Sum:  " << f1.Sum(f2).displayFraction() << endl;
    cout << "Difference:  " << f1.Difference(f2).displayFraction() << endl;
    cout << "Product:  " << f1.Product(f2).displayFraction() << endl;
    cout << "Division:  " << f1.Division(f2).displayFraction() << endl;
}

int main()
{	
	int a,b;
	Fraction f1(4,2);
	Fraction f2(5,2);
    	Output(f1, f2);
}
