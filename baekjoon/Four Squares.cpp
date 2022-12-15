#include <math.h>
#include <stdio.h>
int main() {
    int n, dp[50001], i, j;
    scanf("%d", &n);
    dp[0] = 0;
    for (i = 1; i <= n; i++) {
        dp[i] = 4;
        for (j = 1; j <= sqrt(i); j++) {
            dp[i] = dp[i] > (dp[i - (j * j)] + 1) ? (dp[i - (j * j)] + 1) : dp[i];
        }
    }
    printf("%d", dp[n]);
}