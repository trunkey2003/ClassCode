int handleStringInput(string s){
    return stoi(s.substr(0, s.find(" ")));
}

void swap(string &a, string &b)
{
    string temp = a;
    a = b;
    b = temp;
}

void bubbleSort(string arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (handleStringInput(arr[j]) > handleStringInput(arr[j + 1]))
                swap(arr[j], arr[j + 1]);
}

int main(){
    int n = 0;
    string x;

    string plantPotPosition[1000];
    
    while (true){
        getline(cin, x);
        if (!isdigit(x[1])) break;
        plantPotPosition[n++] = x;
    }

    bubbleSort(plantPotPosition, n);

    cout << 1 << endl;

    for (int i = 0; i < n; i++) {
        if (i > 0 && handleStringInput(plantPotPosition[i]) - handleStringInput(plantPotPosition[i - 1]) > 500) cout << 2 << endl;
        cout << plantPotPosition[i] << endl;
    }

    return 0;
}
