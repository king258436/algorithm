#include <stdio.h>

int n, m;
int graph[500][500];
int visited[500][500];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int Fx[4][4] = {{0, 0, 0, 1}, {0, 1, 2, 1}, {0, 0, 0, -1}, {0, -1, 0, 1}};
int Fy[4][4] = {{0, 1, 2, 1}, {0, 0, 0, 1}, {0, 1, 2, 1}, {0, 1, 1, 1}};

int max;

void dfs(int x, int y, int depth, int sum) {
    int nx, ny;
    if (depth == 3) {
        if (sum > max) max = sum;
    } else {
        for (int i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                if (visited[nx][ny] == 0) {
                    visited[nx][ny] = 1;
                    dfs(nx, ny, depth + 1, sum + graph[nx][ny]);
                    visited[nx][ny] = 0;
                }
            }
        }
    }
}

void likeFUCKYOU(int x,int y){
    for(int i=0;i<4;i++){
        int sum=0;
        for(int j=0;j<4;j++){
            int nx=x+Fx[i][j];
            int ny=y+Fy[i][j];
            if(nx>=0&&ny>=0&&nx<m&&ny<n){
                sum=sum+graph[nx][ny];
            }
        }
        if(sum>max) max=sum;
    }
}

int main() {
    int i, j;
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &graph[j][i]);
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            visited[j][i] = 1;
            dfs(j, i, 0, graph[j][i]);
            visited[j][i] = 0;
            likeFUCKYOU(j,i);
        }
    }
    printf("%d", max);
}