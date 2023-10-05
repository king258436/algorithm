#include<iostream>
#include<vector>

#define LEFT 0
#define UP 1
#define RIGHT 2
#define DOWN 3

using namespace std;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int visited[101][101];
struct Robot {
    int y;
    int x;
    int dir;
};

void turn_left_func(Robot &cur) {
    cur.dir--;
    if (cur.dir < 0) cur.dir = 3;
}

void turn_right_func(Robot &cur) {
    cur.dir = (cur.dir + 1) % 4;
}

void go_straight_func(Robot &cur) {
    cur.x = cur.x + dx[cur.dir];
    cur.y = cur.y + dy[cur.dir];
}

int main() {
    int A, B;
    int n, m;
    cin >> A >> B;
    cin >> n >> m;
    vector<Robot> robots(n + 1);
    for (int i = 1; i <= n; i++) {
        char dir;
        cin >> robots[i].x >> robots[i].y >> dir;
        visited[robots[i].y][robots[i].x] = i;
        if (dir == 'W') {
            robots[i].dir = 0;
        } else if (dir == 'N') {
            robots[i].dir = 1;
        } else if (dir == 'E') {
            robots[i].dir = 2;
        } else if (dir == 'S') {
            robots[i].dir = 3;
        }
    }
    int cur_robot;
    char order;
    int order_num;
    for (int i = 0; i < m; i++) {
        cin >> cur_robot >> order >> order_num;
        if (order == 'L') {
            for (int j = 0; j < order_num; j++) {
                turn_left_func(robots[cur_robot]);
            }
        } else if (order == 'R') {
            for (int j = 0; j < order_num; j++) {
                turn_right_func(robots[cur_robot]);
            }
        } else if (order == 'F') {
            for (int j = 0; j < order_num; j++) {
                visited[robots[cur_robot].y][robots[cur_robot].x] = 0;
                go_straight_func(robots[cur_robot]);
                if (robots[cur_robot].x > A || robots[cur_robot].y > B || robots[cur_robot].x <= 0 ||
                    robots[cur_robot].y <= 0) {// 벽이랑 박았을때
                    cout << "Robot " << cur_robot << " crashes into the wall";
                    return 0;
                } else if (visited[robots[cur_robot].y][robots[cur_robot].x] != 0) {//다른 로봇이랑 박았을때
                    cout << "Robot " << cur_robot << " crashes into robot "
                         << visited[robots[cur_robot].y][robots[cur_robot].x];
                    return 0;
                } else if (j == order_num - 1) {
                    visited[robots[cur_robot].y][robots[cur_robot].x] = cur_robot;
                }
            }
        }
    }
    cout << "OK";
    return 0;
}