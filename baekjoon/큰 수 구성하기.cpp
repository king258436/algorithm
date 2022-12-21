#include <stdio.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))

int result = 0, k, n, arr[10];

void recursive(int num, int ten) {
    if (num > n) return ;
    result = max(result, num);
    for (int i = 0; i < k; i++) {
        recursive(num + arr[i] * ten, ten * 10);
    }
}
int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &arr[i]);
    }
    recursive(0, 1);
    printf("%d", result);
    return 0;
}