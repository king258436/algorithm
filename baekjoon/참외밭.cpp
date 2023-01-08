#include <stdio.h>
#include <string.h>

int arr[6][2];
int cnt[4];
int main() {
    int k, result;
    int i;
    int b = 1, s = 1;

    scanf("%d", &k);

    for (i = 0; i < 6; i++) {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
        cnt[arr[i][0]]++;
    }

    for (i = 0; i < 6; i++) {
        if (cnt[arr[i][0]] == 1) {
            b *= arr[i][1];
            continue;
        }

        int next = (i + 1) % 6;
        int nextnext = (i + 2) % 6;
        if (arr[i][0] == arr[nextnext][0]) {
            s *= arr[next][1];
        }
    }
    result = (b - s) * k;
    printf("%d", result);
}
