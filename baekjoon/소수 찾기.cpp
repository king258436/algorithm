#include <stdio.h>
#include <stdlib.h>

int prime(int x){
    if(x==1) return 0;
    for(int i=2;i<x;i++){
        if(x%i==0)return 0;
    }
    return 1;
}
int main(void){
    int n;
    int a;//소수 인지 구별할 인자
    int count=0;//소수 개수 카운트
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        if(prime(a)==1)count++;
    }
    printf("%d",count);
    return 0;
}