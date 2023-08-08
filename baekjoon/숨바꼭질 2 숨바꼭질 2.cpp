#include<iostream>
#include<queue>

#define MAX 100001
using namespace std;
struct Info {
    int node;
    int cnt;
};
int cnt;
bool visited[MAX];
int ed_time;

void simul() {

}

void bfs(int st, int ed) {
    queue<Info> q;
    q.push({st, 0});
    while (!q.empty()) {
        int cur = q.front().node;
        int time = q.front().cnt;
        q.pop();
        visited[cur] = true;
        if (ed == cur && ed_time == time && cnt) {
            cnt++;
        }
        if (ed == cur && cnt == 0) {
            cnt++;
            ed_time = time;
        }
        if (cur + 1 >= 0 && cur + 1 < MAX && !visited[cur + 1]) {
            q.push({cur + 1, time + 1});
        }
        if (cur - 1 >= 0 && cur - 1 < MAX && !visited[cur - 1]) {
            q.push({cur - 1, time + 1});
        }
        if (cur * 2 >= 0 && cur * 2 < MAX && !visited[cur * 2]) {
            q.push({cur * 2, time + 1});
        }
    }
}

int main() {
    int a, b;
    cin >> a >> b;
    bfs(a, b);
    cout << ed_time << '\n' << cnt;
}