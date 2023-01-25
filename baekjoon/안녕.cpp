#include <stdio.h>

typedef struct _lf{
    int Life;
    int Joy;
}LJ;

int value[22][102];
LJ LandJ[21];

int max(int a, int b){
    if(a>b) return a;
    else return b;
}

int main(){
    int n;
    int i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&LandJ[i].Life);
    }
    for(i=1;i<=n;i++){
        scanf("%d",&LandJ[i].Joy);
    }
    
    for(i=1;i<=n;i++){
        for(j=1;j<100;j++){
            int Li=LandJ[i].Life;
            int Ji=LandJ[i].Joy;

            if(Li>j) value[i][j]=value[i-1][j];
            else {
                value[i][j]=max(value[i-1][j],Ji+value[i-1][j-Li]);
            }
        }
    }
    printf("%d",value[n][99]);
}