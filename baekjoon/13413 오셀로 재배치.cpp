#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int num;
        cin >> num;
        string str;
        string str_wanabe;
        int diff = 0;
        int B = 0, W = 0;
        cin >> str;
        cin >> str_wanabe;
        for (int i = 0; i < num; i++) {
            if (str[i] != str_wanabe[i]) {
                diff++;
                if (str[i] == 'B') {
                    B++;
                } else if (str[i] == 'W') {
                    W++;
                }
            }
        }

        cout << diff - min(B, W) << '\n';
    }
}