#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define max(a,b)  (((a) > (b)) ? (a) : (b))

int main() {
    int n, dp[301]={0}, score[301]={0};
    scanf("%d", &n);

    score[0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &score[i]);
    }
    dp[0] = 0;
    dp[1] = score[1];
    dp[2] = score[1] + score[2];
    for (int i = 3; i <= n; i++) {
        dp[i] = max(dp[i - 2] + score[i], dp[i - 3] + score[i - 1] + score[i]);
    }
    printf("%d", dp[n]);
    return 0;
}