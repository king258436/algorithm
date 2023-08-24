#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
struct Move_info {
    int d;
    int s;
};
struct Point {
    int y;
    int x;
};

int map[51][51];
bool cloud[51][51];
bool temp[51][51];
int n, m;
int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
vector<Move_info> command;
queue<Point> cloud_que;

void create_cloud() {
    for (int y = 1; y <= 2; y++) {
        for (int x = 0; x <= 1; x++) {
            cloud[n - y][x] = 1;
        }
    }
}

int move_al(int next) {
    if (next < 0) {
        return n - 1;
    } else if (next >= n) {
        return 0;
    } else {
        return next;
    }
}

void temp_to_cloud() {
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cloud[y][x] = temp[y][x];
        }
    }
    memset(temp, 0, sizeof(temp));
}

void move_cloud(int dir, int dis) {// Dir 이 예제보다 하나 적어서 처리 잘 해줘야함
    for (int y = 0; y < n; y++) {// 현재 구름위치 다 큐에 저장
        for (int x = 0; x < n; x++) {
            if (cloud[y][x]) {
                cloud_que.push({y, x});
            }
        }
    }
    while (!cloud_que.empty()) {// 구름 위치 옮겨버림
        auto cur = cloud_que.front();
        cloud_que.pop();
        int ny = cur.y;
        int nx = cur.x;
        for (int i = 0; i < dis; i++) {
            ny = move_al(ny + dy[dir]);
            nx = move_al(nx + dx[dir]);
        }
        temp[ny][nx] = 1;
    }
    temp_to_cloud();// cloud 에 옮겨진거 다 저장.
}

void water_plus() {
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (cloud[y][x]) {
                map[y][x]++;
            }
        }
    }
}

void diagonal_water() {
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (cloud[y][x]) {
                int cnt = 0;
                for (int dir = 1; dir <= 7; dir += 2) {
                    int ny = y + dy[dir];
                    int nx = x + dx[dir];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
                        continue;
                    }
                    if (map[ny][nx] >= 1) {
                        cnt++;
                    }
                }
                map[y][x] += cnt;
            }
        }
    }
}

void final() {
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (map[y][x] >= 2 && cloud[y][x] == 0) {
                temp[y][x] = 1;
                map[y][x] -= 2;
            }
        }
    }
    temp_to_cloud();
}

void print_map() {
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cout << map[y][x] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void print_cloud() {
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cout << cloud[y][x] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int main() {
    cin >> n >> m;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> map[y][x];
        }
    }
    for (int i = 0; i < m; i++) {
        int dir, dis;
        cin >> dir >> dis;
        command.push_back({dir - 1, dis});
    }
    create_cloud();
    for (auto a: command) {
        move_cloud(a.d, a.s);
        water_plus();
        diagonal_water();
        final();
//        print_map();
//        print_cloud();
    }
    int result = 0;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            result += map[y][x];
        }
    }
    cout << result << '\n';

}