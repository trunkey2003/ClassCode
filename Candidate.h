#pragma once 
#include<string>

using namespace std;

class Candidate{
	private:
		string name;
		int id;
		int day;
		int month;
		int year;
		double math;
		double literature;
		double english;
		
	public:
		void input();
		
		void output();
		
		double sum(){
			return math + literature + english;
		}
};
