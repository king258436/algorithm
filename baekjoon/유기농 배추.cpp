#include <stdio.h>
#include <string.h>

int map[51][51];
int cnt, m, n;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y) {
        map[x][y] = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < m && nx >= 0 && ny < n && ny >= 0 && map[nx][ny] == 1) {
            dfs(nx, ny);
        }
    }
}

int main() {
    int k, T;
    int x, y;
    int i, j, l;
    scanf("%d",&T);
    for (i = 0; i < T; i++) {
        scanf("%d %d %d", &m, &n, &k);

        for (j = 0; j < k; j++) {
            scanf("%d %d", &x, &y);
            map[x][y] = 1;
        }

        for (j = 0; j < m; j++) {
            for (l = 0; l < n; l++) {
                if (map[j][l] == 1) {
                    dfs(j, l);
                    cnt++;
                }
            }
        }
        printf("%d\n", cnt);
        cnt = 0;
    }
}