#include <iostream>
#include <string>

using namespace std;

int main() {
    string str, sub;
    getline(cin, str);
    getline(cin, sub);
    int idx = 0;
    int cnt = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == sub[0] && i + sub.length()-1 <= str.length()-1) {
            if (str.substr(i, sub.length()) == sub) {
                cnt++;
                i+=sub.length()-1;
            }
        }
    }
    cout << cnt;
}