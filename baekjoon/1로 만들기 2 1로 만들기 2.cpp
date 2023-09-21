#include<iostream>

#define INF 1e9
using namespace std;

int n;
int dp[1000001];
int pre[1000001];

int main() {
    cin >> n;
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        dp[i] = INF;
    }
    for (int i = 2; i <= n; i++) {
        if (dp[i - 1] + 1 < dp[i]) {
            dp[i] = dp[i - 1] + 1;
            pre[i] = i - 1;
        }
        if (i % 2 == 0 && dp[i / 2] + 1 < dp[i]) {
            dp[i] = dp[i / 2] + 1;
            pre[i] = i / 2;
        }
        if (i % 3 == 0 && dp[i / 3] + 1 < dp[i]) {
            dp[i] = dp[i / 3] + 1;
            pre[i] = i / 3;
        }
    }
    cout << dp[n] << '\n';
    cout << n << ' ';
    for (int i = n; i > 1;) {
        cout << pre[i] << ' ';
        i = pre[i];
    }
}