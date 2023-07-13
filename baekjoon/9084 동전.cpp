#include<iostream>
#include<cstring>
using namespace std;

int main() {
    int t;
    int coin[21] = {0,};
    int dp[10001];
    cin >> t;
    while (t--) {
        memset(dp, 0, sizeof(dp));
        int n, m;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> coin[i];
        }
        cin >> m;
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (j >= coin[i]) {
                    dp[j] = dp[j] + dp[j - coin[i]];
                }
            }
        }
        cout << dp[m] << '\n';
    }
}