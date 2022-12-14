#include <stdio.h>

int main() {
    long long arr[100001], sum = 0,temp;
    int n, m, Section_I, Section_J, i, j;

    scanf("%d %d", &n, &m);  // n, m 입력받음.
    for (i = 1; i <= n; i++) {
        scanf("%lld", &temp);  // 각 idx까지의 합을 입력받음.
        arr[i]=sum+temp;
        sum+=temp;
    }
    for (i = 0; i < m; i++) {
        scanf("%d %d", &Section_I, &Section_J); // i와 j입력받음.
        printf("%lld\n",arr[Section_J]-arr[Section_I-1]);
    }
    return 0;
}