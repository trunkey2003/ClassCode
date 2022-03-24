#pragma once 

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
		double sum(){
			return math + literature + english;
		}
	public:
		void input(){
			
		};
		
		void output(){
		};
};