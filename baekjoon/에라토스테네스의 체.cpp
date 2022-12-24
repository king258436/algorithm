#include <stdio.h>

int main() {
    int p, i, n, k, arr[1000] = {0},cnt=0;
    scanf("%d %d", &n, &k);
    for (i = 2; i <= n; i++) {
        arr[i] = i;
    }
    while (1) {
        for (i = 2; i <= n; i++) {
            if (arr[i] != 0) {
                p = i;
                break;
            }
        }
        for (i = p; i<=n; i += p) {
            if(arr[i]!=0) cnt++;
            if(cnt==k){
                printf("%d",arr[i]);
                return 0;
            }
            arr[i] = 0;
        }
    }
}