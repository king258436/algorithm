#include<iostream>

#define INF 1e9
using namespace std;
int dp[1000001];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        dp[i] = INF;
    }
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 1; i <= n; i++) {
        if (i + 1 <= n) {
            dp[i + 1] = min(dp[i + 1], dp[i] + 1);
        }
        if (i * 2 <= n) {
            dp[i * 2] = min(dp[i * 2], dp[i] + 1);
        }
        if (i * 3 <= n) {
            dp[i * 3] = min(dp[i * 3], dp[i] + 1);
        }
    }
    cout << dp[n];
}