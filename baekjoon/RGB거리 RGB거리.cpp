#include<iostream>

using namespace std;

int houses[1001][3];
int dp[1001][3];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> houses[i][j];
        }
    }
    for (int i = 0; i < 3; i++) {
        dp[1][i] = houses[1][i];
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            if (j == 0) {
                dp[i][j] = min(dp[i - 1][j + 1], dp[i - 1][j + 2]) + houses[i][j];
            }
            if (j == 1) {
                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j + 1]) + houses[i][j];
            }
            if (j == 2) {
                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j - 2]) + houses[i][j];
            }
        }
    }
    cout << min(min(dp[n][0], dp[n][1]), dp[n][2]);
}