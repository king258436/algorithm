#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;
int n;
vector<pair<int, int>> store;
bool visited[101];
pair<int, int> goal, start;

bool bfs() {
    queue<pair<int, int>> que;
    que.push({start.first, start.second});
    while (!que.empty()) {
        int x, y;
        y = que.front().first;
        x = que.front().second;
        que.pop();
        if ((abs(goal.first - y) + abs(goal.second - x)) <= 1000) return true;
        for (int i = 0; i < n; i++) {
            if ((abs(store[i].first - y) + abs(store[i].second - x)) <= 1000 && !visited[i]) {
                visited[i] = true;
                que.push({store[i].first, store[i].second});
            }
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i < 101; i++)visited[i] = 0;
        while (!store.empty()) store.pop_back();
        cin >> n;
        cin >> start.first >> start.second;
        for (int i = 0; i < n; i++) {
            int y, x;
            cin >> y >> x;
            store.push_back({y, x});
        }
        cin >> goal.first >> goal.second;
        if (bfs() == true) cout << "happy\n";
        else cout << "sad\n";
    }
}