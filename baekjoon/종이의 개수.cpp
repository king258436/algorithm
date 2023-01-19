#include <stdio.h>

int map[2200][2200];
int zero;
int one;
int mone;

void recursive(int x, int y, int n){
    int i,j;
    int _zero=0;
    int _one=0;
    int _mone=0;
    for(i=y;i<y+n;i++){
        for(j=x;j<x+n;j++){
            if(map[j][i]==0) _zero++;
            else if(map[j][i]==1) _one++;
            else if(map[j][i]==-1) _mone++;
        }
    }
    if(_zero==n*n) zero++;
    else if(_one==n*n) one++;
    else if(_mone==n*n) mone++;
    else {
        recursive(x,y,n/3);
        recursive(x+n/3,y,n/3);
        recursive(x+2*n/3,y,n/3);
        recursive(x,y+n/3,n/3);
        recursive(x+n/3,y+n/3,n/3);
        recursive(x+2*n/3,y+n/3,n/3);
        recursive(x,y+2*n/3,n/3);
        recursive(x+n/3,y+2*n/3,n/3);
        recursive(x+2*n/3,y+2*n/3,n/3);
    }
}

int main(){
    int n;
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&map[j][i]);
        }
    }
    recursive(0,0,n);
    printf("%d\n%d\n%d",mone,zero,one);

}