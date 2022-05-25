#include <iostream>

using namespace std;

#define cowSound "Moooooo!!!"
#define sheepSound "Baaaaa!!!"
#define goatSound "Maaaaa!!!"

class Cattle
{
protected:
    int children; // number of children
    int milk;     // amount of milk
public:
    Cattle()
    {
        children = 0;
        milk = 0;
    };

    int getChildren()
    {
        return children;
    };

    int getMilk()
    {
        return milk;
    };

    virtual string sound(){ return "Some sound!!!";};
    virtual int giveBirth() { return 0; };
    virtual int giveMilk() { return 0; };
};

class Cow : public Cattle
{
public:
    Cow(){};

    string sound()
    {
        return cowSound;
    };

    int giveBirth()
    {
        int newChildren = rand() % 5 + 1;
        children += newChildren;
        return newChildren;
    };

    int giveMilk()
    {
        int newMilk = rand() % 20 + 1;
        milk += newMilk;
        return newMilk;
    };
};

class Sheep : public Cattle
{
public:
    Sheep(){};

    string sound()
    {
        return sheepSound;
    };

    int giveBirth()
    {
        int newChildren = rand() % 5 + 1;
        children += newChildren;
        return newChildren;
    };

    int giveMilk()
    {
        int newMilk = rand() % 5 + 1;
        milk += newMilk;
        return newMilk;
    };
};

class Goat : public Cattle
{
public:
    Goat(){};

    string sound()
    {
        return goatSound;
    };

    int giveBirth()
    {
        int newChildren = rand() % 5 + 1;
        children += newChildren;
        return newChildren;
    };

    int giveMilk()
    {
        int newMilk = rand() % 10 + 1;
        milk += newMilk;
        return newMilk;
    };
};

void inputCattle(Cattle *cattle[100], int &n)
{
    int cows, sheeps, goats;

    cout << "Number of cows: ";
    cin >> cows;
    cout << "Number of sheeps: ";
    cin >> sheeps;
    cout << "Number of goats: ";
    cin >> goats;

    n = cows + sheeps + goats;
    int i = 0;
    int x;

    for (; cows != 0; i++, cows--)
    {
        cattle[i] = new Cow();
    };

    for (; sheeps != 0; i++, sheeps--)
    {
        cattle[i] = new Sheep();
    };

    for (; goats != 0; i++, goats--)
    {
        cattle[i] = new Goat();
    };
};

int main()
{
    Cattle *cattle[500000];
    int n;
    int option;

    cout << "======================================Cattle Management Program======================================\n";
    inputCattle(cattle, n);

    do
    {
        cout << "\n=============================================================\n";
        cout << "Choose one option: " << endl;
        cout << "Press 0 - Display Animal Sound When I Was Leaving" << endl;
        cout << "Press 1 - Display Current Number Of Animals" << endl;
        cout << "Press 2 - Display Current Amount Of Milk" << endl;
        cout << "Press 3 - All Animals Will Give Birth" << endl;
        cout << "Press 4 - All Animals Will Give Milk" << endl;
        cout << "Press 5 - Exit" << endl << endl;
        cin >> option;
        cout << endl;

        switch (option)
        {
        case 0:
        {
            for (int i = 0; i < n; i++)
            {
                cout << cattle[i]->sound() << endl;
            }
            break;
        };

        case 1:
        {
           cout << "Current number of animals: " << n << endl;
           break;
        }
        case 2:
        {
            int totalMilk = 0;
            for (int i = 0; i < n; i++){
                totalMilk += cattle[i]->getMilk();
            }
            cout << "Current amount of milk: " << totalMilk << endl;
            break;
        }
        case 3:
        {
            int nCurrent = n; // number of animals
            for (int i = 0; i < n; i++)
            {
                int newChildren = cattle[i]->giveBirth();
                string sound = cattle[i]->sound();

                if (sound == cowSound)
                {
                    for (int j = nCurrent; j < nCurrent + newChildren; j++)
                    {
                        cattle[j] = new Cow();
                    };
                }
                else if (sound == sheepSound)
                {
                    for (int j = nCurrent; j < nCurrent + newChildren; j++)
                    {
                        cattle[j] = new Sheep();
                    };
                }
                else if (sound == goatSound)
                    for (int j = nCurrent; j < nCurrent + newChildren; j++)
                    {
                        cattle[j] = new Goat();
                    };

                nCurrent += newChildren;
            };

            cout << "Number of animals before all animals giving birth: " << n << endl;
            cout << "Number of animals after all animals giving birth: " << nCurrent << endl;
            cout << "New children: " << nCurrent - n << endl;
            n = nCurrent;
            break;
        }
        case 4:
        {   
            int milkGiven = 0;

            for (int i = 0; i < n; i++){
                milkGiven += cattle[i]->giveMilk();
            };

            cout << "Total milk given: " << milkGiven << endl;
            break;
        }
        case 5:
        {
            exit(0);
            break;
        }
        default:
            exit(0);
            break;
        }
    } while (option != 5);
    return 0;
}
