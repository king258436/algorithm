#include<iostream>
#include<queue>
#include<vector>

using namespace std;
int n, m;
int in_degree[1001];
vector<int> vec[1001];
vector<int> result;

bool Topology_Sort() {
    queue<int> que;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            que.push(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (que.empty()) {
            return false;
        }
        int cur = que.front();
        que.pop();
        result.push_back(cur);
        for (int j = 0; j < vec[cur].size(); j++) {
            int next = vec[cur][j];
            if (--in_degree[next] == 0) {
                que.push(next);
            }
        }
    }
    return true;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int num;
        int pre, cur;
        cin >> num;
        cin >> cur;
        for (int j = 0; j < num - 1; j++) {
            pre = cur;
            cin >> cur;
            vec[pre].push_back(cur);
            in_degree[cur]++;
        }
    }
    if (Topology_Sort()) {
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << '\n';
        }
    } else {
        cout << 0;
    }
}