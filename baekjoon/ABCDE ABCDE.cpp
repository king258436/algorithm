#include<iostream>
#include<vector>
#include<cstring>

using namespace std;
vector<int> vec[2001];
int n, m;
int flag = 0;
bool visited[2001];

void DFS(int depth, int cur) {
    if (flag == 1) {
        return;
    }
    if (depth == 5) {
        flag = 1;
        return;
    }
    for (auto nxt: vec[cur]) {
        if (visited[nxt]) {
            continue;
        }
        visited[nxt] = true;
        DFS(depth + 1, nxt);
        visited[nxt] = false;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        memset(visited, 0, sizeof(visited));
        visited[i] = true;
        DFS(1, i);
        visited[i] = false;
    }

    cout << flag;

}
