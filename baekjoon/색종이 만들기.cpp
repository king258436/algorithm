#include <stdio.h>

int map[128][128];

int result_w,result_b;

void recursive(int x,int y, int n){
    int wcnt=0, bcnt=0;
    int i,j;
    for(i=x;i<x+n;i++){
        for(j=y;j<y+n;j++){
            if(map[i][j]==0){
                wcnt++;
            }
            else bcnt++;
        }
    }
    if(wcnt==n*n){
        result_w++;
        return;
    }
    else if(bcnt==n*n){
        result_b++;
        return;
    }
    if(n==1) return;
    else{
        recursive(x,y,n/2);
        recursive(x+n/2,y,n/2);
        recursive(x,y+n/2,n/2);
        recursive(x+n/2,y+n/2,n/2);
    }
}

int main(){
    int n;
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&map[i][j]);
        }
    }
    recursive(0,0,n);
    printf("%d\n%d",result_w,result_b);
    return 0;
}