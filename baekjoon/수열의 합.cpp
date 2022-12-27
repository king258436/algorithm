#include <math.h>
#include <stdio.h>

int main() {
    int N, L, d, i, j;
    scanf("%d %d", &N, &L);
    for (i = L; i <= 100; i++) {
        if ((N - (i - 1) * i / 2) % i != 0) continue;
        d = (N - (i - 1) * i / 2) / i;
        if(d<0) break;
        for (j = 0; j < i; j++) {
            printf("%d ", d + j);
        }
        return 0;
    }
    printf("-1");
    return 0;
}