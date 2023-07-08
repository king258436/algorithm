#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main() {
    string str;
    cin >> str;
    int lCnt = 0;
    bool flag = 0;
    int res = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') {
            lCnt++;
            flag = true;
        } else {
            if (flag) {
                lCnt--;
                res += lCnt;
            } else {
                res++;
                lCnt--;
            }
            flag = false;
        }
    }
    cout << res;
}