#include <stdio.h>

int n, m;
int result[10];
int visited[10];

void dfs(int depth, int min) {
    if (depth == m) {
        for (int i = 0; i < m; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
    } else {
        for (int i = min; i <= n; i++) {
            if (1) {
                result[depth] = i;
                dfs(depth + 1,i);
            }
        }
    }
}

int main() {
    int i, j;
    scanf("%d %d", &n, &m);
    dfs(0,1);
    return 0;
}