#include <stdio.h>

int main() {
    int arr[999][999], n, num,i,j;
    int x, y;
    int row=-1, col=0;  // 행, 열
    int dir;       // 방향 나타내줌 1이면 더하고 -1 이면 빼고
    int canGo;     // 같은방향으로 몇 번 갈 수 있는지.
    int copy;
    scanf("%d", &n);
    scanf("%d", &num);
    canGo=n;
    copy=n*n;
    dir=1;
    while (copy > 0) {
        for (i=0;i<canGo;i++){
            row= row +dir;
            if(copy==num){
                x=row+1;
                y=col+1;
            }
            arr[row][col]=copy;
            copy=copy-1;
        } 
        canGo=canGo-1;
        for(i=0;i<canGo;i++){
            col=col+dir;
            if(copy==num){
                x=row+1;
                y=col+1;
            }
            arr[row][col]=copy;
            copy=copy-1;
        }
        dir= dir*(-1);
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    printf("%d %d",x,y);
    return 0;
}