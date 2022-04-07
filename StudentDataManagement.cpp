// Student Data Management
#include <iostream>


using namespace std;

class SubjectPoint{
protected: 
	double linearAlgebra;
	double calculus;
	double dsaa; //Data structures and algorithms
	double oop; //Object Oriented Programming
	double itl; //Introduction to law
	double mlp; //Marxist-Leninist philosophy
	double mlpe; //Marxist Leninist political economy

	double avg(){
		double sum = linearAlgebra + calculus + dsaa + oop + itl + mlp + mlpe;
		return sum / 4;
	} 

	void input(){
		cout << endl;
		cout << "-------Subject Point------" << endl;
		cout << "Linear Algebra: "; cin >> linearAlgebra;
		cout << "Calculus: "; cin >> calculus;
		cout << "Data structures and algorithms: "; cin >> dsaa;
		cout << "Object Oriented Programming: "; cin >> oop;
		cout << "Introduction to law: "; cin >> itl;
		cout << "Marxist-Leninist philosophy: "; cin >> mlp;
		cout << "Marxist Leninist political economy: "; cin >> mlpe;
	}
};

class Student : SubjectPoint
{
private:
    string fullName;
	string id;
public:
    Student(){
	}

	void input(){
		cout << "---------------Student Data Managemen------------" << endl;
		cout << "Full name: "; cin >> fullName;
		cout << "id: "; cin >> id;
		SubjectPoint::input();
	}

    string getFullName(){
        return fullName;
    }

    double getlinearAlgebra(){
         return linearAlgebra;
    }

    double getcalculus(){
        return calculus;
    }

    double getAveragePoint(){
        return (linearAlgebra + calculus) / 2;
    }
};

int main(){
	Student s;
	s.input();
	return 0;
}


