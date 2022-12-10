#include <stdio.h>
#include <stdlib.h>

int compare(const void *first, const void *second) { return *(int *)first > *(int *)second ? 1 : -1; }

int main() {
    int *time, sum = 0, i, j, n;
    scanf("%d", &n);

    time = (int *)malloc(sizeof(int) * n);

    for (i = 0; i < n; i++) {
        scanf("%d", &time[i]);
    }

    qsort(time, n, sizeof(int), compare);

    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++) {
            sum += time[j];
        }
    }
    printf("%d", sum);
    return 0;
}