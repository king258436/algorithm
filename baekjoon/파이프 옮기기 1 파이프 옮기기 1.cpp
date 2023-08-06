#include<iostream>

using namespace std;

struct Point {
    int x;
    int y;
};

int n;
int map[20][20];
int cnt;
int dx[] = {1, 0, 1};
int dy[] = {0, 1, 1};


void dfs(Point cur, int state) {
    if (cur.x == n - 1 && cur.y == n - 1) {// 현재지점 이 N,n 일경우
        cnt++;
//        cout << state << ' ';
        return;
    }
    for (int dir = 0; dir < 3; dir++) {
        if ((state == 0 && dir == 1) || (state == 1 && dir == 0)) {
            continue;
        }
        int ny = cur.y + dy[dir];
        int nx = cur.x + dx[dir];
        if (map[ny][nx] == 1 || ny >= n || nx >= n) {
            continue;
        }
        if (dir == 2 && (map[ny - 1][nx] || map[ny][nx - 1])) {
            continue;
        }
//        cout << dir << ' ';
        dfs({nx, ny}, dir);

    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }
    dfs({1, 0}, 0);
    cout << cnt;
}