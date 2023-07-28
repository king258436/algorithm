#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
string s1;
string s2;

int main() {
    cin >> s1 >> s2;
    while (s2.size() != s1.size()) {
        if (s2[s2.size() - 1] == 'A') {
            s2.erase(s2.size() - 1, 1);
        } else if (s2[s2.size() - 1] == 'B') {
            s2.erase(s2.size() - 1, 1);
            reverse(s2.begin(), s2.end());
        }
    }
    if (s2 == s1) {
        cout << 1;
    } else {
        cout << 0;
    }
    return 0;
}