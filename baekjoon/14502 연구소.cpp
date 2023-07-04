#include<iostream>
#include<queue>
#include<vector>

using namespace std;
int n, m;
int map[8][8];
int temp[8][8];
vector<pair<int, int>> vec;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int ans;
int one = 3;

void bfs() {// 벽 3개만드는건 main 에서하자.
    queue<pair<int, int>> que;
    int cnt = one;
    for (int i = 0; i < vec.size(); i++) {// 바이러스 위치들
        que.push({vec[i].first, vec[i].second});
        cnt++;
    }
    while (!que.empty()) {
        int x, y;
        y = que.front().first;
        x = que.front().second;
        que.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 8 || nx < 0 || ny >= 8 || ny < 0) continue;
            if (temp[ny][nx] != 0) continue;
            que.push({ny, nx});
            temp[ny][nx] = 2;
            cnt++;
        }
    }
    if (ans > cnt) ans = cnt;
}

int main() {
    cin >> n >> m;
    ans = n * m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) vec.push_back({i, j});
            if (map[i][j] == 1) one++;
        }
    }

    for (int iy = 0; iy < 8; iy++) {
        for (int ix = 0; ix < 8; ix++) {
            if (map[iy][ix] != 0)continue;
            map[iy][ix] = 1;
            for (int jy = 0; jy < 8; jy++) {
                for (int jx = 0; jx < 8; jx++) {
                    if (map[jy][jx] != 0) continue;
                    map[jy][jx] = 1;
                    for (int ky = 0; ky < 8; ky++) {
                        for (int kx = 0; kx < 8; kx++) {
                            if (map[ky][kx] != 0) continue;
                            map[ky][kx] = 1;
                            for (int i = 0; i < n; i++) {
                                for (int j = 0; j < m; j++) {
                                    temp[i][j] = map[i][j];
                                }
                            }
                            bfs();
                            map[ky][kx] = 0;

                        }
                    }
                    map[jy][jx] = 0;
                }
            }
            map[iy][ix] = 0;
        }
    }
    cout << n * m - ans;
}