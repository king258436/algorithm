#include <stdio.h>

int main() {
    int t;
    int a, b, c;
    int min;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d %d %d", &a, &b, &c);
        min = a;
        if (min > b) min = b;
        if (min > c) min = c;
        printf("%d\n", min);
    }
    return 0;
}