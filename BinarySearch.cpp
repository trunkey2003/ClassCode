#include <iostream>

using namespace std;

int binarySearch(int* arr, int left, int right, int x){
    if (right >= left){
        int mid = left + (right - left) / 2;
        if (arr[mid] == x) return mid;
        if (arr[mid] > x) return binarySearch(arr, left, mid - 1, x);
        return binarySearch(arr, mid + 1, right, x);
    }
    return -1;
}
