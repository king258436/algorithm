#include <stdio.h>

int main() {
    int n, k, i, cnt = 0;
    int money_value[11]={0,};

    scanf("%d %d", &n, &k);

    for (i = 1; i <= n; i++) {
        scanf("%d", &money_value[i]);
    }  // 오름차순으로 입력댐.
    for (i = n; i > 0; i--) {
        while (k >= money_value[i]) {
            k -= money_value[i];
            cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}