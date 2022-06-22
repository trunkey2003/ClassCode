#include <iostream>

using namespace std;

void selectionSort(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int max = i;

        for (int j = i + 1; j < n; j++)
            if (a[j] > a[max])
                max = j;

        swap(a[max], a[i]);
    }
};

void insertionSort(int *a, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] < key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

void quickSort(int *a, int n)
{
    if (n <= 1)
        return;
    int pivot = a[n / 2];
    int i = 0, j = n - 1;
    while (i <= j)
    {
        while (a[i] > pivot)
            i++;
        while (a[j] < pivot)
            j--;
        if (i <= j)
            swap(a[i++], a[j--]);
    };
    quickSort(a, j + 1);
    quickSort(a + j + 1, n - j - 1);
};

void mergeSort(int *a, int n)
{
    if (n <= 1)
        return;
    int mid = n / 2;
    mergeSort(a, mid);
    mergeSort(a + mid, n - mid);
    int *temp = new int[n];
    int i = 0, j = mid, k = 0;
    while (i < mid && j < n)
    {
        if (a[i] > a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    };
    while (i < mid)
        temp[k++] = a[i++];
    while (j < n)
        temp[k++] = a[j++];
    for (i = 0; i < n; i++)
        a[i] = temp[i];
    delete[] temp;
};

void heapify(int *a, int n, int i)
{
    int l = 2 * i + 1, r = 2 * i + 2, min = i;
    if (l < n && a[l] < a[min])
        min = l;
    if (r < n && a[r] < a[min])
        min = r;
    if (min != i)
    {
        swap(a[i], a[min]);
        heapify(a, n, min);
    };
};

void heapSort(int *a, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    };
};

int main()
{
    int a[100] = {2, 0, 7, 6, 8, 0, 3, 5, 3, 1, 9, 4};
    int n = 12;

    cout << "\nBefore sort: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    };

    mergeSort(a, n);

    cout << "\nAfter sort: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    };
};
