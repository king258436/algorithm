#include <math.h>
#include <stdio.h>
#include <string.h>

int main() {
    int n;
    long long count = 0,arr[51];
    scanf("%d", &n);
    arr[0]=1;
    arr[1]=1;
    for(int i=2;i<=50;i++){
        arr[i]=(arr[i-1]+arr[i-2]+1)%1000000007;
    }
    printf("%lld", arr[n]);
    return 0;
}