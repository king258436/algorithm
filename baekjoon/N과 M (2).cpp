#include <stdio.h>

int n, m;
int result[10];
int visited[10];

void dfs(int at, int depth) {
    if (depth == m) {
        for (int i = 0; i < m; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
    } else {
        for (int i = at; i <= n; i++) {
            if (visited[i] == 0) {
                result[depth] = i;
                visited[i] = 1;
                dfs(i+1,depth + 1);
                visited[i]=0;
            }
        }
    }
}

int main() {
    int i, j;
    scanf("%d %d", &n, &m);
    dfs(1,0);
    return 0;
}