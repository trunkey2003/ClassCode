#include <iostream>
#include <string>
using namespace std;

static long long aI[1000000], aJ[1000000];
static long long nJ, nI;

void swap(long long &a, long long &b)
{
    long long temp = a;
    a = b;
    b = temp;
}

void quickSort(long long a[], long long left, long long right)
{
    long long key = a[(left + right) / 2];
    long long i = left, j = right;

    while (i <= j)
    {
        while (a[i] > key)
            i++;
        while (a[j] < key)
            j--;
        if (i <= j)
        {
            if (i < j)
            {
                aI[nI++] = i + 1;
                aJ[nJ++] = j + 1;
                swap(a[i], a[j]);
            };
            i++;
            j--;
        };
    }

    if (left < j)
        quickSort(a, left, j);
    if (i < right)
        quickSort(a, i, right);
}

int main()
{
    long long n;
    long long a[200000];

    cin >> n;

    if (n == 0){
        cout << "Mang rong.";
        return 0;
    }

    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
    };

    cout << "Day truoc khi sap xep: ";
    for (long long i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    };
    cout << endl;

    quickSort(a, 0, n - 1);

    cout << "Day sau khi sap xep: ";
    for (long long i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    };
    cout << endl;

    cout << "Cac hoan vi duoc thuc hien trong Quick Sort: " << endl;
    for (long long i = 0; i < nI; i++){
        cout << aI[i] << " " << aJ[i] << endl;
    }

    return 0;
}
