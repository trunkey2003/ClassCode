#include <iostream>

#define developerOTSalary 200000
#define testerBonusSalary 50000

using namespace std;

class Employee
{
protected:
    string id, fullName, phoneNumber, email;
    int age;
    int baseSalary;
    long long salary = 0;

public:
    Employee(){};

    Employee(string id, string fullName, string phoneNumber, string email, int age, int baseSalary) : id(id), fullName(fullName), phoneNumber(phoneNumber), email(email), age(age), baseSalary(baseSalary){};

    virtual void input()
    {
        cout << endl;
        cout << "------------------------------------\n";
        cout << "Input employee : " << endl;
        cout << "ID: ";
        cin >> id;
        cin.ignore();
        cout << "Fullname: ";
        getline(cin, fullName);
        cout << "Phone number: ";
        cin >> phoneNumber;
        cout << "Email: ";
        cin >> email;
        cout << "Age: ";
        cin >> age;
        cout << "Base salary: ";
        cin >> baseSalary;
    };

    virtual void display()
    {
        cout << "\n-----------------------------------------------\n";
        cout << "ID: " << id << endl;
        cout << "Full name: " << fullName << endl;
        cout << "Phone number: " << phoneNumber << endl;
        cout << "Email: " << email << endl;
        cout << "Age: " << age << endl;
        cout << "Base salary: " << baseSalary << endl;
        cout << "Salary: " << getSalary() << endl;
        cout << "-----------------------------------------------\n";
    };

    virtual int getSalary() = 0;
};

class Developer : public Employee
{
private: 
    int OTTime;
public: 
    Developer()
    {
        OTTime = 0;
    };

    void input()
    {
        Employee::input();
        cout << "OT time: ";
        cin >> OTTime;
    };

    int getSalary()
    {
        salary = baseSalary + OTTime * developerOTSalary;
        return salary;
    };
};

class Tester : public Employee
{
private:
    int bugsFound;
public: 
    Tester()
    {
        bugsFound = 0;
    };

    void input()
    {
        Employee::input();
        cout << "Bugs found: ";
        cin >> bugsFound;
    };

    int getSalary()
    {
        salary = baseSalary + bugsFound * testerBonusSalary;
        return salary;
    };
};

void inputEmployees(Employee *employees[100], int n)
{
    for (int i = 0; i < n; i++)
    {
        int type;
        cout << "--------------------------------------------------\n";
        cout << "Type of employee " << i + 1 << ": " << endl;
        cout << "Press 1 - Developer " << endl;
        cout << "Press 2 - Tester " << endl
             << endl;
        cin >> type;
        switch (type)
        {
        case 1:
        {
            employees[i] = new Developer();
            employees[i]->input();
            break;
        };
        case 2:
        {
            employees[i] = new Tester();
            employees[i]->input();
            break;
        };
        default:
            i--;
            break;
        }
        cout << "--------------------------------------------------\n\n";
    };
};

int main()
{
    int n;
    int option;
    Employee **employees;

    cout << "======================================Employee Management Program======================================\n";
    cout << "Amount of employees: " << endl;
    cin >> n;

    employees = new Employee*[n];
    inputEmployees(employees, n);

    do
    {
        cout << "\n=============================================================\n";
        cout << "Choose one option: " << endl;
        cout << "Press 1 - Display Employees List." << endl;
        cout << "Press 2 - Display Employees Whose Salary Lower Than Average Salary" << endl;
        cout << "Press 3 or any key - Exit" << endl;
        cout << endl;
        cin >> option;
        cout << endl;
        switch (option)
        {
        case 1:
        {
            for (int i = 0; i < n; i++)
            {
                employees[i]->display();
            };
            break;
        };

        case 2:
        {
            double averageSalary = 0;
            for (int i = 0; i < n; i++)
            {
                averageSalary += employees[i]->getSalary();
            };
            averageSalary /= n;

            cout << "Average salary :" << averageSalary << endl;

            cout << "Employee with salary lower than average salary: " << endl;
            for (int i = 0; i < n; i++)
            {
                if (employees[i]->getSalary() < averageSalary)
                {
                    employees[i]->display();
                };
            };
            break;
        };

        case 3:
        {
            return 0;
        };

        default:
            exit(0);
        };
    } while (option != 3);

    return 0;
};
