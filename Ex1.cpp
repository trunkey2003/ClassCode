#include <iostream>

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
            cout << "ERROR: ATTEMPTING TO DIVIDE BY ZERO" << endl;
            exit(0); // will terminate the program if division by 0 is attempted
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
        double aDouble = a.getNumerator() / a.getDenominator();
        double bDouble = b.getNumerator() / b.getDenominator();
        return (aDouble > bDouble)? a : b;
    }
    
    Fraction Sum(Fraction otherFraction)
    {
        int n = numerator*otherFraction.getDenominator()+otherFraction.getNumerator()*denominator;
        int d = denominator*otherFraction.getDenominator();
        return Fraction(n/gcd(n,d),d/gcd(n,d));
    }
    
    Fraction Difference(Fraction otherFraction)
    {
        int n = numerator*otherFraction.getDenominator()-otherFraction.numerator*denominator;
        int d = denominator*otherFraction.getDenominator();
        return Fraction(n/gcd(n,d),d/gcd(n,d));
    }
    
    Fraction Product(Fraction otherFraction)
    {
        int n = numerator*otherFraction.getNumerator();
        int d = denominator*otherFraction.getDenominator();
        return Fraction(n/gcd(n,d),d/gcd(n,d));
    }
    
    Fraction Division(Fraction otherFraction)
    {
        int n = numerator*otherFraction.getDenominator();
        int d = denominator*otherFraction.getNumerator();
        return Fraction(n/gcd(n,d),d/gcd(n,d));
    }
    
    void displayFraction(){
    	cout << numerator << "/" << denominator;
	}
};

int main()
{	
	int a,b;
	Fraction f1(4,2);
	Fraction f2(5,2);
	cout << "Sum: " << f1.Sum(f2).getNumerator() << "/" << f1.Sum(f2).getDenominator() << endl;
	cout << "Difference: " << f1.Difference(f2).getNumerator() << "/" << f1.Difference(f2).getDenominator() << endl;
	cout << "Product: " << f1.Product(f2).getNumerator() << "/" << f1.Product(f2).getDenominator() << endl;
	cout << "Division: " << f1.Division(f2).getNumerator() << "/" << f1.Division(f2).getDenominator() << endl;
}