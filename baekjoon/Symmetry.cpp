#include <stdio.h>
#include <math.h>
long long cow=0,cnt=0;

int symmetry(long long n,long long m){
    cnt++;
    if(n%2==0||m%2==0){
        return 1;
    }
    else{
        cow= cow*4+1;
        symmetry((n-1)/2,(m-1)/2);
    }
}

int main(){
    long long n,m;
    scanf("%lld %lld",&n,&m);
    symmetry(n,m);
    printf("%lld",cow);
    return 0;
}