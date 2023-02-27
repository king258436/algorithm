#include <iostream>

using namespace std;

int dp[1001];
int arr[1001];
int Max;
int main() {
    int n;
    int i, j;
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            int sum = dp[i-j] + arr[j];
            if (sum > Max) Max = sum;
        }
        dp[i] = Max;
    }
    cout << dp[n];
}
