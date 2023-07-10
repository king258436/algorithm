#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<pair<int, int>> vec[5001];

int bfs(int k, int v) {
    int cnt = 0;
    bool visited[5001] = {0,};
    queue<int> que;
    que.push(v);
    visited[v] = true;
    while (!que.empty()) {
        int cur = que.front();
        que.pop();
        for (int i = 0; i < vec[cur].size(); i++) {
            pair<int, int> connectedMTB = vec[cur][i];
            if (visited[connectedMTB.first] || connectedMTB.second < k) continue;
            visited[connectedMTB.first] = true;
            que.push(connectedMTB.first);
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n - 1; i++) {
        int u, v, dis;
        cin >> u >> v >> dis;
        vec[u].push_back({v, dis});
        vec[v].push_back({u, dis});
    }
    for (int i = 0; i < q; i++) {
        int k, v;
        cin >> k >> v;
        cout << bfs(k, v) << "\n";
    }
}