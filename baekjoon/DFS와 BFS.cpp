#include <stdio.h>

#define max 1001

int graph[max][max];
int discovered[max];
int visited[max];

typedef struct _queue {
    int front;
    int rear;
    int data[max];
} queue;

void BFS(int cur, int n) {
    queue q;
    q.front = -1;
    q.rear = -1;
    int pop;

    q.data[++q.rear] = cur;
    discovered[cur] = 1;

    while (q.front < q.rear) {
        pop = q.data[++q.front];
        printf("%d ", pop);
        for (int i = 1; i <= n; i++) {
            if (graph[pop][i] == 1 && discovered[i] == 0) {
                q.data[++q.rear] = i;
                discovered[i] = 1;
            }
        }
    }
}

void DFS(int cur, int n) {
    visited[cur] = 1;
    printf("%d ", cur);
    for (int i = 1; i <= n; i++) {
        if (graph[cur][i] == 1 && visited[i] == 0) {
            DFS(i, n);
        }
    }
}

int main() {
    int n, m, v;
    int i, j;
    scanf("%d %d %d", &n, &m, &v);
    for (i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    DFS(v, n);
    printf("\n");
    BFS(v, n);
    return 0;
}
