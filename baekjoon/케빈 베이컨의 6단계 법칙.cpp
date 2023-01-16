#include <stdio.h>
#include <string.h>
#define max 101

typedef struct _queue {
    int front;
    int rear;
    int que[max];
} queue;

int graph[max][max];
int discovered[max];
int min = max;
int cnt[max];

void bfs(int cur, int n) {
    queue q;
    int pop;  // pop의 기능을 할 변수.
    int mul = 0;
    q.front = -1;
    q.rear = -1;            // 큐 초기화
    q.que[++q.rear] = cur;  // 현재 voltex를 enqueue.
    discovered[cur] = 1;    // enqueue되었으니까 방문했다는 표시 남겨줌.

    while (q.front < q.rear) {
        pop = q.que[++q.front];  // dequeue.
        for (int i = 1; i <= n; i++) {
            if (graph[pop][i] == 1 && discovered[i] == 0) {
                cnt[i] = cnt[pop] + 1;
                q.que[++q.rear] = i;
                discovered[i] = 1;
            }
        }
    }
}

int main() {
    int n, m;
    int i, j;
    int res;
    scanf("%d %d", &n, &m);
    for (i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    for (i = 1; i <= n; i++) {
        bfs(i, n);
        int sum=0;
        for(int j=1;j<=n;j++){
            sum+=cnt[j];
        }
        if(min>sum) {
            min =sum;
            res = i;
        }
        memset(discovered, 0, sizeof(int) * max);
        memset(cnt, 0, sizeof(int) * max);
    }
    printf("%d",res);
    return 0;
}