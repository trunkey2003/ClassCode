#include <iostream>
#include <math.h>

using namespace std;

static long long aI[200000], aJ[200000];
static long long nI = 0, nJ = 0;

void save(long long i, long long j)
{
    aI[nI++] = i;
    aJ[nJ++] = j;
};

void displaySavedData()
{
    cout << "Cac hoan vi duoc thuc hien trong heap: " << endl;
    for (long long i = 0; i < nI; i++)
    {
        cout << aI[i] << " " << aJ[i] << endl;
    }
};

class MinHeap
{
public:
    long long *arr;
    long long capacity;
    long long size;

    MinHeap(long long cap)
    {
        size = cap;
        capacity = cap;
        arr = new long long[cap];
    }

    void printArray()
    {
        for (long long i = 0; i < capacity; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    long long left(long long i)
    {
        return (2 * i + 1);
    }

    long long right(long long i)
    {
        return (2 * i + 2);
    }
    long long getMin()
    {
        return arr[0];
    }
    void heapify(long long i, bool needDisplay = false)
    {
        long long l = left(i);
        long long r = right(i);
        long long smallest = i;
        if (l < size && arr[l] < arr[i])
            smallest = l;
        if (r < size && arr[r] < arr[smallest])
            smallest = r;
        if (smallest != i)
        {
            if (needDisplay)
                save(i, smallest);
            swap(arr[i], arr[smallest]);
            heapify(smallest, needDisplay);
        }
    }
    long long handleMin()
    {
        if (size <= 0)
            return 999999999;
        if (size == 1)
        {
            size--;
            return arr[0];
        }

        long long root = arr[0];
        arr[0] = arr[size - 1];
        size--;
        heapify(0);
        return root;
    }

    void getUnsortedArray()
    {
        for (long long i = 0; i < capacity; i++)
            cin >> arr[i];
    }

    void heapSort()
    {
        long long temp[capacity];
        for (long long j = 0; j < capacity; j++)
        {
            temp[j] = handleMin();
        };

        for (long long i = capacity - 1; i >= 0; i--)
        {
            cout << temp[i] << " ";
        };

        cout << endl;
    };

    ~MinHeap()
    {
        delete arr;
    }
};

int main()
{
    long long s;
    cin >> s;
    MinHeap obj(s);
    obj.getUnsortedArray();

    cout << "Day truoc khi sap xep: ";
    obj.printArray();

    for (long long i = s / 2 - 1; i >= 0; i--)
    {
        obj.heapify(i, true);
    }

    cout << "Day sau khi sap xep: ";
    obj.heapSort();

    displaySavedData();
}
