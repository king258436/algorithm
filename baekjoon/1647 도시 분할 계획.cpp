#include<iostream>
#include<algorithm>

using namespace std;

struct Node {
    int s;
    int e;
    int dis;
};

int n, m;
Node edge[1000002];
int parent[100001];

bool comp(Node n1, Node n2) {
    return n1.dis < n2.dis;
}

int getParent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a > b) parent[a] = b;
    else parent[b] = a;
}

bool findParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a == b) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> edge[i].s >> edge[i].e >> edge[i].dis;
    }
    sort(edge + 1, edge + m + 1, comp);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    long long sum = 0;
    int big = 1;
    for (int i = 1; i <= m; i++) {
        if (!findParent(edge[i].s, edge[i].e)) {
            unionParent(edge[i].s, edge[i].e);
            sum += edge[i].dis;
            if (edge[i].dis > big) big = edge[i].dis;
        }
    }
    sum -= big;
    cout << sum;
}