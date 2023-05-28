#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int indegree[32001];

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v[32001];
    while (m--) {
        int t, s;
        cin >> t >> s;
        v[t].push_back(s);
        indegree[s]++;
    }

    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (!indegree[i]) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto next : v[cur]) {
            indegree[next]--;
            if (!indegree[next]) {
                q.push(next);
            }
        }
        cout << cur << ' ';
    }
}