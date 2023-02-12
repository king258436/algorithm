#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> vec[100001];
queue<int> q;
int visited[100001];
int n;
int result[100001];

void BFS(int start) {
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < vec[x].size(); i++) {
            int y = vec[x][i];
            if (!visited[y]) {
                q.push(y);
                visited[y] = true;
                result[y] = x;
            }
        }
    }
}

int main() {
    cin >> n;
    int l=n;
    l--;
    while (l--) {
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    BFS(1);
    for (int i = 2; i <= n; i++) {
        cout << result[i] << '\n';
    }
}
