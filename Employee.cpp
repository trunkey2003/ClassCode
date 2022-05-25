#include <iostream>

using namespace std;

class Employee
{
protected:
    string id, fullName, DOB;
    long long salary = 0;

public:
    Employee(){};

    Employee(string id, string fullName, string DOB) : id(id), fullName(fullName), DOB(DOB){};

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
        cout << "Date of birth: ";
        cin >> DOB;
    };

    virtual void display()
    {
        cout << endl;
        cout << "------------------------------------------------------------\n";
        cout << "ID: " << id << endl;
        cout << "Full name: " << fullName << endl;
        cout << "Date of birth: " << DOB << endl;
    };

    virtual int getSalary()
    {
        return 0;
    };
};

class FactoryWorker : public Employee
{
private:
    int baseSalary;
    int amountOfProduct;

public:
    FactoryWorker()
    {
        baseSalary = 0;
        amountOfProduct = 0;
    };

    void input()
    {
        Employee::input();
        cout << "Base salary: ";
        cin >> baseSalary;
        cout << "Amount of product: ";
        cin >> amountOfProduct;
        salary = baseSalary + amountOfProduct * 5000;
        calcSalary();
    };

    void display()
    {
        Employee::display();
        cout << "Salary: " << salary << endl;
        cout << "Base salary: " << baseSalary << endl;
        cout << "Amount of product: " << amountOfProduct << endl;
        cout << "------------------------------------------------------------\n";
    };

    void calcSalary()
    {
        salary = baseSalary + amountOfProduct * 5000;
    };

    int getSalary()
    {
        return salary;
    };
};

class OfficeWorker : public Employee
{
private:
    int daysOfWork;

public:
    OfficeWorker()
    {
        daysOfWork = 0;
    };

    void input()
    {
        Employee::input();
        cout << "Days of work: ";
        cin >> daysOfWork;
        calcSalary();
    };

    void display()
    {
        Employee::display();
        cout << "Salary: " << salary << endl;
        cout << "Days of work: " << daysOfWork << endl;
        cout << "------------------------------------------------------------\n";
    };

    void calcSalary()
    {
        salary = daysOfWork * 100000;
    };

    int getSalary()
    {
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
        cout << "Press 1 - Factory Worker " << endl;
        cout << "Press 2 - Office Worker " << endl
             << endl;
        cin >> type;
        switch (type)
        {
        case 1:
        {
            employees[i] = new FactoryWorker();
            employees[i]->input();
            break;
        };
        case 2:
        {
            employees[i] = new OfficeWorker();
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

void quickSort(Employee *employees[100], int left, int right)
{
    if (left > right)
        return;

    int pivot = employees[left]->getSalary();
    int i = left + 1;
    int j = right;

    do
    {
        while ((i <= j) && (employees[i]->getSalary() > pivot))
        {
            i++;
        }

        while ((i <= j) && (employees[j]->getSalary() <= pivot))
        {
            j--;
        }

        if (i < j)
        {
            swap(employees[i], employees[j]);
        }
    } while (i <= j);

    swap(employees[left], employees[j]);
    quickSort(employees, left, j - 1);
    quickSort(employees, j + 1, right);
};

int main()
{
    int n;
    int option;
    Employee *employees[1000];

    cout << "======================================Employee Management Program======================================\n";
    cout << "Amount of employees: ";
    cin >> n;

    inputEmployees(employees, n);

    do
    {
        cout << "\n=============================================================\n";
        cout << "Choose one option: " << endl;
        cout << "Press 1 - Display Employees List." << endl;
        cout << "Press 2 - Display Total Payroll To Employees" << endl;
        cout << "Press 3 - Display Highest-Paid Employee." << endl;
        cout << "Press 4 - Display Lowest-Paid Employee." << endl;
        cout << "Press 5 - Sort & Display Employees List." << endl;
        cout << "Press 6 or any key - Exit" << endl;
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
            long long total = 0;
            for (int i = 0; i < n; i++)
            {
                total += employees[i]->getSalary();
            };
            cout << "Total Payroll To Employees: " << total << endl;
            break;
        };

        case 3:
        {
            int maxIndex = 0;

            for (int i = 0; i < n; i++)
            {
                if (employees[i]->getSalary() > employees[maxIndex]->getSalary())
                    maxIndex = i;
            };

            cout << "Highest-Paid Employee: " << endl;

            employees[maxIndex]->display();

            break;
        };

        case 4:
        {
            int minIndex = 0;

            for (int i = 0; i < n; i++)
            {
                if (employees[i]->getSalary() < employees[minIndex]->getSalary())
                    minIndex = i;
            };

            cout << "Lowest-Paid Employee: " << endl;

            employees[minIndex]->display();

            break;
        };

        case 5:
        {
            quickSort(employees, 0, n - 1);
            for (int i = 0; i < n; i++)
            {
                employees[i]->display();
            };
            break;
        };

        case 6:
        {
            return 0;
        }

        default:
            exit(0);
            break;
        };
    } while (option != 6);

    return 0;
};
