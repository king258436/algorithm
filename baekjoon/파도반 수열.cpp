#include <stdio.h>

int main() {
    int i, t, n;
    long long arr[100];
    for (i = 0; i < 5; i++) {
        if (i < 3) {
            arr[i] = 1;
        } else
            arr[i] = 2;
    }
    for (i = 5; i < 100; i++) {
        arr[i] = arr[i - 1] + arr[i - 5];
    }

    scanf("%d", &t);
    for (i = 0; i < t; i++) {
        scanf("%d", &n);
        printf("%lld\n", arr[n - 1]);
    }
    return 0;
}