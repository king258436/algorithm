#include <stdio.h>

int map[1000][1000];
int n, m;
int front = -1;
int rear = -1;
int maxcnt;
int cnt;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

typedef struct _p {
    int x;
    int y;
} point;

point queue[1000000];

void enque(int x, int y) {
    point temp;
    temp.x = x;
    temp.y = y;
    rear = (rear + 1) % 1000000;
    queue[rear] = temp;
}

point deque(void) {
    point temp;
    front = (front + 1) % 1000000;
    temp = queue[front];
    return temp;
}

int bfs(void) {
    int i, j;
    point temp;
    int nx, ny;
    while (front < rear) {
        temp = deque();
        for (i = 0; i < 4; i++) {
            nx = temp.x + dx[i];
            ny = temp.y + dy[i];

            if (0 <= nx && nx < m && 0 <= ny && ny < n && map[nx][ny] == 0) {
                map[nx][ny] = map[temp.x][temp.y] + 1;
                enque(nx, ny);
                cnt--;
            }
        }
    }
    if (cnt == 0)
        return map[temp.x][temp.y] - 1;
    else
        return -1;
}

int main(void) {
    int i, j;
    int res;
    scanf("%d %d", &m, &n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &map[j][i]);
            if (map[j][i] == 0) cnt++;
            else if (map[j][i] == 1) enque(j, i);
        }
    }
    res=bfs();
    printf("%d",res);
    return 0;
}