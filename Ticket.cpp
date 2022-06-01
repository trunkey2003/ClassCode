#include <iostream>

using namespace std;

#define fullTicketPrice 200000
#define entryTicketPrice 70000
#define gameTicketPrice 20000

class Ticket
{
protected:
	string id;
	string fullName;
	int YOB; //year of birth
	int games; //amount of games this person particapated in
	int price; //price of the ticket
	int type; //0 : Full Ticket, 1 : Spilit Ticket
public:
	Ticket(){};

	Ticket(string id, string fullName, int YOB)
	{
		this->id = id;
		this->fullName = fullName;
		this->YOB = YOB;
	};

	int getType()
	{
		return type;
	}

	virtual void input(){
		cout << "Enter the id: ";
		cin >> id;
		cout << "Enter the full name: ";
		cin.ignore();
		getline(cin, fullName);
		cout << "Enter the year of birth: ";
		cin >> YOB;
		cout << "Enter the amount of games: ";
		cin >> games;
		calcAndGetPrice();
	};

	virtual void output(){
		cout << "\n-----------------------------------------------\n";
		cout << "ID: " << id << endl;
		cout << "Full name: " << fullName << endl;
		cout << "Year of birth: " << YOB << endl;
		cout << "Game: " << games << endl;
		cout << "Price: " << price << endl;
		cout << "-----------------------------------------------\n";
	};

	virtual int calcAndGetPrice() = 0;
};

class FullTicket : public Ticket
{
public:
	FullTicket(){
		this->type = 0;
	};

	FullTicket(string id, string fullName, int YOB) : Ticket(id, fullName, YOB)
	{
		this->type = 0;
	};

	void input(){
		Ticket::input();
	};

	void output(){
		Ticket::output();
	};

	int calcAndGetPrice(){
		this->price = fullTicketPrice;
		return this->price;
	};
};

class SpilitTicket : public Ticket
{
public:
	SpilitTicket(){
		this->type = 1;
	};

	SpilitTicket(string id, string fullName, int YOB) : Ticket(id, fullName, YOB)
	{
		this->type = 1;
	};

	void input(){
		Ticket::input();
	};

	void output(){
		Ticket::output();
	};

	int calcAndGetPrice(){
		this->price = entryTicketPrice + gameTicketPrice * games;
		return this->price;
	};
};


int parkRevenue(Ticket** tickets, int n){
	int sum = 0;
	for (int i = 0; i < n; i++){
		sum += tickets[i]->calcAndGetPrice();
	};
	return sum;
};

int countSpilitTicket(Ticket** tickets, int n){
	int count = 0;
	for (int i = 0; i < n; i++){
		if (tickets[i]->getType() == 1){
			count++;
		};
	};
	return count;
};


int main() {
	int n;
	cin >> n;
	Ticket** ticketsList = new Ticket*[n];
	
	int option;

	for (int i = 0; i < n; i++){
		cout << "\nEnter the type of ticket: " << endl;
		cout << "1. Full ticket" << endl;
		cout << "2. Spilit ticket\n" << endl;
		cin >> option;
		if (option == 1){
			ticketsList[i] = new FullTicket();
		}
		else if (option == 2){
			ticketsList[i] = new SpilitTicket();
		};
		ticketsList[i]->input();
	};

	for (int i = 0; i < n; i++){
		ticketsList[i]->output();
	};

	cout << "Dam Sen Park revenue: " << parkRevenue(ticketsList, n) << endl;
	cout << "Number of spilit ticket: " << countSpilitTicket(ticketsList, n) << endl;
	return 0;
};
