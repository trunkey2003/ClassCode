#include <iostream>
#include "Candidate.h"

using namespace std;

void Candidate::input()
{
	cout << "id: ";
	cin >> id;
    cout << "name(without space): ";
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
void input(Candidate* a, int& n){
	cout << "Amount of Candidate : ";
	cin >> n;
	for (int i = 0; i < n; i++){
		a[i].input();
	}
}

void output(Candidate* a, int n){
	cout << "id\t" <<"name\t" << "date of birth\t" << "Math\t" << "Lit\t" << "Eng\t" << "Sum\t" << endl;
	
	for (int i = 0; i < n; i ++){
		if (a[i].sum() > 15) a[i].output();
	}
}

int main(){
	int n;
	Candidate *a = new Candidate[10];
	input(a,n);
	output(a,n);
}
