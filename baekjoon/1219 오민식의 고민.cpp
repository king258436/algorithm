#include<iostream>
#include<vector>
#include<queue>

#define INF 1e9

using namespace std;


int n, m, depart, goal;
long long dis[51];
int money[51];
vector<pair<pair<int, int>, int>> edge;
vector<int> vec[51];
queue<int> que;
bool visited[51];
bool cycle;

void bellman_Ford() {
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < edge.size(); j++) {
            int from = edge[j].first.first;
            int to = edge[j].first.second;
            int cost = edge[j].second;
            if (dis[from] != INF && dis[to] > dis[from] + cost - money[to]) {
                dis[to] = dis[from] + cost - money[to];
            }
        }
    }
    for (int j = 0; j < edge.size(); j++) {
        int from = edge[j].first.first;
        int to = edge[j].first.second;
        int cost = edge[j].second;
        if (dis[from] != INF && dis[to] > dis[from] + cost - money[to]) {
            cycle = true;
            que.push(from);
            visited[from] = true;
        }
    }
}

bool bfs() {
    while (!que.empty()) {
        int cur = que.front();
        que.pop();
        for (int i = 0; i < vec[cur].size(); i++) {
            int next = vec[cur][i];
            if (!visited[next]) {
                que.push(next);
                visited[next] = true;
            }
        }
    }
    if (visited[goal] == true) return true;
    else return false;
}

int main() {
    cin >> n >> depart >> goal >> m;
    for (int i = 0; i < m; i++) {
        int s, e, c;
        cin >> s >> e >> c;
        edge.push_back({{s, e}, c});
        vec[s].push_back(e);
    }
    for (int i = 0; i < n; i++) {
        cin >> money[i];
    }

    for (int i = 0; i < n; i++) {
        dis[i] = INF;
    }
    dis[depart] = -money[depart];

    bellman_Ford();

    if (dis[goal] == INF) {
        cout << "gg";
    } else if (bfs() && cycle) {
        cout << "Gee";
    } else {
        cout << -dis[goal];
    }
}