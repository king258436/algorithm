#include<iostream>
#include<queue>

using namespace std;
int map[101][101];
bool visited[101][101];
int n, m;
int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};
bool is_peak = true;

struct Point {
    int y;
    int x;
};

void bfs(int y, int x) {
    queue<Point> que;
    que.push({y, x});
    visited[y][x] = true;
    while (!que.empty()) {
        auto cur = que.front();
        que.pop();
        for (int dir = 0; dir < 8; dir++) {
            int ny = cur.y + dy[dir];
            int nx = cur.x + dx[dir];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) {
                continue;
            }
            if (map[ny][nx] > map[y][x]) {
                is_peak = false;
            }
            if (visited[ny][nx] || map[y][x] != map[ny][nx]) {
                continue;
            }
            que.push({ny, nx});
            visited[ny][nx] = true;
        }
    }
    return;
}

int main() {
    cin >> n >> m;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> map[y][x];
        }
    }
    int cnt = 0;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (visited[y][x]) {
                continue;
            }
            is_peak = true;
            bfs(y, x);
            if (is_peak) {
                cnt++;
            }
        }
    }
    cout << cnt;
}