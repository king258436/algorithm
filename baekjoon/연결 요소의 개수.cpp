#include <stdio.h>

int graph[1001][1001];
int visited[1001];

void dfs(int cur, int n) {
    visited[cur] = 1;
    for (int i = 1; i <= n; i++) {
        if (graph[cur][i] == 1 && visited[i] == 0) {
            dfs(i, n);
        }
    }
}

int main() {
    int n, m;
    int i, j;
    int a, b;
    int cnt = 0;
    scanf("%d %d", &n, &m);
    for (i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    for (i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            dfs(i, n);
            cnt++;
        }
    }
    printf("%d", cnt);
}