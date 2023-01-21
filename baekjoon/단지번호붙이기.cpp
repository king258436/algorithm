#include <stdio.h>
#include <stdlib.h>

int n;
int map[25][25];
int arr[600];
int house_cnt;
int cnt = 1;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int comp(const void* a,const void *b){
    return *(int*)a-*(int*)b;
}

void dfs(int x, int y) {
    int nx, ny;
    int i, j;
    map[x][y] = 0;
    for (i = 0; i < 4; i++) {
        nx = x + dx[i];
        ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < n && ny < n && map[nx][ny] == 1) {
            cnt++;
            dfs(nx, ny);
        }
    }
}

int main() {
    int i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%1d", &map[j][i]);
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (map[j][i] == 1) {
                dfs(j, i);
                arr[house_cnt++] = cnt;
                cnt = 1;
            }
        }
    }
    
    qsort(arr,house_cnt,sizeof(int),comp);

    printf("%d\n", house_cnt);

    for (i = 0; i < house_cnt; i++) {
        printf("%d\n", arr[i]);
    }
    
}