#include <stdio.h>

int main() {
    int arr[1000];
    int n;
    scanf("%d", &n);
    arr[0] = 1;
    arr[1] = 3;
    for (int i = 2; i < n; i++) {
        arr[i] = (arr[i - 2] * 2 + arr[i - 1])%10007;
    }
    printf("%d",arr[n-1]);
    return 0;
}