int main(){
    int n;
    cin >> n;

    string timeString[1000];
    int timeInt[1000];
    
    for (int i = 0; i < n; i++) {
        cin >> timeString[i];
    }

    for (int i = 0; i < n; i++){
        timeInt[i] = stoi(timeString[i].substr(0, 2)) * 3600 + stoi(timeString[i].substr(3,2)) * 60 + stoi(timeString[i].substr(6,2));
    }

    

    for (int i = 0; i < n; i++){
        int minIndex = 0;
        for (int j = 0; j < n; j++){
            if (timeInt[minIndex] > timeInt[j]) minIndex = j;
        };
        cout << timeString[minIndex] << endl;
        timeInt[minIndex] = 9999999;
    }

    return 0;
}
