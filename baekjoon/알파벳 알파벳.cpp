#include<iostream>
#include<string>
#include<cstring>
#include<queue>

using namespace std;
int r, c;
string map[21];
int visited[26];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int result;

void dfs(int y, int x, int cnt) {

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny >= r || ny < 0 || nx >= c || nx < 0) {
            continue;
        }
        if (visited[map[ny][nx] - 'A']) {
            continue;
        }
        visited[map[ny][nx] - 'A'] = true;
        dfs(ny, nx, cnt + 1);
        visited[map[ny][nx] - 'A'] = false;
    }
    result = max(cnt, result);
}

int main() {
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        cin >> map[i];
    }
    visited[map[0][0] - 'A'] = true;
    dfs(0, 0, 1);
    cout << result;

}