#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T, b;
    cin >> T;
    while (T--) {
        string str;
        int sum = 0;
        cin >> b;
        cin >> str;
        for (int i = 0; i < str.length(); i++) {
            sum += str[i] - '0';
        }
        cout << sum % (b - 1) << '\n';
    }
}