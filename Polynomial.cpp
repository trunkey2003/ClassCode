#include <iostream>

using namespace std;

class Polynomial{
private:
    int degree; //bậc
    int *coefficientsAndConstant; //hệ số và hằng số
public:
    Polynomial();
    Polynomial(int degree);
    friend ostream& operator<<(ostream& os, const Polynomial x);
    friend istream& operator>>(istream& is, Polynomial& x);
    ~Polynomial();
};

Polynomial::Polynomial(){
    this->degree = 0;
    this->coefficientsAndConstant = new int[0];
};

Polynomial::Polynomial(int degree){
    this->degree = degree;
    this->coefficientsAndConstant = new int[degree + 1];
    for (int i = 0; i < degree + 1; i++){
        this->coefficientsAndConstant[i] = 0;
    };
};

ostream& operator<<(ostream& os, const Polynomial x){
    os << "P = ";
    for (int i = 0; i < x.degree; i++){
        os << x.coefficientsAndConstant[i] << "x^" << x.degree - i << " + ";
    };

    os << x.coefficientsAndConstant[0];

    return os;
};

istream& operator>>(istream& is, Polynomial& x){
    for (int i = 0; i < x.degree + 1; i++){
        cin >> x.coefficientsAndConstant[i];
    };

    return is;
}

Polynomial::~Polynomial(){
    delete coefficientsAndConstant;
}


int main()
{
    Polynomial x(2);
    cin >> x;
    cout << x;
    return 0;
};
