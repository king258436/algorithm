#include<iostream>
#include<queue>
#include<string>
#include<cstring>

using namespace std;
string str[100];
bool visited[100][100];
int n, m;
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};
struct Point {
    int y;
    int x;
};

bool bfs(int y, int x) {
    queue<Point> que;
    if (visited[y][x] || str[y][x] != '#') {
        return false;
    }
    que.push({y, x});
    visited[y][x] = true;
    while (!que.empty()) {
        auto cur = que.front();
        que.pop();
        for (int dir = 0; dir < 4; dir++) {
            int ny = cur.y + dy[dir];
            int nx = cur.x + dx[dir];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                continue;
            }
            if (visited[ny][nx] || str[ny][nx] != '#') {
                continue;
            }
            que.push({ny, nx});
            visited[ny][nx] = true;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        memset(visited, 0, sizeof(visited));
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> str[i];
        }
        int result = 0;
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if (bfs(y, x)) {
                    result++;
                }
            }
        }
        cout << result << '\n';
    }
    return 0;
}