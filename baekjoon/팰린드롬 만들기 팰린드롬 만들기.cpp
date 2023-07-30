#include<iostream>
#include<cstring>

using namespace std;
int arr[5001];
int dp[5001][5001];

int func(int st, int end) {
    if (dp[st][end] == -1) {
        if (st == end) {
            dp[st][end] = 0;
        } else if (st > end) {
            dp[st][end] = 0;
        } else if (arr[st] == arr[end]) {
            dp[st][end] = func(st + 1, end - 1);
        } else {
            dp[st][end] = min(func(st + 1, end) + 1, func(st, end - 1) + 1);
        }
    }
    return dp[st][end];
}

int main() {
    int n;
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << func(0, n - 1);
}