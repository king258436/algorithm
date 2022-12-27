#include <stdio.h>

int main(){
    int n,a,b,cnt=0;
    scanf("%d %d %d",&n,&a,&b);
    while(a!=b){
        if(a%2==1){
            a=a+1;
        }
        if(b%2==1){
            b=b+1;
        }
        a/=2;
        b/=2;
        cnt++;
    }
    printf("%d",cnt);
}