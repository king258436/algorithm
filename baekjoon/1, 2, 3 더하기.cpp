#include <stdio.h>

int main() {
    int dp[11], i, n, t;

    scanf("%d", &t);
    dp[3]=4;
    for (i = 0; i < 3; i++) {
            dp[i] = i;
        }
        for (i = 4; i <= 10; i++) {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
    for (int j = 0; j < t; j++) {
        scanf("%d",&n);
        printf("%d\n", dp[n]);
    }
}