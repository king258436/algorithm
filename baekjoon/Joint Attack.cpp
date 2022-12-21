#include <stdio.h>
long long bunza, bunmo;
long long x[40];

void reverse() {
    long long tmp;
    tmp=bunza;
    bunza=bunmo;
    bunmo= tmp;
}

long long recursive(int n) {
    if (n <= 2)
        return 0;
    else {
        reverse();
        bunza= bunmo*x[n-3]+bunza;
    }
    recursive(--n);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &x[i]);
    }
    bunza = x[n - 1] * x[n - 2] + 1;
    bunmo = x[n - 1];
    recursive(n);
    printf("%lld/%lld", bunza, bunmo);
    return 0;
}