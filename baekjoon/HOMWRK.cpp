#include <stdio.h>
int main() {
    int T, n, a, b;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d", &n);
        for (int j = 0; j < n; j++) {
            scanf("%d %d", &a, &b);
            printf("%d %d\n", a + b, a * b);
        }
    }
    return 0;
}