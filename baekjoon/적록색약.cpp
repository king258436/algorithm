#include <stdio.h>
#include <string.h>

int n;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int map[101][101];
int visited[101][101];
int rgweek, nomal;
int r, g, b;

void dfs(int x, int y, int color) {
    visited[x][y]=1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];  // next x
        int ny = y + dy[i];  // next y
        if(nx>=0&&nx<n&&ny>=0&&ny<n&&visited[nx][ny]==0&&map[nx][ny]==color){
            dfs(nx,ny,color);
        }
    }
}

void rgwdfs(int x, int y){
    visited[x][y]=1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];  // next x
        int ny = y + dy[i];  // next y
        if(nx>=0&&nx<n&&ny>=0&&ny<n&&visited[nx][ny]==0&&(map[nx][ny]==1||map[nx][ny]==2)){
            rgwdfs(nx,ny);
        }
    }
}

int main() {
    int i, j;
    char temp;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf(" %c", &temp);
            if (temp == 'R')
                map[j][i] = 1;  // R은 1로 저장되고
            else if (temp == 'G')
                map[j][i] = 2;  // G는 2로 저장되고
            else if (temp == 'B')
                map[j][i] = 3;  // B는 3으로 저장된다.
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(map[j][i]==1&&visited[j][i]==0){
                dfs(j,i,1);
                r++;
            }
            else if(map[j][i]==2&&visited[j][i]==0){
                dfs(j,i,2);
                g++;
            }
            else if(map[j][i]==3&&visited[j][i]==0){
                dfs(j,i,3);
                b++;
            }
        }
    }
    nomal =r+g+b;
    r=g=b=0;
    for(i=0;i<n;i++){
        memset(visited[i],0,sizeof(int)*n);
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if((map[j][i]==1||map[j][i]==2)&&visited[j][i]==0){
                rgwdfs(j,i);
                r++;
            }
            else if(map[j][i]==3&&visited[j][i]==0){
                dfs(j,i,3);
                b++;
            }
        }
    }
    rgweek = r+b;

    printf("%d %d",nomal, rgweek);
}
