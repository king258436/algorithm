#include<iostream>
#include<algorithm>

using namespace std;

int n;
int dp[1000][3];
int cost[1000][3];
int result = 2e9;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> cost[i][j];
        }
    }
    for (int first = 0; first < 3; first++) {// first는 첫번째 집의 색을 나타냄
        for (int i = 0; i < 3; i++) {// 첫번째 집의 색깔을 정했으면, dp에서 첫번째집의 색깔만 생각해야 되므로
            if (first == i) {//나머지는 전부다 비용 맥스로 해버림.
                dp[0][i] = cost[0][i];
            } else {
                dp[0][i] = 1e9;
            }
        }
        for (int i = 1; i < n; i++) {
            dp[i][0] = cost[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
            dp[i][1] = cost[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
            dp[i][2] = cost[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
        }
        for (int i = 0; i < 3; i++) {
            if (first == i) {
                continue;
            }
            result = min(result, dp[n - 1][i]);
        }
    }
    cout << result;
}