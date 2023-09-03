#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int inDegree[501];
int time_arr[501];
int n;
vector<int> vec[501];
int result[501];

void topologySort() {
    queue<int> que;
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            que.push(i);
            result[i] = time_arr[i];
        }
    }
    while (!que.empty()) {
        int cur = que.front();
        que.pop();
        for (auto nxt: vec[cur]) {
            inDegree[nxt]--;
            result[nxt] = max(result[nxt], result[cur] + time_arr[nxt]);
            if (inDegree[nxt] == 0) {
                que.push(nxt);
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> time_arr[i];
        while (1) {
            int barrack;
            cin >> barrack;
            if (barrack == -1) {
                break;
            } else {
                vec[barrack].push_back(i);
                inDegree[i]++;
            }
        }
    }
    topologySort();
    for (int i = 1; i <= n; i++) {
        cout << result[i] << '\n';
    }

}