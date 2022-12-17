#include <stdio.h>

int main(){
    int x,y,n,c,garo,sero;
    scanf("%d %d",&n,&c);
    garo=n;
    sero=n;
    for(int i=0;i<c;i++){
        scanf("%d %d",&x,&y);
        if(x>=garo||y>=sero||x==0||y==0) continue;;
        if(x*sero>=y*garo){
            garo =x;
        } 
        else sero=y;
    }
    printf("%d",garo*sero);
    return 0;
}