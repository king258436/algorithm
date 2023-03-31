#include <iostream>
#include <string>

using namespace std;

int t;

int funcLeft(string a,int idx) {  // 해당문자열이 팰린드롬이면 리턴 1 아니면 리턴 0
    string temp=a;
    temp.erase(idx, 1);
    for (int i = 0; i < temp.length() / 2; i++) {
        if (temp[i] != temp[temp.length() - 1 - i]) {
            return 0;
        }
    }
    return 1;
}

int funcRight(string a,int idx) {  // 해당문자열이 팰린드롬이면 리턴 1 아니면 리턴 0
    string temp=a;
    temp.erase(temp.length() - 1 - idx, 1);
    for (int i = 0; i < temp.length() / 2; i++) {
        if (temp[i] != temp[temp.length() - 1 - i]) {
            return 0;
        }
    }
    return 1;
}

    int IsPallin(string a) {
    int idx;
    int notPalin = 0;
    // 팰린드롬 수는 0 유사 팰린 1 아예아니면 2
    for (int i = 0; i < a.length() / 2; i++) {
        if (a[i] != a[a.length() - 1 - i]) {
            notPalin = 1;
            idx = i;
            break;
        }
    }

    if (notPalin == 0)
        return 0;

    else if (notPalin == 1) {
        if (a[idx + 1] == a[a.length() - 1 - idx] && a[idx] == a[a.length() - 2 - idx]) {
            if(funcLeft(a,idx)==1) return 1;
            else if(funcRight(a,idx)== 1) return 1;
            else return 2;
        }
        if (a[idx + 1] == a[a.length() - 1 - idx]) {
            a.erase(idx, 1);
        } else if (a[idx] == a[a.length() - 2 - idx]) {
            a.erase(a.length() - 1 - idx, 1);
        } else
            return 2;
    }
    for (int i = 0; i < a.length() / 2; i++) {
        if (a[i] != a[a.length() - 1 - i]) {
            return 2;
        }
    }
    return 1;
}

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        string str;
        cin >> str;
        int result = IsPallin(str);
        cout << result << '\n';
    }
}