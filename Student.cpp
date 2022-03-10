#include <iostream>

using namespace std;

class Student
{
private:
    string fullName;
    double mathPoint;
    double literaturePoint;
public:
    Student(){}

    Student(string fullName, double mathPoint, double literaturePoint){
        this->fullName = fullName;
        this->mathPoint = mathPoint;
        this->literaturePoint = literaturePoint;
    }

    string getFullName(){
        return fullName;
    }

    double getMathPoint(){
         return mathPoint;
    }

    double getLiteraturePoint(){
        return literaturePoint;
    }

    double getAveragePoint(){
        return (mathPoint + literaturePoint) / 2;
    }
};

void inputDate(string &fullName, double &mathPoint, double &literaturePoint)
{
    cout << "Input [fullName] [mathPoint] [literaturePoint] : \n";
    cout << "Student's fullname : ";
	getline (cin,fullName); 
	cout << "Student's math point : ";
    cin >> mathPoint;
    cout << "Student's literature point : ";
    cin >> literaturePoint;

}

void outputDate(Student s)
{
	cout << endl;
    cout << "Student : " << s.getFullName() << "\nMath Point : " << s.getMathPoint() << "\nLiterature Point : " << s.getLiteraturePoint();
    cout << "\nAverage point : " << s.getAveragePoint();
}

int main()
{
	string fullName;
    double mathPoint, literaturePoint;
    inputDate(fullName, mathPoint, literaturePoint);
    Student s1(fullName, mathPoint, literaturePoint);
    outputDate(s1);
}
