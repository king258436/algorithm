#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define SIZE 100001

int d[SIZE];
bool visited[SIZE];

void dijkstra(int start, int end) {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    q.push(make_pair(0, start));
    d[start] = 0;
    visited[start] = true;
    while (!q.empty()) {
        int time = q.top().first;
        int cur = q.top().second;
        q.pop();
        if(time>d[cur]) continue;
        if (cur == end) {
            cout << d[end];
            break;
        }
        if (cur * 2 < SIZE && !visited[cur * 2]) {
            q.push(make_pair(time, cur * 2));
            visited[cur * 2] = true;
            d[cur * 2] = time;
        }
        if (cur + 1 < SIZE && !visited[cur + 1]) {
            q.push(make_pair(time + 1, cur + 1));
            visited[cur + 1] = true;
            d[cur + 1] = time + 1;
        }
        if (cur - 1 >= 0 && !visited[cur - 1]) {
            q.push(make_pair(time + 1, cur - 1));
            visited[cur - 1] = true;
            d[cur - 1] = time + 1;
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    dijkstra(n, k);
    return 0;
}