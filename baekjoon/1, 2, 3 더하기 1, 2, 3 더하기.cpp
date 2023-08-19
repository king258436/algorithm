#include<iostream>

using namespace std;
int dp[12];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        for (int i = 4; i <= n; i++) {
            int sum = 0;
            if (i - 1 >= 0) {
                sum += dp[i - 1];
            }
            if (i - 2 >= 0) {
                sum += dp[i - 2];
            }
            if (i - 3 >= 0) {
                sum += dp[i - 3];
            }
            dp[i] = sum;
        }
        cout << dp[n] << '\n';
    }
}