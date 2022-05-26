void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
};

void selectionSort(int a[], int n)
{
    cout << "Mang truoc khi sap xep la: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl << endl;
    for (int i = 0; i < n - 1; i++){
        int maxIndex = i;
        cout << "i=" << i << ":" << endl << endl;
        for (int j = i + 1; j < n; j++){
            if (a[j] > a[maxIndex]){
                maxIndex = j; 
            };
        };
        cout << "Max = a[" << maxIndex << "]" << " = " << a[maxIndex] << endl << endl;
        cout << "Mang sau khi sap xep " << i + 1 << " phan tu dau tien la: ";
        swap(a[i], a[maxIndex]);
        for (int j = 0; j < n; j++){
            cout << a[j] << " ";
        };

        cout << endl << endl;
    }
    cout << "Mang sau khi sap xep la: ";
    for (int i =0; i < n; i++){
        cout << a[i] << " ";
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

    selectionSort(a, n);

    return 0;
}
