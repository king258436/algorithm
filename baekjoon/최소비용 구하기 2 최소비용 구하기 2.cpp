#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

#define MAX 100001
using namespace std;

struct Info {
    int node;
    int cost;
};

struct compare {
    bool operator()(Info &a, Info &b) {
        return a.cost > b.cost;
    }
};

int n, m;
vector<Info> vec[MAX];
int score[MAX];
int start, goal;
int cnt;
int route[MAX];
vector<int> result;

void simul() {
    for (int i = 1; i <= n; i++) {
        cout << score[i] << ' ';
    }
}

void dijkstra(int a) {
    priority_queue<Info, vector<Info>, compare> pq;
    pq.push({a, 0});
    score[a] = 0;
    while (!pq.empty()) {
        Info cur = pq.top();
        pq.pop();
        if (cur.cost != score[cur.node]) {
            continue;
        }
        for (auto next: vec[cur.node]) {
            if (score[next.node] > score[cur.node] + next.cost) {
                score[next.node] = score[cur.node] + next.cost;
                route[next.node] = cur.node;
                pq.push({next.node, score[next.node]});
            }
        }
    }
    result.push_back(goal);
    int temp = route[goal];
    cnt++;
    while (temp) {
        result.push_back(temp);
        cnt++;
        temp = route[temp];
    }
}

int main() {
    cin >> n;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        vec[a].push_back({b, c});
    }
    cin >> start >> goal;
    for (int i = 1; i <= n; i++) {
        score[i] = 1e9;
    }
    dijkstra(start);
    cout << score[goal] << '\n' << cnt << '\n';
    std::reverse(result.begin(), result.end());
    for (auto a: result) {
        cout << a << ' ';
    }
}