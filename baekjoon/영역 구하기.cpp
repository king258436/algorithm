#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct point {
    int x;
    int y;
};

bool map[100][100];
int area;
int score;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, m, k;
int arr[10000];
int top;

void bfs(int y, int x) {
    queue<pair<int, int> > que;
    que.push(make_pair(y, x));

    while (!que.empty()) {
        pair<int, int> temp = que.front();
        que.pop();
        for (int dir = 0; dir < 4; dir++) {
            int ny = temp.first + dy[dir];
            int nx = temp.second + dx[dir];
            if (ny >= 0 && ny < m && nx >= 0 && nx < n && map[ny][nx] == false) {
                que.push(make_pair(ny, nx));
                map[ny][nx] = true;
                score++;
            }
        }
    }
    if (score == 0) score = 1;
    arr[top++] = score;
    score = 0;
}

int main() {
    cin >> m >> n >> k;
    for (int i = 0; i < k; i++) {
        pair<int, int> leftDown, rightUp;
        cin >> leftDown.second >> leftDown.first >> rightUp.second >> rightUp.first;
        for (int y = min(leftDown.first, rightUp.first); y < max(leftDown.first, rightUp.first); y++) {
            for (int x = min(leftDown.second, rightUp.second); x < max(leftDown.second, rightUp.second); x++) {
                map[y][x] = true;
            }
        }
    }
    for (int y = 0; y < m; y++) {
        for (int x = 0; x < n; x++) {
            if (map[y][x] == false) {
                bfs(y, x);
                area++;
            }
        }
    }
    sort(arr, arr + top);
    cout << area << '\n';
    for (int i = 0; i < top; i++) {
        cout << arr[i] << ' ';
    }
}