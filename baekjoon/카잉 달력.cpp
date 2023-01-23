#include <stdio.h>

int main() {
    int n, m, x, y, gcd, max;
    int t;
    int i, j;
    scanf("%d", &t);

    for (i = 0; i < t; i++) {
        int cnt,flag=0;

        scanf("%d %d %d %d", &m, &n, &x, &y);

        for (j = 1; j <= m && j <= n; ++j) {
            if (m % j == 0 && n % j == 0) {
                gcd = j;
            }
        }

        max = (n * m) / gcd;

        for(j=x;j<=max;j+=m){
            int ny=j%n;
            if(ny==0){
                ny=n;
            }
            if(ny==y){
                flag=1;
                cnt=j;
            }
        }
        if(flag==1) printf("%d\n",cnt);
        else printf("-1\n");
    }
    return 0;
}