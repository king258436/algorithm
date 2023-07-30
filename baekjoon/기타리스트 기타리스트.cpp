#include<iostream>
#include<cstring>

using namespace std;
int n, m, s;
int arr[51];
bool dp[51][1001];

int main() {
    int result = -1;
    cin >> n >> s >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    dp[0][s] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (dp[i - 1][j] == true) {
                if (j + arr[i] <= m) {
                    dp[i][j + arr[i]] = true;
                }
                if (j - arr[i] >= 0) {
                    dp[i][j - arr[i]] = true;
                }
            }
        }
    }
    for (int i = 0; i <= m; i++) {
        if (dp[n][i]) {
            result = max(result, i);
        }
    }
    cout << result;
}