void insertionSort(int a[], int n)
{
    cout << "Mang truoc khi sap xep la: ";

    for (int i =0; i < n; i++){
        cout << a[i] << " ";
    };

    cout << endl;

    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
 
        while (j >= 0 && a[j] < key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        };

        cout << "Vi tri chen cua a[" << i <<"] la " << j + 1 << endl;
        a[j + 1] = key;

        for (int j = 0; j < n; j++){
            cout << a[j] << " ";
        }

        cout << endl;
    }
};

int main(){
    int n;
    int a[1000];
    
    cin >> n;
    
    if (n == 0){
        cout << "Mang rong.";
        return 0;
    }
    
    for (int i = 0; i < n; i ++){
        cin >> a[i];
    }

    insertionSort(a, n);

    cout << "Mang sau khi sap xep la: ";

    for (int i = 0; i < n; i ++){
        cout << a[i] << " ";
    }

    return 0;
}
