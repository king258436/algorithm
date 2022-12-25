#include <stdio.h>
#include <string.h>

int main() {
    long long n,i,a=0;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        a+=i;
    }
    printf("%d",a);
    return 0;
}
