#include <stdio.h>

int main() {
    int n, i, arr[100000] = {0}, cnt = 1, max = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    max = arr[n - 1];
    for (i = n - 1; i >= 0; i--) {
        if (max < arr[i]) {
            cnt++;
            max = arr[i];
        }
    }
    printf("%d", cnt);
    return 0;
}