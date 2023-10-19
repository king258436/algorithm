#include<iostream>
#include<string>

using namespace std;

int main() {
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    long long cnt = 0;
    bool flag = false;
    long long result = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            cnt++;
            flag = true;
        } else {
            if (flag == true) {
                result += (cnt - 1);
            }
            flag = false;
            cnt--;
        }
    }
    cout << result;
}