#include<iostream>
#include<vector>
#include<queue>

#define INF 1e9
using namespace std;

int dist[20001];
vector<pair<pair<int, int>, int> > edge;
vector<int> reEdge[101];
bool visited[20001];
int V, E;
bool cycle;
int road[101];

void bellman_Ford() {
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < edge.size(); j++) {
            int from = edge[j].first.first;
            int to = edge[j].first.second;
            int value = edge[j].second;
            if (dist[from] != INF && dist[to] > dist[from] + value) {
                dist[to] = dist[from] + value;
                road[to] = from;
            }
        }
    }

    for (int j = 0; j < edge.size(); j++) {
        int from = edge[j].first.first;
        int to = edge[j].first.second;
        int value = edge[j].second;
        if (dist[from] != INF && dist[to] > dist[from] + value) {
            if (visited[from]) {
                cycle = true;
            }
            road[to] = from;
        }
    }

}

void init() {
    for (int i = 2; i <= V; i++) {
        dist[i] = INF;
    }
}

void find(int n) {
    if (n == 1) {
        cout << n << ' ';
        return;
    }
    find(road[n]);
    cout << n << ' ';
}

int main() {
    cin >> V >> E;
    init();
    for (int i = 0; i < E; i++) {
        int s, e, v;
        cin >> s >> e >> v;
        edge.push_back({{s, e}, -v});
        reEdge[e].push_back(s);
    }
    queue<int> que;
    que.push(V);
    visited[V] = true;
    while (!que.empty()) {
        int cur = que.front();
        que.pop();
        for (int i = 0; i < reEdge[cur].size(); i++) {
            int next = reEdge[cur][i];
            if (!visited[next]) {
                visited[next] = true;
                que.push(next);
            }
        }
    }
    bellman_Ford();
    if (cycle) {
        cout << -1;
    } else {
        find(V);
    }


}