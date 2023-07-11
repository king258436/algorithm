#include<iostream>
#include<vector>

#define INF 1e9
using namespace std;

int main() {
    int tc;
    cin >> tc;
    while (tc--) {// 테케 반복

        int n, m, w;
        int s, e, t;
        vector<pair<pair<int, int>, int>> edge;
        long long dis[501];
        bool flag = false;

        for (int i = 1; i <= n; i++) {//dis 초기화
            dis[i] = INF;
        }
        dis[1] = 0;//어디서부터 출발해도 상관없으니 스타트지점은 1로 설정.
        cin >> n >> m >> w;

        for (int i = 0; i < m; i++) {// 도로는 양방향이므로 양쪽다연결
            cin >> s >> e >> t;
            edge.push_back({{s, e}, t});
            edge.push_back({{e, s}, t});
        }

        for (int i = 0; i < w; i++) {//웜홀은 한방향.
            cin >> s >> e >> t;
            edge.push_back({{s, e}, t * (-1)});
        }

        for (int i = 1; i <= n - 1; i++) {
            for (int j = 0; j < edge.size(); j++) {
                int from = edge[j].first.first;
                int to = edge[j].first.second;
                long long cost = edge[j].second;
                if (dis[to] > dis[from] + cost) {
                    dis[to] = dis[from] + cost;
                }
            }
        }
        for (int i = 0; i < edge.size(); i++) {
            int from = edge[i].first.first;
            int to = edge[i].first.second;
            long long cost = edge[i].second;
            if (dis[to] > dis[from] + cost) {
                flag = true;
            }
        }
        if (flag) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}