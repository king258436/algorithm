#include<iostream>
#include<vector>

#define MAX 100001
using namespace std;

struct Info {
    int goal;
    int dist;
};
int result;
int restart;
vector<Info> vec[MAX];
int visited[MAX];

void dfs(int cnt, int cur) {
    if (result < cnt) {
        result = cnt;
        restart = cur;
    }

    for (auto next: vec[cur]) {
        if (visited[next.goal]) {
            continue;
        }
        visited[next.goal] = true;
        dfs(cnt + next.dist, next.goal);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int st;
        cin >> st;
        int to = 0, dist = 0;
        while (1) {
            cin >> to;
            if (to == -1) {
                break;
            }
            cin >> dist;
            vec[st].push_back({to, dist});
            vec[to].push_back({st, dist});
        }
    }
    visited[1] = true;
    dfs(0, 1);
    for (int i = 0; i < MAX; i++) {
        visited[i] = false;
    }
    visited[restart] = true;
    dfs(0, restart);
    cout << result;
}