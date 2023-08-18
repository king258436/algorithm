#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, cnt = 0, *dp;
    scanf("%d", &n);

    dp = (int*)malloc((n+1) * sizeof(int));

    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+1;
        if(i%2==0){
            if(dp[i]>dp[i/2]){
                dp[i]=dp[i/2]+1;
            }
        }
        if(i%3==0){
            if(dp[i]>dp[i/3]){
                dp[i]=dp[i/3]+1;
            }
        }
    }
    printf("%d", dp[n]);
    return 0;
}