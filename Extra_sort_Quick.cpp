void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void quickSort(int a[], int left, int right)
{
    if (left > right)
        return;

    int pivot = a[left];
    int i = left + 1;
    int j = right;

    do
    {
        while ((i <= j) && (a[i] <= pivot))
        {
            i++;
        }

        while ((i <= j) && (a[j] > pivot))
        {
            j--;
        }

        if (i < j)
        {
            swap(a[i], a[j]);
        }
    } while (i <= j);

    swap(a[left], a[j]);
    quickSort(a, left, j - 1);
    quickSort(a, j + 1, right);
};

int main(){
    int n;
    int a[1000];
    
    cin >> n;
    
    for (int i = 0; i < n; i ++){
        cin >> a[i];
    }

    quickSort(a, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }

    return 0;
}
