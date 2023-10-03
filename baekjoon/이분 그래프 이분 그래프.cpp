#include<iostream>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;

int check[200001];

void bfs(vector<int> vec[], int first) {
    queue<int> que;
    que.push(first);
    check[first] = 1;
    while (!que.empty()) {
        int cur = que.front();
        que.pop();
        for (auto nxt: vec[cur]) {
            if (check[nxt] != 0) {// 연결된 다음 노드의 색이 정해져있다면
                continue;
            }
            if (check[cur] == 1) {// 현재 노드의 색깔 의 반대로 다음노드를 칠하기.
                check[nxt] = -1;
                que.push(nxt);
            } else {
                check[nxt] = 1;
                que.push(nxt);
            }
        }
    }
}

void print_test(int v) {
    for (int i = 1; i <= v; i++) {
        cout << check[i] << ' ';
    }
}

int main() {
    int k;
    int v;
    int e;
    cin >> k;
    while (k--) {
        memset(check, 0, sizeof(check));
        vector<int> vec[20001];
        cin >> v >> e;
        for (int i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            vec[a].push_back(b);
            vec[b].push_back(a);
        }
        for (int i = 1; i <= v; i++) {
            if (check[i] == 0)bfs(vec, i);
        }
        bool flag = true;
        for (int cur = 1; cur <= v; cur++) {
            for (int nxt: vec[cur]) {
                if (check[cur] == check[nxt]) {
                    flag = false;
                }
            }
            if (!flag) {
                break;
            }
        }
        if (!flag) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
//        print_test(v);
    }
}