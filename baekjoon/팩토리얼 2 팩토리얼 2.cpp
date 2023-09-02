#include<stdio.h>

long long fac(int n){
    if(n<2){
        return 1;
    }
    return n*fac(n-1);
}

int main(){
    long long n;
    scanf("%lld",&n);
    printf("%lld",fac(n));
}