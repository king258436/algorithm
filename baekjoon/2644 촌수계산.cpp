#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> vec[101];
int visited[101];

int bfs(int a, int b) {
    queue<int> que;
    que.push(a);
    while (!que.empty()) {
        int x = que.front();
        que.pop();
        for (int i = 0; i < vec[x].size(); i++) {
            if (!visited[vec[x][i]]) {
                visited[vec[x][i]] = visited[x] + 1;
                que.push(vec[x][i]);
            }
        }
    }
    return visited[b];
}

int main() {
    int n, m;
    int a, b;
    cin >> n;
    cin >> a >> b;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    int result = bfs(a, b);

    if (result == 0) cout << -1;
    else cout << result;


}