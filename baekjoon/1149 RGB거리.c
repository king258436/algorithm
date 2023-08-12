#include <stdio.h>

int dp[1001][3];
int input[1001][3];
int n;
int result;

int min(int a, int b) {
    if (a > b)
        return b;
    else
        return a;
}

int main() {
    int i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d %d %d", &input[i][0], &input[i][1], &input[i][2]);
    }
    for (i = 0; i < 3; i++) {
        dp[0][i] = input[0][i];
    }
    for (i = 1; i < n; i++) {
        dp[i][0] = min(dp[i - 1][1] + input[i][0], dp[i - 1][2] + input[i][0]);
        dp[i][1] = min(dp[i - 1][0] + input[i][1], dp[i - 1][2] + input[i][1]);
        dp[i][2] = min(dp[i - 1][0] + input[i][2], dp[i - 1][1] + input[i][2]);
    }
    result = min(dp[n-1][0],dp[n-1][1]);
    result = min(result,dp[n-1][2]);
    printf("%d",result);
    return 0;
}