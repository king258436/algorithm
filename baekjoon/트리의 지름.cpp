#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
vector<pair<int, int> > tree[10001];  // first = 정점 , second = 거리.
bool visited[10001];
int max_dist, max_node;

void dfs(int node, int dist) {
    if(visited[node]) return;
    if (max_dist < dist) {
        max_dist = dist;
        max_node = node;
    }
    visited[node]=true;
    for (int i = 0; i < tree[node].size(); i++) {
        int nextNode = tree[node][i].first;
        int sumOfNextDist = dist + tree[node][i].second;

        dfs(nextNode, sumOfNextDist);
    }
}

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int p;
        int c;
        int val;
        cin >> p >> c >> val;
        tree[p].push_back(make_pair(c, val));
        tree[c].push_back(make_pair(p, val));
    }
    dfs(1, 0);
    memset(visited, 0, sizeof(visited));
    dfs(max_node, 0);

    cout << max_dist;
}