#include<iostream>
#include<string>
#include<regex>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string str;
        cin >> str;
        regex pattern("(100+1+|01)+");
        if (regex_match(str, pattern)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}