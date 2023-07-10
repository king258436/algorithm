#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct edge {
    int v;
    int u;
    int dis;
};

int parent[10001];
vector<edge> vec;

bool comp(edge e1, edge e2) {
    return e1.dis < e2.dis;
}

int getParent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a > b)parent[a] = b;
    else parent[b] = a;
}

bool findParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a == b) return true;
    else return false;
}

int main() {
    int V, E;
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        edge e;
        cin >> e.v >> e.u >> e.dis;
        vec.push_back(e);
    }
    sort(vec.begin(), vec.end(), comp);
    for (int i = 1; i <= V; i++) {
        parent[i] = i;
    }
    int sum = 0;
    for (int i = 0; i < vec.size(); i++) {
        if (!findParent(vec[i].v, vec[i].u)) {
            unionParent(vec[i].v, vec[i].u);
            sum += vec[i].dis;
        }
    }
    cout << sum;
}