#include<iostream>
#include<vector>
#include<queue>

using namespace std;
vector<int> vec[51];
vector<int> tree;
bool visited[51];
int n;

void print_test() {
    for (int i = 0; i < n; i++) {
        for (auto a: vec[i]) {
            cout << '\n' << i << ' ' << a;
        }
    }
}

int bfs(int head) {
    queue<int> que;
    int cnt = 0;
    visited[head] = true;
    que.push(head);
    while (!que.empty()) {
        auto cur = que.front();
        que.pop();
        if (!vec[cur].size()) {
            cnt++;
        }
        for (auto nxt: vec[cur]) {
            if (visited[nxt]) {
                continue;
            }
            que.push(nxt);
            visited[nxt] = true;
        }
    }
    return cnt;
}

int main() {

    int result = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int parent;
        cin >> parent;
        if (parent == -1) {
            tree.push_back(i);
        }
        vec[parent].push_back(i);
    }
    int cut;
    cin >> cut;
    for (int i = 0; i < tree.size(); i++) {
        if (tree[i] == cut) {
            tree.erase(tree.begin() + i);// 헤드노드일때 삭제
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < vec[i].size(); j++) {// 헤드노드가 아닐때 삭제
            if (vec[i][j] == cut) {
                vec[i].erase(vec[i].begin() + j);
            }
        }
    }
//    print_test();
    for (int i = 0; i < tree.size(); i++) {
        int cur = tree[i];
        visited[cur] = true;
        result += bfs(cur);
    }
    cout << result;

}