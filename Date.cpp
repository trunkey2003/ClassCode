#include <iostream>

using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;
    int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool isLeapYear(int year)
    {
        if (year % 400 == 0)
            return true;
        if (year % 4 == 0 && year % 100 != 0)
            return true;
        return false;
    }
    bool isValidDate(int d, int m, int y)
    {
        if (y < 0) return false;
        if (m < 1 || m > 12) return false;
        if (d < 1 || d > 31) return false;
        if (m == 2)
        {
            if (isLeapYear(y))
                return (d <= 29);
            else
                return (d <= 28);
        }
        if (m == 4 || m == 6 ||
            m == 9 || m == 11)
            return (d <= 30);
        return true;
    }

public:
    Date(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
        
        if (!isValidDate(day, month, year)) {
            cout << "Invalidated Date ";
            exit(0);
        }

        if (isLeapYear(year))
            monthDays[2 - 1] = 29;
    }

    int getDay()
    {
        return day;
    }

    int getMonth()
    {
        return month;
    }

    int getYear()
    {
        return year;
    }
    
    Date nextDate(){
    	int day = this->day;
    	int month = this->month;
    	int year = this->year;
    	if (day == monthDays[month-1]){
    		day = 1;
    		month++;
		} else day++;
		if (month == 13){
			month = 1;
			year++;
		}
		return Date(day, month, year);
	}
};

void inputDate(int &day, int &month, int &year)
{
    cout << "Input [day] [month] [year] with space : ";
    cin >> day >> month >> year;
}

void outputDate(Date a)
{
    cout << "Next date is " << a.getDay() << "/" << a.getMonth() << "/" << a.getYear();
}

int main()
{
    int day, month, year;
    inputDate(day, month, year);
    Date d1(day, month, year);
    outputDate(d1.nextDate());
}