#include<iostream>
#include<queue>

using namespace std;
struct Point {
    int y;
    int x;
};
int map[101][101];
bool visited[101][101];
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};
queue<Point> que;
int n, m;

void simul() {
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cout << map[y][x] << ' ';
        }
        cout << '\n';
    }
}

bool find_cheese() {// 치즈중에 노출된 애들 체크하고 노출된애들있으면 큐에 푸쉬
    for (int y = 1; y < n - 1; y++) {
        for (int x = 1; x < m - 1; x++) {
            if (map[y][x]) {
                int out_cnt = 0;
                for (int dir = 0; dir < 4; dir++) {
                    int ny = y + dy[dir];
                    int nx = x + dx[dir];
                    if (visited[ny][nx] && !map[ny][nx]) {
                        out_cnt++;
                    }
                }
                if (out_cnt >= 2) {
                    que.push({y, x});
                }
            }
        }
    }
    if (que.empty()) {// 큐 비었으면 치즈없단얘기니까 리턴 false
        return false;
    }
    return true;
}

void out_check() {// 빈공간에 bfs돌려서 0으로 체크된애들 visited 처리
    queue<Point> oq;
    oq.push({0, 0});
    while (!oq.empty()) {
        auto cur = oq.front();
        oq.pop();
        for (int dir = 0; dir < 4; dir++) {
            int ny = cur.y + dy[dir];
            int nx = cur.x + dx[dir];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) {
                continue;
            }
            if (visited[ny][nx] || map[ny][nx]) {
                continue;
            }
            oq.push({ny, nx});
            visited[ny][nx] = true;
        }
    }
}

void make_zero() {// 큐에 체크해놓은 치즈들 0으로 바꾸기
    while (!que.empty()) {
        Point cur = que.front();
        que.pop();
        map[cur.y][cur.x] = 0;
    }
};

void visited_init() {// visited 초기화
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            visited[y][x] = false;
        }
    }
}


int main() {
    cin >> n >> m;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> map[y][x];
        }
    }
    int result = 0;
    while (1) {
//        simul();
        out_check();
        if (!find_cheese()) {
            cout << result;
            return 0;
        }
        make_zero();
        visited_init();
        result++;
    }
}