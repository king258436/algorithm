#include <stdio.h>
#include <stdlib.h>

int broken[10];

int check(int n) {
    if (n == 0) {
        if (broken[0]) {
            return 0;
        }
        else {
            return 1;
        }
    }
    int len = 0;
    while (n > 0) {
        if (broken[n % 10]) return 0;
        n = n / 10;
        len += 1;
    }

    return len;
}

int main() {
    int n,m;
    scanf("%d",&n);
    scanf("%d",&m);
    for (int i = 0; i < m; i++) {
        int j;
        scanf("%d",&j);
        broken[j] = 1;
    }

    int result = abs(n-100);

    for (int i = 0; i <= 1000000; i++) {
        int c = i;
        int len = check(c);
        if (len > 0) {
            int press = abs(c - n);
            if (result > press + len)
                result = press + len;
        }
    }
    printf("%d",result);
    return 0;
}