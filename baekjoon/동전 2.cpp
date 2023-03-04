#include <iostream>
#define INF 1e9
using namespace std;
int arr[101];
int dp[100001];
int main() {
    int n, k;
    int i, j;
    cin >> n >> k;
    for (i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for (i = 1; i <= k; i++) dp[i] = INF;
    for (i = 1; i <= n; i++) {
        dp[arr[i]] = 1;
    }
    for (i = 1; i <= n; i++) {
        for (j = arr[i]; j <= k; j++) {
            dp[j] = min(dp[j], dp[j - arr[i]] + 1);
        }
    }
    if(dp[k]==INF) cout<<-1;
    else cout << dp[k];
}