#include<iostream>
#include<algorithm>

using namespace std;
struct Node {
    int s;
    int e;
    int dis;
};
int parent[2000010];
Node edge[2000010];

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

bool comp(Node n1, Node n2) {
    return n1.dis < n2.dis;
}

int main() {
    while (1) {
        int n, m;
        cin >> m >> n;
        if (m == 0 && n == 0) {
            break;
        }
        for (int i = 1; i <= m; i++) {
            parent[i] = i;
        }

        long long sum = 0;
        for (int i = 1; i <= n; i++) {
            cin >> edge[i].s >> edge[i].e;
            if (edge[i].s == 0 && edge[i].e == 0) break;
            cin >> edge[i].dis;
            sum += edge[i].dis;

        }

        sort(edge + 1, edge + n + 1, comp);

        for (int i = 1; i <= n; i++) {
            if (!findParent(edge[i].s, edge[i].e)) {
                unionParent(edge[i].s, edge[i].e);
                sum -= edge[i].dis;
            }
        }
        cout << sum << "\n";
    }
}