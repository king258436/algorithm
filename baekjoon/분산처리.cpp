#include <math.h>
#include <stdio.h>

int main() {
    int t, result, a, b;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d %d", &a, &b);
        result = 1;
        for (int j = 0; j < b; j++) {
            result = result * a % 10;
        }
        if (result == 0) result = 10;
        printf("%d\n", result);
    }
    return 0;
}