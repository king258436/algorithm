#include <math.h>
#include <stdio.h>

int main() {
    int n, d, cnt = 0;
    scanf("%d %d", &n, &d);
    for (int i = 1; i <= n; i++) {
        int ex = i;
        int j = 0;
        while (ex > 0) {
            // printf("%d ",ex);
            if (ex %10  == d) {
                cnt++;
            }
            ex /= 10;
            j++;
            // printf("%d ",ex);
        }
    }
    printf("%d", cnt);
    return 0;
}