#include<iostream>
#include<queue>
#include<vector>

using namespace std;
int indegree[32001];
vector<int> vec[32001];
vector<int> result;
int n, m;

bool topology_sort() {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            pq.push(i);
        }
    }
    while (!pq.empty()) {
        int cur = pq.top();
        pq.pop();
        result.push_back(cur);
        for (auto next: vec[cur]) {
            if (--indegree[next] == 0) {
                pq.push(next);
            }
        }
    }
    if (result.size() != n) {
        return false;
    }
    return true;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        vec[s].push_back(e);
        indegree[e]++;
    }
    topology_sort();
    for (auto a: result) {
        cout << a << ' ';
    }
    return 0;
}

