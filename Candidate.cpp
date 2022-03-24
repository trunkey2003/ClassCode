#include <iostream>
#include "Candidate.h"

using namespace std;

void Candidate::input()
{
	cout << "id: ";
	cin >> id;
    cout << "name: ";
	cin >> name;
    cout <<"dd mm yyyy: ";
	cin >> day >> month >> year;
	cout << "math literature english: ";
    cin >> math >> literature >> english;
}

void Candidate::output(){
    cout << id << "\t";
	cout << name << "\t";
	cout << to_string(day) + "/" + to_string(month) + "/" + to_string(year) << "\t";
	cout << math << "\t";
	cout << literature << "\t";
	cout << english << "\t";
	cout << sum() << "\t";
	cout << endl;
}

int main(){
	Candidate *a = new Candidate[10];
	cout << "Amount of Candidate : ";
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		a[i].input();
	}
	
	cout << "id\t" <<"name\t" << "date of birth\t" << "Math\t" << "Lit\t" << "Eng\t" << "Sum\t" << endl;
	
	for (int i = 0; i < n; i ++){
		if (a[i].sum() > 15) a[i].output();
	}
}
