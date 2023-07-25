#include <iostream>
#include <queue>
#include <vector>
#include <string>
 
using namespace std;
 
int d[101][101];
char map[101][101];
bool chk[101][101];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
 
int main() {
    int n, m;
    cin >> m >> n;
    cin.ignore();
    string s;
    vector<pair<int, int>> c;
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        for (int j = 0; j < s.size(); j++) {
            map[i][j] = s[j];
            if (map[i][j] == 'C') {
                c.push_back(make_pair(i, j));
            }
        }
    }
    int s1 = c[0].first;
    int s2 = c[0].second;
    queue<pair<int, int>> q;
    q.push(make_pair(s1, s2));
    d[s1][s2] = 0;
    chk[s1][s2] = true;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            while (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (map[nx][ny] == '*') break;
                if (!chk[nx][ny]) {
                    chk[nx][ny] = true;
                    d[nx][ny] = d[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
                nx += dx[k];
                ny += dy[k];
            }
        }
    }
    cout << d[c[1].first][c[1].second] -1 << "\n";
}
