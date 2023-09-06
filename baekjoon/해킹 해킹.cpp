#include<iostream>
#include<queue>
#include<set>
#include<vector>

#define MAX 10001
#define INF 1e9
using namespace std;
int dist[MAX];

struct Info {
    int com;
    int time;
};

struct Answer {
    int infected_computer_cnt;
    int last_time;
};

struct cmp {
    bool operator()(Info a, Info b) {
        return a.time > b.time;
    }
};

void dist_init() {// dist 배열 무한대 로 초기화.
    for (int i = 0; i <= MAX; i++) {
        dist[i] = INF;
    }
}

Answer dijkstra(int start_computer, vector<Info> vec[MAX]) {
    Answer ret;// 마지막 컴퓨터 방문할 때 까지 걸린 시간.
//    set<int> st;
//    st.insert(start_computer);
    priority_queue<Info, vector<Info>, cmp> pq;
    dist[start_computer] = 0;
    pq.push({start_computer, 0});
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if (dist[cur.com] != cur.time) {
            continue;
        }
        for (auto nxt: vec[cur.com]) {
            if (dist[nxt.com] > dist[cur.com] + nxt.time) {
                dist[nxt.com] = dist[cur.com] + nxt.time;
                pq.push({nxt.com, dist[nxt.com]});
//                st.insert(nxt.com);
//                cout << nxt.com << ' ';
            }
        }
    }
    ret = {0, 0};
    for (int i = 0; i < MAX; i++) {
        int cur = dist[i];
        if (cur < INF) {
            ret.infected_computer_cnt++;
            ret.last_time = max(ret.last_time, cur);
        }
    }
//    ret.infected_computer_cnt = st.size();
    return ret;
}

int main() {

    int test_case;
    cin >> test_case;
    while (test_case--) {
        int n, d, c;
        cin >> n >> d >> c;
        vector<Info> vec[MAX];
        for (int i = 0; i < d; i++) {
            int a, b, s;
            cin >> a >> b >> s;
            vec[b].push_back({a, s});
        }
        fill_n(dist, MAX, INF);
        Answer answer = dijkstra(c, vec);
        cout << answer.infected_computer_cnt << ' ' << answer.last_time << '\n';
    }
}