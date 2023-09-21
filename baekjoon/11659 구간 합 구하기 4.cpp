#include<iostream>

using namespace std;
int dp[100001];
int arr[100001];

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        if (i == 1) {
            dp[i] = arr[i];
        } else {
            dp[i] = dp[i - 1] + arr[i];
        }
    }
    while (m--) {
        int i, j;
        cin >> i >> j;
        cout << dp[j] - dp[i - 1] << '\n';
    }
}