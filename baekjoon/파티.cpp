#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<pair<int, int> > v[1001];
int n, m, x;
int t[1001];
int value;

void djstra(int st, int en) {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    fill(t, t + n + 1, 200000000);
    pq.push(make_pair(0, st));
    t[st] = 0;

    while (!pq.empty()) {
        int cn = pq.top().second;
        int ct = pq.top().first;
        pq.pop();
        if (cn == en) {
            value = t[en];
            break;
        }
        if (ct > t[cn]) continue;

        for (auto next : v[cn]) {
            int nn = next.first;
            int nt = next.second + ct;

            if (nt < t[nn]) {
                t[nn] = nt;
                pq.push(make_pair(nt, nn));
            }
        }
    }
}

int main() {
    cin >> n >> m >> x;
    int i;
    for (i = 0; i < m; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        v[a].push_back(make_pair(b, t));
    }

    int result;
    int maximum = 0;
    int ans = 0, ans1, ans2;

    for (i = 1; i <= n; i++) {
        djstra(i, x);
        ans1 = value;

        djstra(x, i);
        ans2 = value;
        if (ans < ans1 + ans2) {
            ans = ans1 + ans2;
        }
    }
    cout << ans;
}