#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;
bool visited[1001];

void print(int &a) {
    cout << a << ' ';
}

void bfs(int &start, vector<int> vec[]) {
    queue<int> que;
    que.push(start);
    visited[start] = true;
    while (!que.empty()) {
        auto cur = que.front();
        que.pop();
        print(cur);
        for (auto nxt: vec[cur]) {
            if (!visited[nxt]) {
                visited[nxt] = true;
                que.push(nxt);
            }
        }
    }
    cout << '\n';
}

void dfs(int &cur, vector<int> vec[]) {
    print(cur);
    visited[cur] = true;
    for (auto nxt: vec[cur]) {
        if (!visited[nxt]) {
            dfs(nxt, vec);
        }
    }
}

int main() {
    int n, m, s;
    cin >> n >> m >> s;
    vector<int> vec[n + 1];
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        sort(vec[i].begin(), vec[i].end());
    }
//    visited[s]=true;
    dfs(s, vec);
    cout << '\n';
    memset(visited, 0, sizeof(visited));
    bfs(s, vec);

}