#include <string.h>

#include <iostream>
#include <queue>
using namespace std;
bool map[51][51];
bool visited[51][51];
int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};
int w, h;
void bfs(int y, int x) {
    queue<pair<int, int> > que;
    que.push(make_pair(y, x));
    visited[y][x] = true;
    while (!que.empty()) {
        y = que.front().first;
        x = que.front().second;
        que.pop();
        for (int dir = 0; dir < 8; dir++) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if (nx >= 0 && ny >= 0 && ny < h && nx < w && !visited[ny][nx] && map[ny][nx]) {
                que.push(make_pair(ny, nx));
                visited[ny][nx] = true;
            }
        }
    }
}
int main() {
    while (1) {
        memset(map, 0, sizeof(map));
        memset(visited, 0, sizeof(visited));
        cin >> w >> h;
        if (w == 0 && h == 0) break;
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                cin >> map[y][x];
            }
        }
        int cnt = 0;
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (!visited[y][x] && map[y][x]) {
                    bfs(y, x);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
}