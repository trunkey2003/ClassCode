#include <iostream>

using namespace std;

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void quickSort(int a[], int left, int right)
{
    // base case
    if (left > right) return;

    int pivot = a[left];
    int i = left + 1;
    int j = right;

    do{
        while ((i <= j) && (a[i] <= pivot)){
            i++;
        }
        
        while ((i <= j) && (a[j] > pivot)){
            j--;
        }
        
        if (i < j){
            swap(a[i], a[j]);
        }
    } while(i <= j);

    //i surpassed j
    swap(a[left], a[j]);
    quickSort(a, left, j-1);
    quickSort(a, j+1, right);
}
 
int main()
{
 
    int arr[] = { 9, 3, 4, 2, 1, 8 };
    int n = 6;
 
    quickSort(arr, 0, n - 1);
 
    // cout << "n : " << n;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
 
    return 0;
}
