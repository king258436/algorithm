#include <stdio.h>
#define max 100000

typedef struct _po {
    int x;
    int y;
} point;

int graph[100][100];
int n, m;
int cnt[100][100];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int front = -1, rear = -1;
point que[max];

void enque(point data) {
    rear = (rear + 1) % max;
    que[rear] = data;
}

point deque() {
    front = (front + 1) % max;
    return que[front];
}

void bfs(int x, int y, int n, int m) {
    point temp, endata;
    temp.x = x;
    temp.y = y;
    enque(temp);
    graph[temp.x][temp.y] = 0;
    while (front < rear) {
        temp = deque();
        for (int i = 0; i < 4; i++) {
            endata.x = temp.x + dx[i];
            endata.y = temp.y + dy[i];

            if (graph[endata.x][endata.y] == 1 && endata.x >= 0 && endata.y >= 0 && endata.x < m && endata.y < n) {
                enque(endata);
                graph[endata.x][endata.y] = 0;
                cnt[endata.x][endata.y] = cnt[temp.x][temp.y] + 1;
            }
        }
    }
}

int main() {
    int i, j;
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%1d", &graph[j][i]);
        }
    }
    bfs(0, 0, n, m);
    printf("%d", cnt[m-1][n-1]+1);
    return 0;
}