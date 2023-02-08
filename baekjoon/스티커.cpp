#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, Tc, c;
    cin >> Tc;
    for (int c = 0; c < Tc; c++) {
        cin >> n;
        vector<vector<int> > vec(2, vector<int>(n));
        vector<vector<int> > dp(2, vector<int>(n,0));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                cin >> vec[i][j];
            }
        }
        dp[0][0] = vec[0][0];
        dp[1][0] = vec[1][0];
        dp[0][1] = vec[0][1] + dp[1][0];
        dp[1][1] = vec[1][1] + dp[0][0];
        for (int i = 2; i < n; i++) {
            dp[0][i] = vec[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
            dp[1][i] = vec[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
        }
        cout << max(dp[1][n - 1], dp[0][n - 1]) << "\n";
    }
}