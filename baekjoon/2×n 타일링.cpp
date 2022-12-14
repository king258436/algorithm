#include <stdio.h>

int main() {
    int n;
    int arr[1001];
    scanf("%d", &n);
    arr[1] = 1;
    arr[2] = 2;
    for (int i = 3; i <= 1000; i++) {
        arr[i] = (arr[i - 1] + arr[i - 2])%10007;
    }
    printf("%d\n", arr[n]);
    return 0;
}