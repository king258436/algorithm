#include<iostream>
#include<queue>

using namespace std;

int F, S, G, U, D;
int visited[1000002];

bool bfs() {
    queue<int> que;
    que.push(S);
    visited[S] = 1;
    while (!que.empty()) {
        if (visited[G]) {
            return true;
        }
        int cur = que.front();
        que.pop();
        int uCur = cur + U;
        int dCur = cur - D;
        if (uCur <= F && uCur > 0) {
            if (!visited[uCur]) {
                que.push(uCur);
                visited[uCur] = visited[cur] + 1;
            }
        }
        if (dCur > 0 && dCur <= F) {
            if (!visited[dCur]) {
                que.push(dCur);
                visited[dCur] = visited[cur] + 1;
            }
        }
    }
    return false;
}

int main() {
    cin >> F >> S >> G >> U >> D;
    if (bfs()) {
        cout << visited[G] - 1;
    } else {
        cout << "use the stairs";
    }
}