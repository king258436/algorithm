#include <stdio.h>

char star[400][400];
int len;

void recursive(int n, int x, int y){
    if(n==1){
        star[x][y]='*';
        return ;
    }
    len = 4*(n-1)+1;
    for(int i=y;i<len+y;i++){
        star[x][i]='*';
        star[x+len-1][i]='*';
    }//가로 위 아래
    for(int i=x+1;i<len+x-1;i++){
        star[i][y]='*';
        star[i][y+len-1]='*';
    }//세로 위 아래
    
    recursive(n-1,x+2,y+2);
    return;
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<4*(n-1)+1;i++){
        for(int j=0;j<4*(n-1)+1;j++){
            star[i][j]=' ';
        }
    }// 초기화
    recursive(n,0,0);
    
    for(int i=0;i<4*(n-1)+1;i++){
        for(int j=0;j<4*(n-1)+1;j++){
            printf("%c",star[i][j]);
        }
        printf("\n");
    }
    return 0;
}