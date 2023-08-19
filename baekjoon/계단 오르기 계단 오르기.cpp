#include<iostream>

using namespace std;
int dp[301][3];
int stairs[301];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> stairs[i];
    }
    dp[1][1] = stairs[1];
    for (int i = 2; i <= n; i++) {
        dp[i][1] = max(dp[i - 2][1], dp[i - 2][2]) + stairs[i];
        dp[i][2] = dp[i - 1][1] + stairs[i];
    }
    cout << max(dp[n][1], dp[n][2]);
}