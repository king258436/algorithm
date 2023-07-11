#include<iostream>
#include<vector>

#define INF 1e9
using namespace std;

vector<pair<pair<int, int>, long long>> vec;
long long dis[501];
int n, m;
bool flag;

void bellman_Ford() {
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < vec.size(); j++) {
            int from = vec[j].first.first;
            int to = vec[j].first.second;
            long long cost = vec[j].second;
            if (dis[from] == INF) continue;
            if (dis[to] > dis[from] + cost)dis[to] = dis[from] + cost;
        }
    }

    for (int i = 0; i < vec.size(); i++) {
        int from = vec[i].first.first;
        int to = vec[i].first.second;
        int cost = vec[i].second;
        if (dis[from] >= INF) continue;
        if (dis[to] > dis[from] + cost) {
            flag = true;
        }
    }
}

void init() {
    for (int i = 1; i <= n; i++) {
        dis[i] = INF;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        vec.push_back({{a, b}, c});
    }
    init();
    dis[1] = 0;
    bellman_Ford();
    if (flag) {
        cout << -1;
    } else {
        for (int i = 2; i <= n; i++) {
            if (dis[i] == INF) cout << -1 << '\n';
            else cout << dis[i] << '\n';
        }
    }
}