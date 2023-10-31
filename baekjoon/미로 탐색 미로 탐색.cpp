#include<iostream>
#include<string>
#include<queue>

using namespace std;

struct Info {
    int y;
    int x;
    int point;
};

int n, m;
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
int map[100][100];

int bfs(Info start, vector<string> vec) {
    queue<Info> que;
    que.push(start);
    map[start.y][start.x] = 1;
    while (!que.empty()) {
        auto cur = que.front();
        que.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            int n_point = cur.point + 1;
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && vec[ny][nx] == '1' &&
                (map[ny][nx] > n_point || map[ny][nx] == 0)) {
                map[ny][nx] = n_point;
                que.push({ny, nx, n_point});
            }
        }
    }
    return map[n - 1][m - 1];
}

void print_map() {
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cout << map[y][x] << ' ';
        }
        cout << '\n';
    }
}

int main() {

    cin >> n >> m;
    vector<string> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    int result = bfs({0, 0, 1}, vec);
    cout << result << '\n';
}