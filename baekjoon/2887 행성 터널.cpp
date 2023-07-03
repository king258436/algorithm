#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
vector<pair<int, pair<int, int>>> info;
int parent[100001];
int n;

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
    vector<pair<int, int>> X, Y, Z;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        X.push_back({x, i});
        Y.push_back({y, i});
        Z.push_back({z, i});
        parent[i] = i;
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    sort(Z.begin(), Z.end());

    for (int i = 0; i < n - 1; i++) {
        info.push_back({abs(X[i + 1].first - X[i].first), {X[i].second, X[i + 1].second}});
        info.push_back({abs(Y[i + 1].first - Y[i].first), {Y[i].second, Y[i + 1].second}});
        info.push_back({abs(Z[i + 1].first - Z[i].first), {Z[i].second, Z[i + 1].second}});
    }
    sort(info.begin(), info.end());
    int cost = 0;
    for (int i = 0; i < info.size(); i++) {
        if (!findParent(info[i].second.first, info[i].second.second)) {
            unionParent(info[i].second.first, info[i].second.second);
            cost += info[i].first;
        }
    }
    cout << cost;


}