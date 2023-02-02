#include <stdio.h>
#include <string.h>
#define MAX_Q 100000
#define MAX_INT 500

typedef struct _point {
    int x;
    int y;
} point;

int graph[20][20];
int visited[20][20];
int n;
int numOfData;
point queue[MAX_Q];
int rear, front;
int shark_size = 2;    // 상어크기
int sharkAteFish_cnt;  // 상어가 먹은물고기수
int shark_ate;
int dx[] = {0, -1, 1, 0};
int dy[] = {-1, 0, 0, 1};
int min_distance = MAX_INT;
int min_x = MAX_INT;
int min_y = MAX_INT;
int result;

void enque(int x, int y) {
    rear = (rear + 1) % MAX_Q;
    queue[rear].x = x;
    queue[rear].y = y;
    numOfData++;
}

point deque() {
    front = (front + 1) % MAX_Q;
    numOfData--;
    return queue[front];
}

void Init() {
    rear = front = -1;
    numOfData = 0;
    min_distance = MAX_INT;
    min_x = MAX_INT;
    min_y = MAX_INT;
    for (int i = 0; i < n; i++) {
        memset(visited[i], 0, sizeof(int) * n);
    }
}

void BFS(int shark_x, int shark_y) {
    enque(shark_x, shark_y);

    visited[shark_x][shark_y] = 1;

    int nx, ny;

    while (numOfData > 0) {
        point pop = deque();
        for (int i = 0; i < 4; i++) {
            nx = pop.x + dx[i];
            ny = pop.y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

            if (visited[nx][ny] != 0 || graph[nx][ny] > shark_size) continue;

            visited[nx][ny] = visited[pop.x][pop.y] + 1;

            if (shark_size > graph[nx][ny] && graph[nx][ny] != 0) {  // 상어가 먹을게있다.
                if (visited[nx][ny] < min_distance) {               // 먹을수있는것중에 최솟값인가? 최솟값이면 저장.
                    min_distance = visited[nx][ny];
                    min_x = nx;
                    min_y = ny;
                } else if (visited[nx][ny] == min_distance) {  //
                    if (min_x == nx) {
                        if (min_y > ny) {
                            min_x = nx;
                            min_y = ny;
                        }
                    } else if (min_x > nx) {
                        min_x = nx;
                        min_y = ny;
                    }
                }
            }
            enque(nx, ny);
        }
    }
}

int main() {
    point shark_zone;
    int i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 9) {
                shark_zone.x = i;
                shark_zone.y = j;
                graph[i][j] = 0;
            }
        }
    }
    while (1) {  // 나가려면 bfs에서 먹을 수 있는 물고기가 없어야함.
        Init();  // 초기화

        BFS(shark_zone.x, shark_zone.y);

        if (min_x != MAX_INT && min_y != MAX_INT) {
            sharkAteFish_cnt++;
            if (sharkAteFish_cnt == shark_size) {
                shark_size++;
                sharkAteFish_cnt = 0;
            }
            result = result + visited[min_x][min_y]-1;
            graph[min_x][min_y] = 0;
            shark_zone.x = min_x;
            shark_zone.y = min_y;
        } else {
            break;
        }
    }
    printf("%d", result);
}