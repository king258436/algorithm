#include <stdio.h>

int main(){
    int x,stick=64,cnt=1,sum=64;
    scanf("%d",&x);
    while(stick>1){
        if(sum==x){
            break;
        }
        else if(sum-stick/2<x){
            stick/=2;
            cnt++;
        }
        else {
            stick/=2;
            sum-=stick;
        }
    }
    printf("%d",cnt);
}