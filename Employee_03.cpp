#include <iostream>

#define payrollStaffSalaryArg 1000;

using namespace std;

class Employee{
protected:
    string id, fullName, department;
    double salary;
    double type; //1: nhan vien bien che(payroll employee), 2: nhan vien hop dong(contract employee)
public:
    Employee(){};
    Employee(string id, string fullName, string department) : id(id), fullName(fullName), department(department){};
    virtual void input(){
        cout << endl;
        cout << "------------------------------------\n";
        cout << "Input employee : " << endl;
        cout << "ID: ";
        cin >> id;
        cin.ignore();
        cout << "Fullname: ";
        getline(cin, fullName);
        cout << "Department: ";
        getline(cin, department);
    };
    virtual void display(){
        cout << "\n-----------------------------------------------\n";
        cout << "ID: " << id << endl;
        cout << "Full name: " << fullName << endl;
        cout << "Department: " << department << endl;
        cout << "Salary: " << getSalary() << endl;
    };

    virtual double getSalary() = 0;

    string getID(){
        return id;
    };
    
    string getFullName(){
        return fullName;
    };

    string getDepartment(){
        return department;
    };

    double getType(){
        return type;
    };
};

class PayrollStaff : public Employee{
private:
    double coefficientsSalary; //he so luong
    double allowance; // he so phu cap chuc vu
public:
    PayrollStaff(){
        this->type = 1;
    };
    PayrollStaff(string id, string fullName, string department, double coefficientsSalary, double allowance) : Employee(id, fullName, department), coefficientsSalary(coefficientsSalary), allowance(allowance){
        this->type = 1;
    };
    void input(){
        Employee::input();
        cout << "Coefficients salary: ";
        cin >> coefficientsSalary;
        cout << "Allowance: ";
        cin >> allowance;
    };

    void display(){
        Employee::display();
        cout << "Coefficients salary: " << coefficientsSalary << endl;
        cout << "Allowance: " << allowance << endl;
        cout << "\n-----------------------------------------------\n";
    };

    double getSalary(){
        salary = (1 + coefficientsSalary + allowance) * payrollStaffSalaryArg;
        return salary;
    };
    
    double getCoefficientsSalary(){
        return coefficientsSalary;
    };

    double getAllowance(){
        return allowance;
    };
};

class ContractEmployee : public Employee{
private:
    double dailyPay; //tien cong
    double workingDays; //ngay cong
public:
    ContractEmployee(){
        this->type = 2;
    };
    ContractEmployee(string id, string fullName, string department, double dailyPay, double workingDays) : Employee(id, fullName, department), dailyPay(dailyPay), workingDays(workingDays){
        this->type = 2;
    };
    void input(){
        Employee::input();
        cout << "Daily pay: ";
        cin >> dailyPay;
        cout << "Working days: ";
        cin >> workingDays;
    };

    void display(){
        Employee::display();
        cout << "Daily pay: " << dailyPay << endl;
        cout << "Working days: " << workingDays << endl;
        cout << "\n-----------------------------------------------\n";
    };

    double getSalary(){
        salary = dailyPay * workingDays;
        return salary;
    };
    
    double getDailyPay(){
        return dailyPay;
    };

    double getWorkingDays(){
        return workingDays;
    };
};

void handleDisplayPayrollStaffOption1(Employee** employees, int n){
    for (int i = 0; i < n; i++){
        if (employees[i]->getType() == 1){
            PayrollStaff* payrollStaff = (PayrollStaff*)employees[i];
            if (payrollStaff->getCoefficientsSalary() >= 3.5){
                payrollStaff->display();
            }
        }
    };
};

int getNumberOfConstractEmployeeOption2(Employee** employees, int n){
    int count = 0;
    for (int i = 0; i < n; i++){
        if (employees[i]->getType() == 2){
            ContractEmployee* contractEmployee = (ContractEmployee*)employees[i];
            if (contractEmployee->getWorkingDays() == 26){
                count++;
            }
        }
    };
    return count;
};

double getSumOfSalaryPayForKeToanDepartment(Employee** employees, int n){
    double sum = 0;
    for (int i = 0; i < n; i++){
        if (employees[i]->getDepartment() == "Ke toan"){
            sum += employees[i]->getSalary();
        };
    };
    return sum;
};

double getAverageSalaryOfPayrollStaff(Employee** employees, int n){
    double sum = 0;
    int count = 0;
    for (int i = 0; i < n; i++){
        if (employees[i]->getType() == 1){
            PayrollStaff* payrollStaff = (PayrollStaff*)employees[i];
            sum += payrollStaff->getSalary();
            count++;
        };
    };
    return sum / count;
};

double getConstractEmployeeDayOff(Employee** employees, int n){
    int count = 0;
    for (int i = 0; i < n; i++){
        if (employees[i]->getType() == 2){
            ContractEmployee* contractEmployee = (ContractEmployee*)employees[i];
            if (contractEmployee->getWorkingDays() < 26){
                count++;
            }
        }
    };
    return count;
};

void displayHighestCoeficientSalaryEmployees(Employee** employees, int n){
    PayrollStaff* payrollStaff = (PayrollStaff*)employees[0];
    for (int i = 0; i < n; i++){
        if (employees[i]->getType() == 1){
            PayrollStaff* payrollStaff = (PayrollStaff*)employees[i];
            if (payrollStaff->getCoefficientsSalary() > payrollStaff->getCoefficientsSalary()){
                payrollStaff = (PayrollStaff*)employees[i];
            }
        }
    };
    cout << "Cac nhan vien bien che co he so luong lon nhat: " << endl;
    payrollStaff->display();
};

void quickSortEmployeesByID(Employee** employees, int n){
    int i = 0;
    int j = n - 1;
    Employee* pivot = employees[n / 2];
    while (i <= j){
        while (employees[i]->getID() < pivot->getID()){
            i++;
        };
        while (employees[j]->getID() > pivot->getID()){
            j--;
        };
        if (i <= j){
            Employee* temp = employees[i];
            employees[i] = employees[j];
            employees[j] = temp;
            i++;
            j--;
        };
    };
    if (n > 1){
        quickSortEmployeesByID(employees, j);
        quickSortEmployeesByID(employees + i, n - i);
    };
};

void addNewEmployee(Employee** &employees, int &n){
    cout << "Type of new employee: " << endl;
    cout << "Press 1 - Nhan vien bien che" << endl;
    cout << "Press 2 - Nhan vien hop dong" << endl;
    int option = 0;
    cin >> option;
    if (option == 1){
        Employee* payrollStaff = new PayrollStaff();
        payrollStaff->input();
        employees[n] = payrollStaff;
    }
    else if (option == 2){
        Employee* contractEmployee = new ContractEmployee();
        contractEmployee->input();
        employees[n] = contractEmployee;
    }
    else{
        cout << "Wrong option!" << endl;
        return;
    };
    n++;
};

void deleteEmployeeByID(Employee** &employees, int &n){
    string id;
    cout << "Nhap ID can xoa: ";
    cin >> id;
    for (int i = 0; i < n; i++){
        if (employees[i]->getID() == id){
            for (int j = i; j < n - 1; j++){
                employees[j] = employees[j + 1];
            };
            n--;
            break;
        };
    };
};

void displayEmployeeByID(Employee** employees, int n){
    string id;
    cout << "Nhap ID can tim: ";
    cin >> id;
    for (int i = 0; i < n; i++){
        if (employees[i]->getID() == id){
            employees[i]->display();
        };
    };
};

void displayEmployeeByFullName(Employee** employees, int n){
    string fullName;
    cout << "Nhap ho ten can tim: ";
    cin.ignore();
    getline(cin, fullName);
    for (int i = 0; i < n; i++){
        if (employees[i]->getFullName() == fullName){
            employees[i]->display();
        };
    };
};

void displayEmployeeByDepartment(Employee** employees, int n){
    string department;
    cout << "Nhap phong ban can tim: ";
    cin.ignore();
    getline(cin, department);
    for (int i = 0; i < n; i++){
        if (employees[i]->getDepartment() == department){
            employees[i]->display();
        };
    };
};

void displayEmployeeBySalary(Employee** employees, int n){
    double salary;
    cout << "Nhap luong can tim: ";
    cin >> salary;
    for (int i = 0; i < n; i++){
        if (employees[i]->getSalary() == salary){
            employees[i]->display();
        };
    };
};

void displayEmployeeByType(Employee** employees, int n){
    int type;
    cout << "Nhap loai can tim: " << endl;
    cout << "Press 1 - Nhan vien bien che" << endl;
        cout << "Press 2 - Nhan vien hop dong" << endl
             << endl;
    cin >> type;
    for (int i = 0; i < n; i++){
        if (employees[i]->getType() == type){
            employees[i]->display();
        };
    };
};


int main(){
    cout << "\n=======================================Chuong trinh quan ly nhan vien=======================================\n";
    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;

    Employee **employees = new Employee*[n + 1000]; //thêm đc 1000 nhân viên so với nhân viên đã nhập
    int option;

    for(int i = 0; i < n; i++){
        cout << "--------------------------------------------------\n";
        cout << "Type of employee " << i + 1 << ": " << endl;
        cout << "Press 1 - Nhan vien bien che" << endl;
        cout << "Press 2 - Nhan vien hop dong" << endl
             << endl;
        cin >> option;
        switch (option)
        {
        case 1:
        {
            employees[i] = new PayrollStaff();
            employees[i]->input();
            break;
        };
        case 2:
        {
            employees[i] = new ContractEmployee();
            employees[i]->input();
            break;
        };
        default:
            i--;
            break;
        }
        cout << "--------------------------------------------------\n\n";
    };

    option = 0;
    do{
        cout << "\n";
        cout << "Option: " << endl;
        cout << "Press 0: Liet ke danh sach nhan vien" << endl;
        cout << "Press 1: Liet ke cac nhan vien bien che co he so luong tu 3.5 tro len." << endl;
        cout << "Press 2: Dem so luong NVHD co so ngay cong la 26" << endl;
        cout << "Press 3: Tinh tong luong cua cac NV phong ke toan" << endl;
        cout << "Press 4: Tinh trung binh luong cua cac NV bien che" << endl;
        cout << "Press 5: Kiem tra cong ty co NVHD khong di lam ngay nao khong" << endl;
        cout << "Press 6: Tim cac NVBC co he so luong cao nhat." << endl;
        cout << "Press 7: Sap xep cac NV theo ID" << endl;
        cout << "Press 8: Them nhan vien moi." << endl;
        cout << "Press 9: Xoa nhan vien theo ID." << endl;
        cout << "Press 10: Tim nhan vien theo ID." << endl;
        cout << "Press 11: Tim nhan vien theo ten." << endl;
        cout << "Press 12: Tim nhan vien theo phong ban." << endl;
        cout << "Press 13: Tim nhan vien theo luong." << endl;
        cout << "Press 14: Tim nhan vien theo loai." << endl;
        cout << "Press 15: Thoat." << endl;
        cin >> option;
        switch (option)
        {
            case 0:{
                cout << "Danh sach nhan vien: " << endl;
                for (int i = 0; i < n; i++){
                    employees[i]->display();
                };
                break;
            };

            case 1:
            {
                cout << "Danh sach nhan vien bien che co he so luong tu 3.5 tro len: " << endl;
                handleDisplayPayrollStaffOption1(employees, n);
                break;
            };

            case 2:
            {
                cout << "So luong NVHD co so ngay cong la 26: " << endl;
                cout << getNumberOfConstractEmployeeOption2(employees, n);
                break;
            };

            case 3:
            {
                cout << "Tong luong cua cac NV phong ke toan: " << endl;
                cout << getSumOfSalaryPayForKeToanDepartment(employees, n);
                break;
            };

            case 4:
            {
                cout << "Trung binh luong cua cac NV bien che: " << endl;
                cout << getAverageSalaryOfPayrollStaff(employees, n);
                break;
            };

            case 5:
            {
                cout << "Cong ty co NVHD khong di lam ngay nao khong: " << endl;
                cout << getConstractEmployeeDayOff(employees, n);
                break;
            };

            case 6:
            {
                cout << "Cac NVBC co he so luong cao nhat: " << endl;
                displayHighestCoeficientSalaryEmployees(employees, n);
                break;
            };

            case 7:
            {
                cout << "Sap xep cac NV theo ID: " << endl;
                quickSortEmployeesByID(employees, n);
                cout << "Da sort danh sach NV" << endl;
                break;
            };

            case 8:
            {
                cout << "Them nhan vien moi: " << endl;
                addNewEmployee(employees, n);
                break;
            };

            case 9:
            {
                cout << "Xoa nhan vien theo ID: " << endl;
                deleteEmployeeByID(employees, n);
                break;
            };

            case 10:
            {
                cout << "Tim nhan vien theo ID: " << endl;
                displayEmployeeByID(employees, n);
                break;
            };

            case 11:{
                cout << "Tim nhan vien theo ten: " << endl;
                displayEmployeeByFullName(employees, n);
                break;
            };

            case 12:{
                cout << "Tim nhan vien theo phong ban: " << endl;
                displayEmployeeByDepartment(employees, n);
                break;
            };

            case 13:{
                cout << "Tim nhan vien theo luong: " << endl;
                displayEmployeeBySalary(employees, n);
                break;
            };

            case 14:{
                cout << "Tim nhan vien theo loai: " << endl;
                displayEmployeeByType(employees, n);
                break;
            };

            case 15:{
                cout << "Thoat." << endl;
                break;
            };

            default:{
                cout << "Khong co chuc nang nay." << endl;
                break;
            };
        }
    } while(option != 15);

    return 0;
};
