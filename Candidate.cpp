#include <iostream>
#include "h"

using namespace std;

void Candidate::input()
{
    cin >> name;
    cin >> id;
    cin >> day >> month >> year;
    cin >> math >> literature >> english;
}

void Candidate::output(){
    cout << "id\t" <<"Fullname\t" << "Date Of birth\t" << "Math\t" << "Literature\t" << "English\t" << endl;
    cout << id << "\t";
	cout << name << day + "/" + month + "/" + year << "\t";
	cout << math << "\t";
	cout << literature << "\t";
	cout << english << "\t";
}

int main(){
	Candidate a;
	a.input();
}