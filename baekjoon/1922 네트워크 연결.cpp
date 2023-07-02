#include<iostream>
#include<algorithm>

using namespace std;

struct node {
    int s;
    int e;
    int value;
};

int parent[1001];

bool comp(node n1, node n2) {
    return n1.value < n2.value;
}

int getParent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

bool findParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a == b) return true;
    else return false;
}

int main() {
    int v, e;
    node edge[100001];
    cin >> v;
    cin >> e;
    for (int i = 1; i <= v; i++) {
        parent[i] = i;
    }
    for (int i = 1; i <= e; i++) {
        cin >> edge[i].s >> edge[i].e >> edge[i].value;
    }
    int sum = 0;

    sort(edge + 1, edge + e + 1, comp);
    for (int i = 1; i <= e; i++) {
        if (!findParent(edge[i].s, edge[i].e)) {
            unionParent(edge[i].s, edge[i].e);
            sum += edge[i].value;
//            cout << edge[i].s << ' ' << edge[i].e << ' ' << edge[i].value << "\n";
        }
    }
    cout << sum;
}