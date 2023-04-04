#include <iostream>
#include <queue>

using namespace std;

char map[5][5];
bool visited[5][5];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int r, c, k;
int cnt;

void dfs(int depth, int x, int y) {
    if (depth == k) {
        if (y == 0 && x == c - 1) cnt++;
        return;
    }
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx >= 0 && nx < c && ny >= 0 && ny < r && !visited[ny][nx] && map[ny][nx] != 'T') {
            visited[ny][nx] = true;
            dfs(depth + 1, nx, ny);
            visited[ny][nx] = false;
        }
    }
}

int main() {
    cin >> r >> c >> k;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> map[i][j];
        }
    }
    visited[r-1][0]=true;
    dfs(1, 0, r - 1);

    cout << cnt;
}