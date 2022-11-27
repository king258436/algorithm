#include <stdio.h>

int main(){
    int m,n;//세로와 가로
    char chess[50][50];
    int min =32;//8*8일때 32 이상을 고쳐야 한다면 다른걸로 바꾸는게 이득임
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%s",chess[i]);
    }

    for(int i=0;i<n-7;i++){
        for(int j=0;j<m-7;j++){
            int cntB=0,cntW=0;
            for(int a=i;a<i+8;a++){
                for(int b=j;b<j+8;b++){
                    if((a+b)%2==0){
                        if(chess[a][b]=='B') cntW++;
                        else cntB++;
                    }
                    else {
                        if(chess[a][b]=='B') cntB++;
                        else cntW++;
                    }
                }
            }
            min = min > cntW ? cntW : min;
            min = min > cntB ? cntB : min;
        }
    }
    printf("%d",min);
    return 0;
}