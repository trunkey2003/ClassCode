#include <iostream>
#include <math.h>
#include <string>

using namespace std;

#define MAXN 100

class PhanSo
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
    PhanSo()
    {
    }

    PhanSo(int n, int d)
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
    
    PhanSo(int n, int d, bool validation)
    {
    	if (validation) {
    		PhanSo(n, d);	
		}
        numerator = n;
       	denominator = d;
    }

    int getNumerator()
    {
        return numerator;
    }

    int getDenominator()
    {
        return denominator;
    }

    PhanSo reducedFraction()
    { 
        int _gcd = gcd(numerator, denominator);
        numerator = numerator / _gcd;
        denominator = denominator / _gcd;
        return PhanSo(numerator, denominator);
    }
    
    string reducedFractionString(){
    	if (denominator == 0) return "Khong thoa yeu cau bai toan";
    	int _gcd = gcd(numerator, denominator);
        numerator = numerator / _gcd;
        denominator = denominator / _gcd;
		if (denominator == 1) return to_string(numerator);
		if (numerator < 0 || denominator < 0) {
			numerator = abs(numerator);
			denominator = abs(denominator);
			return  ("-" + to_string(numerator) + "/" + to_string(denominator));
		}	
        return (to_string(numerator) + "/" + to_string(denominator));
	}

    PhanSo greatestFraction(PhanSo a, PhanSo b)
    {
        double aDouble = a.getNumerator() / a.getDenominator();
        double bDouble = b.getNumerator() / b.getDenominator();
        return (aDouble > bDouble) ? a : b;
    }
    

    PhanSo Sum(PhanSo otherFraction)
    {
        int n = numerator * otherFraction.getDenominator() + otherFraction.getNumerator() * denominator;
        int d = denominator * otherFraction.getDenominator();
        return PhanSo(n / gcd(n, d), d / gcd(n, d));
    }

    PhanSo Difference(PhanSo otherFraction)
    {
        int n = numerator * otherFraction.getDenominator() - otherFraction.numerator * denominator;
        int d = denominator * otherFraction.getDenominator();
        return PhanSo(n / gcd(n, d), d / gcd(n, d));
    }

    PhanSo Product(PhanSo otherFraction)
    {
        int n = numerator * otherFraction.getNumerator();
        int d = denominator * otherFraction.getDenominator();
        return PhanSo(n / gcd(n, d), d / gcd(n, d));
    }

    PhanSo Division(PhanSo otherFraction)
    {
        int n = numerator * otherFraction.getDenominator();
        int d = denominator * otherFraction.getNumerator();
        return PhanSo(n / gcd(n, d), d / gcd(n, d));
    }

    void displayFraction()
    {
        cout << numerator << "/" << denominator << endl;
    }
};

void Nhap(PhanSo* a, int& n){
	cin >> n;
	int numerator;
	int denominator;
	for (int i = 0; i < n; i++){
		cin >> numerator;
		cin >> denominator;
		a[i] = PhanSo(numerator, denominator, false);
	}
}

void Xuat(PhanSo* a, int n){
	for (int i = 0; i < n; i++){
		cout << a[i].reducedFractionString() << endl;
	}
}

int main()
{
    PhanSo a[MAXN];
    int n;
    Nhap(a, n);
    Xuat(a, n);
    return 0;
}
