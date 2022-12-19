#include <stdio.h>
#include <string.h>
typedef int stack;

int main(){
    stack dishes[10000]={0}, wash[10000]={0}, dry[10000]={0};
    int dish_top=-1,wash_top=-1,dry_top=-1,mode,rn,cnt=0;
    int n,i,j,k;
    scanf("%d",&n);
    for(i=n;i>0;i--){
        dish_top++;
        dishes[dish_top]=i;
    }
    while(dry[n-1]==0){
        scanf("%d %d",&mode,&rn);
        if(mode==1){
            for(i=0;i<rn;i++){
                wash_top++;
                wash[wash_top]=dishes[dish_top];
                dish_top--;
            }//dishes 에서 wash 로 rn 만큼 옮긴다.
        }
        else{
            for(i=0;i<rn;i++){
                dry_top++;
                dry[dry_top]=wash[wash_top];
                wash_top--;
            }
        }
    }
    for(i=0;i<n;i++){
        printf("%d\n",dry[dry_top]);
        dry_top--;
    }
    return 0;
}