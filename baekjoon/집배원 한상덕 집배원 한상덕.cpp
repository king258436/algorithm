#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;

struct Point {
    int y;
    int x;
};
int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[] = {1, -1, 1, -1, 0, 1, -1, 0};
int n;
string map[51];
int fatigue[51][51];
bool status[51][51];
bool visited[51][51];
bool check[1000001];
vector<int> vec;
int low, high;
Point post;
int K_cnt;
int result = 1e9;

void print() {
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cout << status[y][x] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void check_status() {// 해당 피로도가 투포인터 배열 vec의 범위안에 있다면, status에 기록(길 만들기)
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (vec[low] <= fatigue[y][x] && vec[high] >= fatigue[y][x]) {
                status[y][x] = 1;
            }
        }
    }
}

void bfs() {
    queue<Point> que;
    if (status[post.y][post.x] != 1) {
        high++;
        return;
    }
    que.push({post.y, post.x});
    int K_cnt_in_func = 0;
    while (!que.empty()) {
        auto cur = que.front();
        que.pop();
        for (int dir = 0; dir < 8; dir++) {
            int ny = cur.y + dy[dir];
            int nx = cur.x + dx[dir];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
                continue;
            }
            if (visited[ny][nx] || status[ny][nx] != 1) {
                continue;
            }
            que.push({ny, nx});
            if (map[ny][nx] == 'K') {
                K_cnt_in_func++;
            }
            visited[ny][nx] = true;
        }
    }
    if (K_cnt_in_func == K_cnt) {
        result = min(result, vec[high] - vec[low]);
        low++;
    } else {
        high++;
    }
}


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> map[i];
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 'P') {
                post.y = i;
                post.x = j;
            } else if (map[i][j] == 'K') {
                K_cnt++;
            }
        }
    }
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> fatigue[y][x];
            if (!check[fatigue[y][x]]) {
                vec.push_back(fatigue[y][x]);
                check[fatigue[y][x]] = true;
            }
        }
    }
    sort(vec.begin(), vec.end());

    while (high <= vec.size() - 1 && low <= high) {
        memset(status, 0, sizeof(status));
        memset(visited, 0, sizeof(visited));
        check_status();// 길 만들기.
        bfs();
//        print();
    }
    cout << result;
}