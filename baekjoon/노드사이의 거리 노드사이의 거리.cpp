#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;


struct Info {
    int node;
    int cost;
};
vector<Info> vec[1001];
bool visited[1001];
int n, m;
int res;

void dfs(int a, int b, int sum) {
    if (a == b) {
        res = sum;
        return;
    }
    for (auto next: vec[a]) {
        if (visited[next.node]) {
            continue;
        } else {
            visited[next.node] = true;
            dfs(next.node, b, sum + next.cost);
        }
    }
    return;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n - 1; i++) {
        int n1, n2, dis;
        cin >> n1 >> n2 >> dis;
        vec[n1].push_back({n2, dis});
        vec[n2].push_back({n1, dis});
    }
    for (int i = 0; i < m; i++) {
        memset(visited, 0, sizeof(visited));
        int a, b;
        cin >> a >> b;
        visited[a] = true;
        dfs(a, b, 0);
        cout << res << '\n';
    }
}