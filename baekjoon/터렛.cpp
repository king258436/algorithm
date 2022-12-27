#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct point {
    int x;
    int y;
    int r;
} pt;

int main() {
    pt a, b;
    int n, result;
    double d;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d %d %d", &a.x, &a.y, &a.r, &b.x, &b.y, &b.r);
        d = pow(a.x - b.x, 2) + pow(a.y - b.y, 2);
        d = sqrt(d);
        if (a.x == b.x && a.y == b.y && a.r == b.r) {
            result = -1;
        } 
        else if (a.r + b.r > d && d > abs(a.r - b.r)) {
            result = 2;
        } 
        else if (a.r + b.r == d || abs(a.r - b.r) == d) {
            result = 1;
        }
        else result = 0;
        printf("%d\n", result);
    }
    return 0;
}