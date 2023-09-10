#include<iostream>
#include<queue>
#include<vector>
#include<cstring>

#define MAX 1001
using namespace std;

int n, m;

string str[MAX];
int group[MAX][MAX];
bool visited[MAX][MAX];
vector<int> vec;
bool visited_vec[MAX * MAX];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int vec_point;
struct Point {
    int y;
    int x;
};

//bfs를 돌릴때, group, visited 배열만 채운다는 목적으로 작성하면 됨.
void bfs_for_group(int y, int x) {
    queue<Point> que;
    que.push({y, x});
    int cnt = 1;
    vec_point++;
    while (!que.empty()) {
        auto cur = que.front();
        que.pop();
        group[cur.y][cur.x] = vec_point;
        visited[cur.y][cur.x] = true;
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                continue;
            }
            if (!visited[ny][nx] && str[ny][nx] == '0') {
                cnt++;
                que.push({ny, nx});
                visited[ny][nx] = true;
                group[ny][nx] = vec_point;
            }
        }
    }
    vec.push_back(cnt);
}

int check_result(int y, int x) {
    int cnt = 1;
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
            continue;
        }
        if (visited_vec[group[ny][nx]]) {
            continue;
        }
        cnt += vec[group[ny][nx]];
        visited_vec[group[ny][nx]] = true;
    }
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
            continue;
        }
        visited_vec[group[ny][nx]] = false;
    }
    return cnt;
}

void print_test_group() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << group[i][j];
        }
        cout << '\n';
    }
}

void print_test_vector() {
    for (auto i: vec) {
        cout << i << ' ';
    }
}

int main() {// visited 처리는 여기서 해줘야 함.
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }
    vec.push_back(0);
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (str[y][x] == '0' && !visited[y][x]) {
                bfs_for_group(y, x);
            }
        }
    }
    memset(visited, 0, sizeof(visited));
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (str[y][x] == '1') {
                cout << check_result(y, x) % 10;
            } else {
                cout << '0';
            }
        }
        cout << '\n';
    }
//    cout << '\n';
//    print_test_group();
//    cout << '\n';
//    print_test_vector();
    return 0;
}