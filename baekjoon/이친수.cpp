#include <stdio.h>

int main(){
    int n;
    long long arr[91]={0};
    scanf("%d",&n);
    arr[0]=1;
    arr[1]=1;
    for(int i=2;i<=90;i++){
        arr[i]=arr[i-1]+arr[i-2];
    }
    printf("%lld",arr[n-1]);
}