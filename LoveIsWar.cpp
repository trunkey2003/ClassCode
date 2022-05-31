#include <iostream>

static int n; // number of friends

using namespace std;

class Friend
{
protected:
    string name;
    int age;
    double time; // time for this friend
    int type;    // 1: banthan, 2: bantrai, 3:bantraikhac
public:
    Friend(){};
    Friend(string name, int age)
    {
        this->name = name;
        this->age = age;
    };
    int getType()
    {
        return type;
    };
    virtual void display()
    {
        cout << "Ten: " << name << ", ";
        cout << "Tuoi: " << age << ", ";
    };
    virtual double calcAndGetTime() = 0;
};

class BestFriend : public Friend
{
private:
    string phoneNumber;

public:
    BestFriend(){};
    BestFriend(string name, int age, string phoneNumber) : Friend(name, age)
    {
        this->phoneNumber = phoneNumber;
        this->type = 1;
    };
    double calcAndGetTime()
    {
        this->time = 5;
        return this->time;
    };
    void display()
    {
        Friend::display();
        cout << "So dien thoai: " << phoneNumber << ", ";
    };
};

class BoyFriend : public Friend
{
private:
    int income;

public:
    BoyFriend(){};
    BoyFriend(string name, int age, int income) : Friend(name, age)
    {
        this->income = income;
        this->type = 2;
    };
    double calcAndGetTime()
    {
        this->time = (this->income * 5) / 10000000;
        return this->time;
    };
    void display()
    {
        Friend::display();
        cout << "Thu nhap: " << income << ", ";
    };
};

class OtherBoy : public Friend
{
private:
    double attractiveness;

public:
    OtherBoy(){};
    OtherBoy(string name, int age, double attractiveness) : Friend(name, age)
    {
        this->attractiveness = attractiveness;
        this->type = 3;
    };
    double calcAndGetTime()
    {
        this->time = (this->attractiveness * 20) / n;
        return this->time;
    };
    void display()
    {
        Friend::display();
        cout << "Do hap dan: " << attractiveness << ", ";
    };
};

double getTimeFromFriendType(Friend **f, int n, int type)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (f[i]->getType() == type)
        {
            sum += f[i]->calcAndGetTime();
        }
    };
    return sum;
};

void findMostImportantFriend(Friend **f, int n)
{
    cout << "Nguoi ban quan trong nhat: ";
    double max = 0;
    for (int i = 0; i < n; i++)
    {
        double time = f[i]->calcAndGetTime();
        if (time > max)
            max = time;
    }
    for (int i = 0; i < n; i++)
    {
        if (f[i]->calcAndGetTime() == max)
            f[i]->display();
    }
}

int main()
{
    cin >> n;

    bool haveBestFriend = false;
    bool haveBoyFriend = false;
    bool haveOtherBoy = false;

    Friend **friends = new Friend *[n];
    int option;
    for (int i = 0; i < n; i++)
    {
        cin >> option;
        switch (option)
        {
        case 1:
        {
            string name;
            int age;
            double time;
            string phoneNumber;
            cin >> name >> age >> phoneNumber;
            friends[i] = new BestFriend(name, age, phoneNumber);
            haveBestFriend = true;
            break;
        }
        case 2:
        {
            string name;
            int age;
            double time;
            int income;
            cin >> name >> age >> income;
            friends[i] = new BoyFriend(name, age, income);
            haveBoyFriend = true;
            break;
        }
        case 3:
        {
            string name;
            int age;
            double time;
            double attractiveness;
            cin >> name >> age >> attractiveness;
            friends[i] = new OtherBoy(name, age, attractiveness);
            haveOtherBoy = true;
            break;
        }
        default:
            i--;
        };
    };

    cout << "Thong ke: " << endl;
    if (haveBestFriend)
    {
        cout << "Thoi gian danh cho ban than: " << getTimeFromFriendType(friends, n, 1) << " h" << endl;
    };
    if (haveBoyFriend)
    {
        cout << "Thoi gian danh cho ban trai: " << getTimeFromFriendType(friends, n, 2) << " h" << endl;
    };
    if (haveOtherBoy)
    {
        cout << "Thoi gian danh cho ban trai khac: " << getTimeFromFriendType(friends, n, 3) << " h" << endl;
    };

    findMostImportantFriend(friends, n);

    return 0;
};
