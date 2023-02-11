#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 1000000000;
int n, m;
vector<pair<int, int> > arr[20001];
int d[20001];
int start, end_;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

int main() {
    int i, j;
    cin >> n >> m >> start;

    for (i = 1; i <= n; i++) {
        d[i] = INF;  // 시작점에서 모든 정점까지 가는 비용은 inf로 초기화 시켜준다.
    }

    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        arr[u].push_back(make_pair(w,v));
    }

    d[start] = 0;

    pq.push(make_pair(d[start], start));  // 비용, 정점 순으로 heap 에 push 할거임.

    while (!pq.empty()) {
        pair<int, int> cur;
        cur = pq.top();  // 큐에서 방금 뽑아올린 신선한 비용, 정점.
        pq.pop();
        for (i = 0; i < arr[cur.second].size(); i++) {
            pair<int, int> next;
            next.first = arr[cur.second][i].first;  // cur 과 연결된 다음 노드의 경로값
            next.second = arr[cur.second][i].second;                  // cur 과 연결된 다음 노드의 정점 Idx
            if (d[next.second] > cur.first + next.first) {
                d[next.second] = cur.first + next.first;
                pq.push(make_pair(d[next.second], next.second));
            }
        }
    }
    for (i = 1; i <= n; i++) {
        if (d[i] == INF)
            cout << "INF\n";
        else
            cout << d[i] << '\n';
    }
}