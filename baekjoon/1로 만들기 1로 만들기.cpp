#include<iostream>

using namespace std;
int dp[1000000];

int main() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int a = 1e9, b = 1e9, c = 1e9;
        if (i % 3 == 0) {
            a = dp[i / 3] + 1;
        }
        if (i % 2 == 0) {
            b = dp[i / 2] + 1;
        }
        c = dp[i - 1] + 1;
        dp[i] = min(min(a, b), c);
    }
    cout << dp[n];
}