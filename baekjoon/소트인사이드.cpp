#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comp(const void* a, const void* b) {
    if (*(long long*)a > *(long long*)b)
        return -1;
    else
        return 1;
}

int main() {
    long long n, arr[11], copy,cnt=0;
    scanf("%lld", &n);
    copy = n;

    for (int i = 0; copy > 0; i++) {
        arr[i] = copy % 10;
        copy = copy / 10;
        cnt++;
    }

    qsort(arr, cnt, sizeof(long long), comp);

    for (int i = 0; i < cnt ; i++) {
        printf("%lld", arr[i]);
    }
}