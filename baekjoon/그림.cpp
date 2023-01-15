#include <stdio.h>

int map[501][501];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int max, maxcnt, picture;
int n, m;

void dfs(int x, int y) {
    map[x][y]=0;
    maxcnt++;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx > 0 && nx <= m && ny > 0 && ny <= n && map[nx][ny] == 1) {
            dfs(nx, ny);
        }
    }
}

int main() {
    int i, j;
    scanf("%d %d", &n, &m);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            scanf("%d", &map[j][i]);
        }
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (map[j][i] == 1) {
                dfs(j, i);
                picture++;
                if (max < maxcnt) max = maxcnt;
                maxcnt=0;
            }
        }
    }

    printf("%d\n%d", picture, max);
}