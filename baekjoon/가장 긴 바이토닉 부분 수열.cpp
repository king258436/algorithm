#include <algorithm>
#include <iostream>

using namespace std;

int arr[1000];
int dp[1000];
int rdp[1000];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        rdp[i] = 1;
        for (int j = n - 1; j > i; j--) {
            if (arr[i] > arr[j]) rdp[i] = max(rdp[i], rdp[j] + 1);
        }
    }

    int max = 1;
    for (int i = 0; i < n; i++) {
        if (dp[i] + rdp[i] > max) max = dp[i] + rdp[i];
    }
    cout << max - 1;
}