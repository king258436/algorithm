#include <math.h>
#include <stdio.h>
int r, c;
int cnt;
int flag = 0;
void recursive(int x, int y, int size) {
    if (x == c && y == r) {
        flag = 1;
        return;
    }
    if (x <= c && c < x + size && y <= r && r < y + size) {
        if (flag == 0) recursive(x, y, size / 2);
        if (flag == 0) recursive(x + size / 2, y, size / 2);
        if (flag == 0) recursive(x, y + size / 2, size / 2);
        if (flag == 0) recursive(x + size / 2, y + size / 2, size / 2);
    } else {
        cnt += size * size;
    }
}

int main() {
    int n;
    scanf("%d %d %d", &n, &r, &c);
    recursive(0, 0, (int)pow(2, n));
    printf("%d",cnt);
    return 0;
}