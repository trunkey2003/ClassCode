int main(){
    string x;
    string phoneString[10000];
    int phoneInt[10000];
    int n = 0;
    
    while (true){
        cin >> x;
        if (!isdigit(x[1])) break;
        phoneString[n++] = x;
    }

    for (int i = 0; i < n; i++){    
        phoneInt[i] = stoi(phoneString[i].substr(3, 7)); 
    }

    

    for (int i = 0; i < n; i++){
        int minIndex = 0;
        for (int j = 0; j < n; j++){
            if (phoneInt[minIndex] > phoneInt[j]) minIndex = j;
        };
        cout << phoneString[minIndex] << endl;
        phoneInt[minIndex] = 10000000;
    }

    return 0;
}
