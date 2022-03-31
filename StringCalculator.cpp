//+ - * /
//input 1+2*3/4-5
//output -2.5

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

bool isAOS(char s) //return true if s is Arithmetic Operator Signs
{
    string sign = "+-*/%^";
    for (int i = 0; i < 5; i++){
        if (s == sign[i]) return true;
    }
    return false;
}

void spilitSignAndNumber(string s, vector<string>& v){
    int markBegin = 0;
    for (int i = 0; i < s.length(); i++){
        if (isAOS(s[i+1]) || i == s.length() - 1){
            v.push_back(s.substr(markBegin, i - markBegin + 1));
            if (i != s.length() - 1) v.push_back(s.substr(i+1, 1));
            markBegin = i + 2; 
        }
    }
}

double calculateVectorString(vector<string> v){
    if (v.size() <= 1) return stod(v[0]);
    int markBI = 0;
    int markEI = 0;
    double temp = 0;
    double result = 0;
    int j = 0;
    for (int i = 0; i < v.size(); i++){
        if (i + 1 < v.size() && (v[i+1] == "*" || v[i+1] == "/")){
            markBI = i;
            temp = stod(v[markBI]);
            j = i + 2;
            do{
                temp *= (v[j-1] == "*")? stod(v[j]) : 1/stod(v[j]);
                markEI = j;
                j = j + 2;
            } while(j < v.size() && (v[j-1] == "*" || v[j-1] == "/"));
            i = markEI+1;
            if (markBI != 0 && v[markBI-1] == "-") temp = -temp;
            result += temp;
            temp = 0;
            if (i >= v.size()) break;
        }

        if (i % 2 == 0) {
            if(i != 0 && v[i-1] == "-") result -= stod(v[i]); else result += stod(v[i]);
        }
    }
    return result;
}

int main()
{
    string s;
    vector<string> v;
    cin >> s;

    //number at even index - "+-*/" at odd index
    spilitSignAndNumber(s, v);

    double res = calculateVectorString(v);
    cout << res;
}
